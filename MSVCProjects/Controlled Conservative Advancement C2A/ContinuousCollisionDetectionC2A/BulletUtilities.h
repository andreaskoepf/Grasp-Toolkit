#ifndef BULLET_UTILITIES_H
#define BULLET_UTILITIES_H

#include "MexUtilities.h"
#include "LinearMath/btQuaternion.h"
#include "LinearMath/btTransform.h"

// bullet collision header files
#include "btBulletCollisionCommon.h"

class BulletUtilities
{

public:

	// extract data from objects or structure properties passed as arguments
		static btVector3 mxArray_to_btVector3(const mxArray* input);
		static btTransform mxArray_to_btTransform(const mxArray* input);


	// Methods to extract data from bullet data types and populate mxArray types
		static mxArray* btTransform_to_mxArray(const btTransform &transform);
		static mxArray* btVector3_to_mxArray(const btVector3 &vec);
		static mxArray* btVector3_to_mxArray(const btVector3 &vec,bool isRowVector);

	// Methods to create bullet related entities
		static btTriangleIndexVertexArray* createTriangleIndexVertexArray(double *verticesArray,int *facesArray,int numVertices,int numFaces);

};

#endif