#ifndef CONTINUOUSCOLLISIONDETECTION_H
#define CONTINUOUSCOLLISIONDETECTION_H

#include "mexFunction.h"
#include "MexUtilities.h"
#include "Solid.h"
#include "LinearMath/btQuaternion.h"
#include "LinearMath/btTransform.h"

// including PQP and C2A Libraries
#include "C2AUtilities.h"

#include "BulletCollision/NarrowPhaseCollision/btGjkConvexCast.h"

/*
#include "BulletCollision/NarrowPhaseCollision/btVoronoiSimplexSolver.h"
#include "BulletCollision/CollisionShapes/btBoxShape.h"
#include "BulletCollision/CollisionShapes/btMinkowskiSumShape.h"

#include "BulletCollision/NarrowPhaseCollision/btGjkPairDetector.h"
#include "BulletCollision/NarrowPhaseCollision/btGjkConvexCast.h"
#include "BulletCollision/NarrowPhaseCollision/btSubSimplexConvexCast.h"
#include "BulletCollision/NarrowPhaseCollision/btContinuousConvexCollision.h"

*/


enum CCDMethods{
	CCD_CONSTRUCTOR,
	CCD_SETOBJECTA,
	CCD_SETOBJECTB,
	CCD_PERFORMCCDTEST,
	CCD_DESTRUCTOR=-1
};

enum CCDTESTTYPE{
	CCD_COMPOUND_VS_COMPOUND,
	CCD_COMPOUND_VS_CONVEX,
	CCD_CONVEX_VS_CONVEX,
	CCD_CONVEX_VS_COMPOUND
};






class ContinuousCollisionDetection
{
public:

	ContinuousCollisionDetection(const mxArray *obj);
	~ContinuousCollisionDetection();

	void performCCDTest(int nargin,const mxArray *inputs[],int nargout,mxArray *output[]);

	void setObjectA(int nargin,const mxArray *inputs[]);
	void setObjectB(int nargin,const mxArray *inputs[]);

	int solveC2A(const btTransform &objectATransform0,const btTransform &objectATransformf,const btTransform &objectBTransform0
		,const btTransform &objectBTransformf,btTransform &objectATransformTOC,btTransform &objectBTransformTOC,int &number_of_iterations
		,PQP_REAL th_ca,C2A_TimeOfContactResult &dres);



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

	C2A_Model *ObjectAModel;
	C2A_Model *ObjectBModel;

	btTransform LocalTransformA;
	btTransform LocalTransformB;





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