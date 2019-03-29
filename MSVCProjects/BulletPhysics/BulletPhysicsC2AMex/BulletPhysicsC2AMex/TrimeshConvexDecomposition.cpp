
#include "TrimeshConvexDecomposition.h"
#include "LinearMath/btGeometryUtil.h"
#pragma warning(disable:4996)



TrimeshConvexDecomposition::TrimeshConvexDecomposition()
{
	
	
	Indices=0;
	TCount=0;
	Vertices=0;
	VCount=0;

	NumConvexShapes=0;

	
	MaxHullVertices=100;	// maximum number of vertices in the output hull. Recommended 32 or less.
	SkinWidth=0.001;	// a skin width to apply to the output hulls.

	DecompositionDepth=8;			// depth to split, a maximum of 10, generally not over 7.
	ConcavityThresholdPercentage= 1.f;	// the concavity threshold percentage.  0=20 is reasonable.
	MergeThresholdPercentage=20;
	VolumeSplitThresholdPercentage=2;	// the percentage volume conservation threshold to collapse hulls. 0-30 is reasonable.

	UseInitialIslandGeneration = true;
	UseIslandGeneration = false;
	UseBackgroundThread = true;

	
}
	

TrimeshConvexDecomposition::TrimeshConvexDecomposition(int numFaces, int *faces, int numVertices, btScalar *vertices)
{
	
	


	Indices=0;
	TCount=0;
	Vertices=0;
	VCount=0;

	NumConvexShapes=0;

	
	MaxHullVertices=100;	// maximum number of vertices in the output hull. Recommended 32 or less.
	SkinWidth=0.001;	// a skin width to apply to the output hulls.

	DecompositionDepth=8;			// depth to split, a maximum of 10, generally not over 7.
	ConcavityThresholdPercentage= 1.f;	// the concavity threshold percentage.  0=20 is reasonable.
	MergeThresholdPercentage=20;
	VolumeSplitThresholdPercentage=2;	// the percentage volume conservation threshold to collapse hulls. 0-30 is reasonable.

	UseInitialIslandGeneration = true;
	UseIslandGeneration = false;
	UseBackgroundThread = true;
	
	
	setTriangularMeshData(numFaces,faces,numVertices,vertices);
}

TrimeshConvexDecomposition::~TrimeshConvexDecomposition()
{
	releaseData();
}


void TrimeshConvexDecomposition::setTriangularMeshData(int numFaces, int *faces, int numVertices, btScalar *vertices)
{
	/*	
	// creating unsigned int array of indices
	Indices = new unsigned int[3*numFaces];
	TCount = (unsigned int)numFaces;

	// storing data inside of Indices array
	for(int i=0;i<numFaces;i++)
	{
		Indices[i*3]=(unsigned int)faces[i*3];
		Indices[i*3+1]=(unsigned int)faces[i*3+1];
		Indices[i*3+2]=(unsigned int)faces[i*3+2];
	}
	*/



	TCount=(unsigned int)numFaces;
	Indices=faces;

	// creating float array of vertices
	Vertices = new NxF32[3*numVertices];
	VCount = (unsigned int)numVertices;

	// storing data inside of Vertices array
	for(int i=0;i<numVertices;i++)
	{
		Vertices[i*3]=(NxF32)vertices[i*3];
		Vertices[i*3+1]=(NxF32)vertices[i*3+1];
		Vertices[i*3+2]=(NxF32)vertices[i*3+2];
	}
	

	
	//VCount=(unsigned int)numVertices;
	//Vertices=vertices;
}

void TrimeshConvexDecomposition::releaseData()
{
	
	if(Vertices!=NULL)
		delete[] Vertices;

	/*
	if(Indices!=NULL)
		delete Indices;	
	*/

	TCount=0;
	VCount=0;

}



btCompoundShape* TrimeshConvexDecomposition::computeConvexDecomposition()
{
	
	// instantiating convex decomposition object
	CONVEX_DECOMPOSITION::iConvexDecomposition *convexDecomposition = CONVEX_DECOMPOSITION::createConvexDecomposition();

	// adding triangles to convex decomposition object
#ifdef IN_DEBUG_MODE_LEVEL_1
	mexPrintf("\nPreparing convex decomposition");
	mexPrintf("\naAdding triangle data to convex decomposition object");
	mexPrintf("\nTotal number of triangles to be added: %i",TCount);
#endif
	for(unsigned int i=0;i<TCount;i++)
	{
		NxU32 index1=(NxU32)Indices[i*3+0];
		NxU32 index2=(NxU32)Indices[i*3+1];
		NxU32 index3=(NxU32)Indices[i*3+2];

		const NxF32 *p1 = &Vertices[index1*3];
		const NxF32 *p2 = &Vertices[index2*3];
		const NxF32 *p3 = &Vertices[index3*3];

#ifdef IN_DEBUG_MODE_LEVEL_2
		mexPrintf("[%1.4f\t\t%1.4f\t\t%1.4f]\n",*p1,*(p1+1),*(p1+2));
		mexPrintf("[%1.4f\t\t%1.4f\t\t%1.4f]\n",*p2,*(p2+1),*(p2+2));
		mexPrintf("[%1.4f\t\t%1.4f\t\t%1.4f]\n",*p3,*(p3+1),*(p3+2));

#endif


		convexDecomposition->addTriangle(p1,p2,p3);
	}

	// computing convex decomposition

#ifdef IN_DEBUG_MODE_LEVEL_1
	mexPrintf("\nStarting Convex Decomposition\n");
#endif


	convexDecomposition->computeConvexDecomposition((NxF32)SkinWidth,(NxU32)DecompositionDepth,(NxU32)MaxHullVertices,(NxF32)ConcavityThresholdPercentage,
														(NxF32)MergeThresholdPercentage,(NxF32)VolumeSplitThresholdPercentage,UseInitialIslandGeneration,
														UseIslandGeneration,
														UseBackgroundThread);	


	
	while(!convexDecomposition->isComputeComplete())
	{

#ifdef IN_DEBUG_MODE_LEVEL_1

		mexPrintf("\nComputing Convex Decomposition ...");
		
#endif
		Sleep(1000);

	}
#ifdef IN_DEBUG_MODE_LEVEL_1
		mexPrintf("\n\nCompleted Convex Decomposition");
		mexPrintf("\nA total of %i hulls were produced\n",convexDecomposition->getHullCount());
#endif


	
		// Processing results 	
		for(NxU32 i=0;i<convexDecomposition->getHullCount();i++)
		{

			// creating vector container to store vertices
			btAlignedObjectArray< btVector3 > vertices;

			// creating btVector3 object to store centroid location
			btVector3 centroid(0,0,0);			
			
			CONVEX_DECOMPOSITION::ConvexHullResult result;
			convexDecomposition->getConvexHullResult(i,result);

			// computing the centroid
			for(unsigned int i=0;i<result.mVcount;i++)
			{
				btVector3 vertex(result.mVertices[i*3],result.mVertices[i*3+1],result.mVertices[i*3+2]);
				centroid +=vertex;
			}

			centroid *= btScalar(1.f)/(btScalar(result.mVcount));
			//centroid -= COG;

			// shifting all vertices in accordance to the centroid location and storing the vertices in the vertices container

			for(unsigned int i=0;i<result.mVcount;i++)
			{
				btVector3 vertex(result.mVertices[i*3],result.mVertices[i*3+1],result.mVertices[i*3+2]);
				vertex -=centroid;
				vertices.push_back(vertex);
			}



#ifdef SHRINK_OBJECT_INWARDS
	
			float collisionMargin = 0.01f;			
			btAlignedObjectArray<btVector3> planeEquations;
			btGeometryUtil::getPlaneEquationsFromVertices(vertices,planeEquations);

			btAlignedObjectArray<btVector3> shiftedPlaneEquations;
			for (int p=0;p<planeEquations.size();p++)
			{
				btVector3 plane = planeEquations[p];
				plane[3] += 5*collisionMargin;
				shiftedPlaneEquations.push_back(plane);
			}
			btAlignedObjectArray<btVector3> shiftedVertices;
			btGeometryUtil::getVerticesFromPlaneEquations(shiftedPlaneEquations,shiftedVertices);

			
			btConvexHullShape* convexShape = new btConvexHullShape(&(shiftedVertices[0].getX()),shiftedVertices.size());

			
#else //SHRINK_OBJECT_INWARDS

						
			btConvexHullShape* convexShape = new btConvexHullShape(&(vertices[0].getX()),vertices.size());

#endif 

			convexShape->setMargin(0.01);
			ConvexShapes.push_back(convexShape);
			Centroids.push_back(centroid);

			NumConvexShapes++;

		}

		// releasing convex decomposition
		CONVEX_DECOMPOSITION::releaseConvexDecomposition(convexDecomposition);

		btCompoundShape* compound = new btCompoundShape(false);

		btTransform trans;
		trans.setIdentity();

		// creating compound shape with original triangulation center
		for(int i=0;i<NumConvexShapes;i++)
		{
			btVector3 centroid = Centroids[i];
			//trans.setOrigin(centroid-COG);
			trans.setOrigin(centroid);
			btConvexHullShape* convexShape = ConvexShapes[i];
			compound->addChildShape(trans,convexShape);
		}
		

		return compound;

}


















