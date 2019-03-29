#ifndef MEX_FUNCTION_H
#define MEX_FUNCTION_H

#include "mex.h"
#include "matrix.h"

//#define USING_BULLET_MATH
//#define IN_DEBUG_MODE
//#define IN_DEBUG_MODE_2

// indices defined for input data
enum InputDataIndexes{
	CLASS_IDENTIFIER_INDEX=-1, // not in use
	METHOD_IDENTIFIER_INDEX = 0,
	HANDLE_IDENTIFIER_INDEX = 1,
	CONSTRUCTION_DATA_INDEX = 1,
	START_OF_INPUT_DATA_INDEX = 2
};



#endif