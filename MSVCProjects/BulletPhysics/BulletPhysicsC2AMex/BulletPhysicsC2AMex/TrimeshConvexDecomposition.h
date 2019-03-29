#ifndef TRIMESH_CONVEX_DECOMPOSITION_H
#define TRIMESH_CONVEX_DECOMPOSITION_H


//#include "NvConvexBuilder.h"
#include "NvConvexDecomposition.h"
#include "mexFunction.h"
#include "btBulletDynamicsCommon.h"
#include "LinearMath/btAlignedObjectArray.h"
#include "mexFunction.h"


// creating customized convex decomposition interface

class TrimeshConvexDecomposition 
{	
public:
	// storage
	btAlignedObjectArray< btConvexHullShape* > ConvexShapes;  // will store all convex shapes
	btAlignedObjectArray<btVector3> Centroids;


	// indexing
	int NumConvexShapes;
	int StartIndex;				// might be used for accessing the vertices 

	// comvex decomposition processing data and parameters

	// description data for triangular mesh
	unsigned int VCount;
	NxF32 *Vertices;		// pointer to the start of vertex array
	unsigned int TCount;		// number of triangles
	int *Indices;		// indexed triangle list array

	// options 
	unsigned int DecompositionDepth;			// depth to split, a maximum of 10, generally not over 7.
	float ConcavityThresholdPercentage;	// the concavity threshold percentage.  0=20 is reasonable.
	float MergeThresholdPercentage;
	float VolumeSplitThresholdPercentage;	// the percentage volume conservation threshold to collapse hulls. 0-30 is reasonable.

	// hull output limits
	unsigned int MaxHullVertices;	// maximum number of vertices in the output hull. Recommended 32 or less.
	float SkinWidth;	// a skin width to apply to the output hulls.

	bool UseInitialIslandGeneration;
	bool UseIslandGeneration;
	bool UseBackgroundThread;

	// constructors
	TrimeshConvexDecomposition();
	TrimeshConvexDecomposition(int numFaces,int* faces,int numVertices,btScalar* vertices);

	// 
	~TrimeshConvexDecomposition();

	// helper methods
	void setTriangularMeshData(int numFaces,int* faces,int numVertices,btScalar* vertices);

	// virtual void ConvexDecompResult(ConvexDecomposition::ConvexResult &result);  // overriding abstract method

	// Convex Decomposition Processing methods

	btCompoundShape* computeConvexDecomposition();

	// Release Data

	void releaseData();

};

#endif