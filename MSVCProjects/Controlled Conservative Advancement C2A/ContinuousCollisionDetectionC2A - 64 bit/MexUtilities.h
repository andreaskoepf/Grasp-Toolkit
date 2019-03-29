#ifndef MEXUTILITIES_H
#define MEXUTILITIES_H

#include "mexFunction.h"
#include <string>
#include <vector>
#include <typeinfo>


using namespace std;

enum MexDataExtractionMode 
{
	DO_NOT_COPY_DATA,
	COPY_DATA,	
	APPEND_ROW_WISE, // copies data
	ADD_ONE, // copies data
	ADD_ONE_AND_APPEND_ROW_WISE // copies data
};

class MexUtilities
{
public:

		// -------------------------------------------------------------------------------------------- //
		// -------------------------------------------------------------------------------------------- //
		// Methods for indirect data extraction from fields of object or structure inputs

			// extract data from objects or structure properties passed as arguments
			static int mxArray_to_int(const mxArray* input);
			static int mxArray_to_int(const mxArray* inputStruct,mwIndex index,const char propName[]);
			static int* mxArray_to_int_array(const mxArray *input,MexDataExtractionMode mode = DO_NOT_COPY_DATA);
			static int* mxArray_to_int_array(const mxArray *inputStruct,mwIndex index,const char propName[],MexDataExtractionMode mode = DO_NOT_COPY_DATA);


			static double mxArray_to_double(const mxArray* input);
			static double mxArray_to_double(const mxArray* inputStruct,mwIndex index,const char propName[]);
			static double* mxArray_to_double_array(const mxArray *input,MexDataExtractionMode mode = DO_NOT_COPY_DATA);
			static double* mxArray_to_double_array(const mxArray *inputStruct,mwIndex index,const char propName[],MexDataExtractionMode mode = DO_NOT_COPY_DATA);
			static double* mxArray_to_double_array2D(const mxArray *inputStruct,mwIndex index,const char propName[],MexDataExtractionMode mode = DO_NOT_COPY_DATA);							

			static char mxArray_to_char(const mxArray *input);
			static char mxArray_to_char(const mxArray *inputStruct,mwIndex index,const char propName[]);
			static char* mxArray_to_char_array(const mxArray *input,MexDataExtractionMode mode = COPY_DATA);// only supports COPY_DATA and APPEND_ROW_WISE
			static char* mxArray_to_char_array(const mxArray *inputStruct,mwIndex index,const char propName[],MexDataExtractionMode mode = COPY_DATA);// only supports COPY_DATA and APPEND_ROW_WISE
			
			static string mxArray_to_string(const mxArray *input); // copies data by default
			static string mxArray_to_string(const mxArray *inputStruct,mwIndex index,const char propName[]);

			static int mxArray_row_size(const mxArray *input);
			static int mxArray_row_size(const mxArray *inputStruct,mwIndex index,const char propName[]);            
			static int mxArray_column_size(const mxArray *input);			 
			// extracts the column size of an array stored in a structure of object under the object property or field name 
			// indicated by propName   
			static int mxArray_column_size(const mxArray *inputStruct,mwIndex index,const char propName[]);

		// -------------------------------------------------------------------------------------------- //
		// -------------------------------------------------------------------------------------------- //
		// Methods to extract data from c++ ,c and bullet data types and populate mxArray types

			// all returned mxArray* pointers contain copies of the input data.  Therefore, the input data
			// must be deleted once it is not needed if this was dynamically allocated.
			static mxArray* int_to_mxArray(const int &val);

			static mxArray* bool_to_mxArray(bool boolean);

			static mxArray* intArray_to_mxArray(const int *val,mwSize size,bool isRowVector = true);

			static mxArray* double_to_mxArray(const double &val);

			static mxArray* doubleArray_to_mxArray(const double *val,mwSize size,bool isRowVector = true);

			static mxArray* intArray_to_mxMatrix(const int *val,mwSize rows,mwSize columns,bool appendRowWise = true);

			static mxArray* doubleArray_to_mxMatrix(const double *val,mwSize rows,mwSize columns,bool appendRowWise = true);

			template<typename T> static mxArray* vector_to_mxMatrix(const vector<T> &valVector,mwSize rows,mwSize columns,bool appednRowWise = true);

			static mxArray* charArray_to_mxArray(const char *val,mwSize size,bool isRowVector = true);
		
		// -------------------------------------------------------------------------------------------- //
		// -------------------------------------------------------------------------------------------- //
};

// -------------------------------------------------------------------------------------------- //
template<typename T> mxArray* MexUtilities::vector_to_mxMatrix(const std::vector<T> &valVector,mwSize rows,mwSize columns,bool appendRowWise)
{

	mxClassID classID;
	if(typeid(T) == typeid(char))
	{
		
		classID = mxCHAR_CLASS;

	}
	else if(typeid(T) == typeid(double))
	{

		classID = mxDOUBLE_CLASS;

	}
	else if(typeid(T) == typeid(int))
	{

		classID = mxINT32_CLASS;

	}
	else
	{

		mexErrMsgTxt("input vector must contain either double, int or char elements");

	}

	mwSize arraySize[2];

	arraySize[0] = rows;
	arraySize[1] = columns;

	mxArray *output = mxCreateNumericArray(2,&arraySize[0],classID,mxREAL);
	T *outputVal = (T *)mxGetData(output);

	if(appendRowWise)
	{

		for(mwSize i = 0; i<rows; i++)
		{

			for(mwSize j = 0; j<columns; j++)
			{

				outputVal[rows*j + i] = valVector[i*columns + j];

			}

		}

	}
	else
	{

		for(mwSize i = 0; i<rows; i++)
		{

			for(mwSize j = 0; j<columns; j++)
			{

				outputVal[i*columns + j] = valVector[i*columns + j];

			}

		}

	}

	return output;

}

#endif
