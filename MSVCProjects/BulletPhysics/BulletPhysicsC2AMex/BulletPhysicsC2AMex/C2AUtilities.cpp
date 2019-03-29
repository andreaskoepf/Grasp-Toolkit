#include "C2AUtilities.h"

C2A_Model* C2AUtilities::create_C2A_Model(const Solid *solid,const btTransform &localTransform)
{

	// creating transform that will be used to shift all vertices to a user define reference frame
	btTransform toNewFrameTransform = btTransform(localTransform);
	
	// creating new model
	// this model is used for collision queries only
	C2A_Model *model = new C2A_Model();

	model->BeginModel(solid->NumFaces);

	// adding triangles to construct model
	model->Vertex = new Coord3D[solid->NumVertices];

	// declaring vectors that contains original and transformed vertices
	btVector3 origVertex, newVertex[100000];
	//newVertex = new btVector3[solid->NumVertices];

	for(int i = 0; i < solid->NumVertices ; i++)
	{
		origVertex.setValue(solid->Vertices[3*i],solid->Vertices[3*i+1],solid->Vertices[3*i+2]);
		newVertex[i] = toNewFrameTransform(origVertex);
		//model->Vertex[i].Set_Value(solid->Vertices[3*i],solid->Vertices[3*i+1],solid->Vertices[3*i+2]);
		model->Vertex[i].Set_Value(newVertex[i].getX(),newVertex[i].getY(),newVertex[i].getZ());
	}

#ifdef IN_DEBUG_MODE_LEVEL_2
	/*
	mexPrintf("\nVertices\n");
	for(int i=0;i<solid->NumVertices;i++)
	{
		origVertex.setValue(solid->Vertices[3*i],solid->Vertices[3*i+1],solid->Vertices[3*i+2]);
		transformVertex = toNewFrameTransform(origVertex);
		mexPrintf("\t%1.3f\t%1.3f\t%1.3f\n",transformVertex.getX(),transformVertex.getY(),transformVertex.getZ());
	}
	*/

	mexPrintf("\nModel was shifted by the following transform:\n");
	MexUtilities::print_btTransform(localTransform);
	mexPrintf("\n");
#endif

	// declaring indexes
	int i1, i2, i3;

	// declaring vertex holders
	PQP_REAL p1[3], p2[3], p3[3];


	for(int i = 0;i<solid->NumFaces;i++)
	{
		i1 = solid->Faces[3*i];
		i2 = solid->Faces[3*i+1];
		i3 = solid->Faces[3*i+2];

#ifdef IN_DEBUG_MODE_LEVEL_2
		mexPrintf("\t%i\t%i\t%i\n",i1,i2,i3);
#endif


		//p1[0] = newVertex[i].x
		/*
		model->AddTri(solid->Vertices+i1*3,solid->Vertices + i2*3,solid->Vertices + i3*3,
			i,i1,i2,i3);
		*/

		model->AddTri(newVertex[i1].m_floats,newVertex[i2].m_floats,newVertex[i3].m_floats,i,
			i1, i2, i3);
	}

	model->EndModel();

	// deleting vertexes array
	//delete[] newVertex;

	return model;
}

C2A_Model* C2AUtilities::create_C2A_Model(const Solid *solid)
{
	btTransform localTransform;
	localTransform.setIdentity();

	create_C2A_Model(solid,localTransform);
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

	/*
	PQP_REAL velocity[3];
	btVector3 velVector;
	velVector = endTransform.getOrigin() - startTransform.getOrigin();
	velocity[1]=velVector.getX();
	velocity[2]=velVector.getY();
	velocity[3]=velVector.getZ();
	*/

	
	// construction motion object
	CInterpMotion_Slerp *motion = new CInterpMotion_Slerp(rotStart,posStart,rotEnd,posEnd);
	//CInterpMotion *motion = new CInterpMotion_Slerp(rotStart,posStart,rotEnd,posEnd);

	motion->m_toc_delta = dTolerance;
	//motion->m_time = timeTolerance;

	return motion;

}

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






