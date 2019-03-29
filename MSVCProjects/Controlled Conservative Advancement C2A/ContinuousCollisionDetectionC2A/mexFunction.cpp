#include "mexFunction.h"
#include "ContinuousCollisionDetection.h"

void mexFunction(int nlhs,mxArray *plhs[], int nrhs, const mxArray *prhs[])
{

	mexSetTrapFlag(int(1));

	ContinuousCollisionDetection::method_selector(nrhs,prhs,nlhs,plhs);

}

