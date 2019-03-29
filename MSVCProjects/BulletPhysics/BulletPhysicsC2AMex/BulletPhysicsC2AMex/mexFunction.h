

#ifndef MEX_FUNCTION_H
#define MEX_FUNCTION_H



// User Preprocessors ----------------------------------------------------------------//
#define IN_DEBUG_MODE_LEVEL_1
//#define IN_DEBUG_MODE_LEVEL_2

// select collision method
//#define USE_DEFAULT_COLLISION 1
#define USE_GIMPACT_COLLISION

// this will be set to mxDOUBLE_CLASS once the physics library is compile with support for double precision data.
#define MXDATA_CLASS mxDOUBLE_CLASS 

// Bullet Preprocessors -------------------------------------------------------------//
//#define SHRINK_OBJECT_INWARDS

#include <vector>
#include <algorithm>
#include <string>
using namespace std;

#include "mex.h"
#include "matrix.h"


// indices defined for input data
enum InputDataIndexes{
	CLASS_IDENTIFIER_INDEX=0,
	METHOD_IDENTIFIER_INDEX,
	HANDLE_IDENTIFIER_INDEX,
	CONSTRUCTION_DATA_INDEX=2,
	START_OF_INPUT_DATA_INDEX
};



// exit function
void closeMexFunction();

#endif