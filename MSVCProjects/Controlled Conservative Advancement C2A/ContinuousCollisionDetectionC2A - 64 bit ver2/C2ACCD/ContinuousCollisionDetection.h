#ifndef CONTINUOUSCOLLISIONDETECTION_H
#define CONTINUOUSCOLLISIONDETECTION_H

#include "mexFunction.h"
#include "MexUtilities.h"
#include "LinearMath/btQuickprof.h"
#include "LinearMath/btQuaternion.h"
#include "LinearMath/btTransform.h"

// including PQP and C2A Libraries
#include "C2AUtilities.h"



enum CCDMethods{
	CCD_CONSTRUCTOR,
	CCD_SETOBJECTA,
	CCD_SETOBJECTB,
	CCD_PERFORMCCDTEST,
	CCD_DESTRUCTOR=-1
};

enum CCDCollisionFlags{
	CCD_COLLISION_FOUND = -1,
	CCD_COLLISION_FREE = 0,
	CCD_TOC_FOUND = 1

};




void Contact_normal_new(C2A_TimeOfContactResult *res,C2A_Model *o1,C2A_Model *o2, Transform moving_transform, Transform object_2_pose);


class ContinuousCollisionDetection
{
public:

	ContinuousCollisionDetection(const mxArray *intputStruct);
	~ContinuousCollisionDetection();

	void performCCDTest(int nargin,const mxArray *inputs[],int nargout,mxArray *output[]);

	void setObjectA(int nargin,const mxArray *inputs[]);
	void setObjectB(int nargin,const mxArray *inputs[]);

	int solveC2A(const btTransform &objectATransform0,const btTransform &objectATransformf,const btTransform &objectBTransform0
		,const btTransform &objectBTransformf,btTransform &objectATransformTOC,btTransform &objectBTransformTOC,int &number_of_iterations
		,PQP_REAL th_ca,C2A_TimeOfContactResult &dres);

	// conversion to C2A Data
	static CCDCollisionFlags convertC2ACollisionFlag(C2A_Result flag);


	// handle accessing methods
	static void create_handle(int nargin,const mxArray *inputs[],mxArray **output);
	static void destroy_handle(const mxArray *input);
	static ContinuousCollisionDetection* get_object_pointer(const mxArray *input);
	static void method_selector(int nargin,const mxArray* intputs[], int nargout, mxArray* outputs[]);

	// additional informative methods  
	static void printMethodCallDetails(const string &methodName,int methodIndex);



protected:


	C2A_Model *ObjectAModel;
	C2A_Model *ObjectBModel;

	btTransform LocalTransformA;
	btTransform LocalTransformB;

	int mNumIterations;





};











/*
class ContinuousCollisionDetection
{
public:

	ContinuousCollisionDetection(const mxArray *obj);
	~ContinuousCollisionDetection();

	void performCCDTest(int nargin,const mxArray *inputs[],int nargout,mxArray *output[]);

	void setObjectA(const mxArray *solidHandle);
	void setObjectB(const mxArray *solidHandle);


	// handle accessing methods
	static void create_handle(int nargin,const mxArray *inputs[],mxArray **output);
	static void destroy_handle(const mxArray *input);
	static ContinuousCollisionDetection* get_object_pointer(const mxArray *input);
	static void method_selector(int nargin,const mxArray* intputs[], int nargout, mxArray* outputs[]);

	// additional informative methods  
	static void printMethodCallDetails(const string &methodName,int methodIndex);

protected:
	Solid *ObjectA;
	Solid *ObjectB;

	btConvexShape *ConvexShapeA;
	btConvexShape *ConvexShapeB;

	int CollisionType;

	btContinuousConvexCollision *CCDCaster;
	btConvexPenetrationDepthSolver *PenetrationDepthSolver;
	btSimplexSolverInterface *SimplexSolverInterface;

	void resetCCDCaster();

	// pointer to corresponding collision test function 
	bool (ContinuousCollisionDetection::*ccdTestFunction)(btTransform& ,btTransform& ,btTransform& ,btTransform&,btConvexCast::CastResult&);

	// collision test helpers
	bool ccdTestCompoundvsCompoundShapes(btTransform &startTransformA,btTransform &endTransformA,
		btTransform &startTransformB,btTransform &endTransformB,btConvexCast::CastResult &result);

	bool ccdTestCompoundvsConvexShapes(btTransform &startTransformA,btTransform &endTransformA,
		btTransform &startTransformB,btTransform &endTransformB,btConvexCast::CastResult &result);

	bool ccdTestConvexvsConvexShapes(btTransform &startTransformA,btTransform &endTransformA,
		btTransform &startTransformB,btTransform &endTransformB,btConvexCast::CastResult &result);

	bool ccdTestConvexvsCompoundShapes(btTransform &startTransformA,btTransform &endTransformA,
		btTransform &startTransformB,btTransform &endTransformB,btConvexCast::CastResult &result);

};

*/


#endif