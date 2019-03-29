

#include "mexFunction.h"
#include "TrimeshConvexDeComposition.h"
#include "Solid.h"
#include "ArticulatedBody.h"
#include "SimplePhysicsEnvironment.h"
#include "ContinuousCollisionDetection.h"


// defining closeMexFunction
void closeMexFunction()
{
	if(mexIsLocked())
	{
		mexUnlock();
	}

#ifdef IN_DEBUG_MODE_LEVEL_1
	mexPrintf("\nMex File %s Unlocked\n",mexFunctionName());
#endif
}


enum ClassIndexes{
	SIMPLE_PHYSICS_ENVIRONMENT=1,
	SOLID,
	ARTICULATED_BODY,
	CONTINUOUSCOLLISIONDETECTION

};

void mexFunction(int nlhs,mxArray *plhs[],int nrhs,const mxArray *prhs[])
{

	
	
	if((!mxIsInt8(prhs[CLASS_IDENTIFIER_INDEX])&&!mxIsInt16(prhs[CLASS_IDENTIFIER_INDEX]))&&(!mxIsInt32(prhs[CLASS_IDENTIFIER_INDEX])&&!mxIsInt64(prhs[CLASS_IDENTIFIER_INDEX])))
	{
		mexErrMsgTxt("must pass an integer data type for the class identifier index\n");
		return;
	}
	
	

	int *class_index=(int *)mxGetData(prhs[CLASS_IDENTIFIER_INDEX]);

	switch(*class_index)
	{
		case SIMPLE_PHYSICS_ENVIRONMENT:

#ifdef IN_DEBUG_MODE_LEVEL_2
			mexPrintf("\nBullet Physics Mex File Call\n");
			mexPrintf("------------------------------------------------------------\n");
			//mexPrintf("SimplePhysicsEnvironment Object Call\n");
#endif
			SimplePhysicsEnvironment::method_selector(nrhs,prhs,nlhs,plhs);



			break;

		case SOLID:

#ifdef IN_DEBUG_MODE_LEVEL_2
			mexPrintf("\nBullet Physics Mex File Call\n");
			mexPrintf("------------------------------------------------------------\n");
			//mexPrintf("Solid Object Call\n");
#endif
			Solid::method_selector(nrhs,prhs,nlhs,plhs);



			break;

		case CONTINUOUSCOLLISIONDETECTION:

#ifdef IN_DEBUG_MODE_LEVEL_2
			mexPrintf("\nBullet Physics Mex File Call\n");
			mexPrintf("------------------------------------------------------------\n");
			//mexPrintf("ContinuousCollisionDetection Object Call\n");
#endif
			ContinuousCollisionDetection::method_selector(nrhs,prhs,nlhs,plhs);



			break;

		case ARTICULATED_BODY:

#ifdef IN_DEBUG_MODE_LEVEL_2
			mexPrintf("\nBullet Physics Mex File Call\n");
			mexPrintf("------------------------------------------------------------\n");
			//mexPrintf("Solid Object Call\n");
#endif
			ArticulatedBody::method_selector(nrhs,prhs,nlhs,plhs);



			break;

		default:
			break;
	}

	return;
}
