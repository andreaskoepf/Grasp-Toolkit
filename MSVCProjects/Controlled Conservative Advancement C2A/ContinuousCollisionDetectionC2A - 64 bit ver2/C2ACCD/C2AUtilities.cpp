#include "C2AUtilities.h"

C2A_Model* C2AUtilities::create_C2A_Model(const mxArray *meshData,const btTransform &localTransform)
{

	// creating transform that will be used to shift all vertices to a user define reference frame
	btTransform toNewFrameTransform = btTransform(localTransform);


	// obtaining mesh data
#ifdef IN_DEBUG_MODE
	mexPrintf("\nC2AUtilities::create_C2A_Model extracting vertex data\n");
#endif
	double *vertices = NULL;
	vertices = MexUtilities::mxArray_to_double_array(meshData,0,"vertices",APPEND_ROW_WISE);

#ifdef IN_DEBUG_MODE
	mexPrintf("\nC2AUtilities::create_C2A_Model extracting faces data\n");
#endif
	int *faces = MexUtilities::mxArray_to_int_array(meshData,0,"faces",APPEND_ROW_WISE);

#ifdef IN_DEBUG_MODE
	mexPrintf("\nC2AUtilities::create_C2A_Model extracting size\n");
#endif
	// obtaining mesh size
	int numFaces = MexUtilities::mxArray_row_size(meshData,0,"faces");
	int numVertices = MexUtilities::mxArray_row_size(meshData,0,"vertices");

#ifdef IN_DEBUG_MODE
	mexPrintf("\nC2AUtilities::create_C2A_Model %i vertices and &i faces\n",numVertices,numFaces);
#endif

	// creating new model
	// this model is used for collision queries only
	C2A_Model *model = new C2A_Model();	

	model->BeginModel(numFaces);

	// adding triangles to construct model
	model->Vertex = new Coord3D[numVertices];

	// declaring vectors that contains original and transformed vertices
	btVector3 origVertex, newVertex;
	//newVertex = new btVector3[solid->NumVertices];
#ifdef IN_DEBUG_MODE
	mexPrintf("\nC2AUtilities::create_C2A_Model transforming vertex data\n");
#endif

	for(int i = 0; i < numVertices ; i++)
	{
		origVertex.setValue(vertices[3*i],vertices[3*i+1],vertices[3*i+2]);
		newVertex = toNewFrameTransform(origVertex);
		vertices[3*i] = newVertex.getX();
		vertices[3*i+1] = newVertex.getY();
		vertices[3*i+2] = newVertex.getZ();

		model->Vertex[i].Set_Value(vertices[3*i] ,vertices[3*i+1],vertices[3*i+2]);
	}


	// declaring indexes
	int i1, i2, i3;

	// declaring vertex holders
	PQP_REAL p1[3], p2[3], p3[3];

#ifdef IN_DEBUG_MODE
	mexPrintf("\nC2AUtilities::create_C2A_Model copying vertex data to C2A_Model\n");
#endif
	for(int i = 0;i<numFaces;i++)
	{
		i1 = faces[3*i]-1;	// c arrays are zero based
		i2 = faces[3*i+1]-1;
		i3 = faces[3*i+2]-1;

		model->AddTri(vertices + 3*i1,vertices+3*i2,vertices + 3*i3,i,
			i1, i2, i3);
	}

	model->EndModel();

	// deleting vertices and faces arrays
#ifdef IN_DEBUG_MODE
	mexPrintf("\nC2AUtilities::create_C2A_Model deleting faces and vertices data data\n");
#endif
	delete[] vertices;
	delete[] faces;

	return model;
}

C2A_Model* C2AUtilities::create_C2A_Model(const mxArray *meshData)
{
	btTransform localTransform;
	localTransform.setIdentity();

	create_C2A_Model(meshData,localTransform);
}



CInterpMotion_Linear* C2AUtilities::create_C2A_CInterpMotion_Linear(const btTransform &startTransform,const btTransform &endTransform,
															 btScalar timeTolerance,btScalar dTolerance)
{

	// creating 3 x 3 arrays for rotation matrices
	PQP_REAL rotStart[3][3], rotEnd[3][3], posStart[3], posEnd[3];

	//mexPrintf("\nCreating CInterpMotion_Linear Object:\n");
	//mexPrintf("End transform is as follows:\n");

	for(int i = 0 ; i<3 ; i++)
	{
		for(int j = 0; j<3 ; j++)
		{
			rotStart[i][j] = startTransform.getBasis().getRow(i).m_floats[j];
			rotEnd[i][j] = endTransform.getBasis().getRow(i).m_floats[j];
			//rotStart[i][j] = startTransform.getBasis().getColumn(i).m_floats[j];
			//rotEnd[i][j] = endTransform.getBasis().getColumn(i).m_floats[j];
		}

		posStart[i] = startTransform.getOrigin().m_floats[i];
		posEnd[i] = endTransform.getOrigin().m_floats[i];

		//mexPrintf("%1.2f\t%1.2f\t%1.2f\t%1.2f\n",rotEnd[i][0],rotEnd[i][1],rotEnd[i][2],posEnd[i]);


	}

	// creating relative velocity 
	// Note:  this procedure may need to be change if it is determined that C2A can only perform collision test
	//			for a pair in which one is static and the other is moving.

	/*
	PQP_REAL velocity[3];
	btVector3 velVector;
	velVector = endTransform.getOrigin() - startTransform.getOrigin();
	velocity[1]=velVector.getX();
	velocity[2]=velVector.getY();
	velocity[3]=velVector.getZ();
	*/

	
	// construction motion object
	CInterpMotion_Linear *motion = new CInterpMotion_Linear(rotStart,posStart,rotEnd,posEnd);
	//CInterpMotion *motion = new CInterpMotion_Slerp(rotStart,posStart,rotEnd,posEnd);

	motion->m_toc_delta = dTolerance;
	//motion->m_time = timeTolerance;

	return motion;

}

/*
CInterpMotion_Slerp* C2AUtilities::create_C2A_CInterpMotion_Slerp(const btTransform &startTransform,const btTransform &endTransform,
															 btScalar timeTolerance,btScalar dTolerance)
{

	// creating 3 x 3 arrays for rotation matrices
	PQP_REAL rotStart[3][3], rotEnd[3][3], posStart[3], posEnd[3];

	//mexPrintf("\nCreating CInterpMotion_Linear Object:\n");
	//mexPrintf("End transform is as follows:\n");

	for(int i = 0 ; i<3 ; i++)
	{
		for(int j = 0; j<3 ; j++)
		{
			rotStart[i][j] = startTransform.getBasis().getRow(i).m_floats[j];
			rotEnd[i][j] = endTransform.getBasis().getRow(i).m_floats[j];
			//rotStart[i][j] = startTransform.getBasis().getColumn(i).m_floats[j];
			//rotEnd[i][j] = endTransform.getBasis().getColumn(i).m_floats[j];
		}

		posStart[i] = startTransform.getOrigin().m_floats[i];
		posEnd[i] = endTransform.getOrigin().m_floats[i];

		//mexPrintf("%1.2f\t%1.2f\t%1.2f\t%1.2f\n",rotEnd[i][0],rotEnd[i][1],rotEnd[i][2],posEnd[i]);


	}

	// creating relative velocity 
	// Note:  this procedure may need to be change if it is determined that C2A can only perform collision test
	//			for a pair in which one is static and the other is moving.


	
	// construction motion object
	CInterpMotion_Slerp *motion = new CInterpMotion_Slerp(rotStart,posStart,rotEnd,posEnd);
	//CInterpMotion *motion = new CInterpMotion_Slerp(rotStart,posStart,rotEnd,posEnd);

	motion->m_toc_delta = dTolerance;
	//motion->m_time = timeTolerance;

	return motion;

}
*/

void C2AUtilities::btTransform_to_PQP(const btTransform &transform, PQP_REAL R[][3], PQP_REAL T[])
{

	for(int i = 0 ; i<3 ; i++)
	{
		for(int j = 0; j<3 ; j++)
		{
			R[i][j] = transform.getBasis().getRow(i).m_floats[j];
		}

		T[i] = transform.getOrigin().m_floats[i];

#ifdef IN_DEBUG_MODE_LEVEL_2

		mexPrintf("%1.2f\t%1.2f\t%1.2f\t%1.2f\n",R[i][0],R[i][1],R[i][2],T[i]);

#endif


	}

}

void C2AUtilities::btTransform_to_Transform(const btTransform &transform, Transform &C2ATransform)
{

	for(int i = 0 ; i<3 ; i++)
	{
		for(int j = 0; j<3 ; j++)
		{
			C2ATransform.Rotation()[i][j] = transform.getBasis().getRow(i).m_floats[j];
		}

		C2ATransform.Translation()[i] = transform.getOrigin().m_floats[i];

		//mexPrintf("%1.2f\t%1.2f\t%1.2f\t%1.2f\n",rotEnd[i][0],rotEnd[i][1],rotEnd[i][2],posEnd[i]);


	}

}






