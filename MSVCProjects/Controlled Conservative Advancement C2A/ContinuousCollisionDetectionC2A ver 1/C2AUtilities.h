#ifndef C2AUTILITIES_H
#define C2AUTILITIES_H

// the following macro changes the interpolation method used by C2A
//#define USE_QUATERNION_DIFF
#include "BulletUtilities.h"
//#include "PQP.h"
#include "C2A.h"
#include "InterpMotion.h"
//#include "CustomInterpMotion.h"



class C2AUtilities
{

public:

	// create a PQP_Model from a Solid Object in order to perform a CCD Query
	static C2A_Model* create_C2A_Model(const mxArray *meshData, const btTransform &localTransform) ;
	static C2A_Model* create_C2A_Model(const mxArray *meshData);

	// creates an interpolated motion object for given initial and final configurations
	static CInterpMotion_Linear* create_C2A_CInterpMotion_Linear(const btTransform &startTransform,
		const btTransform &endTransform,btScalar timeTolerance = 0.0001 ,btScalar dTolerance = 0.0001);

	/*
	static CInterpMotion_Slerp* create_C2A_CInterpMotion_Slerp(const btTransform &startTransform,
		const btTransform &endTransform,btScalar timeTolerance = 0.0001 ,btScalar dTolerance = 0.0001);
		*/

	static void btTransform_to_PQP(const btTransform &transform,PQP_REAL R[][3],PQP_REAL T[]);

	static void btTransform_to_Transform(const btTransform &transform,Transform &C2ATransform);



};


#endif