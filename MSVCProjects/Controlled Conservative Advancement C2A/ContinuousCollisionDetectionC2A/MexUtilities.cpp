#include "MexUtilities.h"


// -------------------------------------------------------------------------------------------- //
double MexUtilities::mxArray_to_double(const mxArray *inputStruct,mwIndex index,const char propName[])
{
	double *p;
	
	// instantiating pointer to mxArray corresponding to the property value
	const mxArray *propertyValuePointer;
	if(mxIsStruct(inputStruct))
	{

		// creating pointer to the data store under the propName property
		propertyValuePointer = mxGetField(inputStruct,index,propName);

	}
	else // treat as object
	{
		
		propertyValuePointer = mxGetProperty(inputStruct,index,propName);

	}

	// retrieving data and casting to double
	p=(double *)mxGetData(propertyValuePointer);
	

	return double(*p);
}

// -------------------------------------------------------------------------------------------- //
int MexUtilities::mxArray_to_int(const mxArray *inputStruct,mwIndex index,const char propName[])
{
	int *i;

	// instantiating pointer to mxArray corresponding to the property value
	const mxArray *propertyValuePointer;
	if(mxIsStruct(inputStruct))
	{

		// creating pointer to the data store under the propName property
		propertyValuePointer = mxGetField(inputStruct,index,propName);

	}
	else // treat as object
	{
		
		propertyValuePointer = mxGetProperty(inputStruct,index,propName);

	}

	// retrieving data and casting to int
	i=(int *)mxGetData(propertyValuePointer);

	return *i;
}

// -------------------------------------------------------------------------------------------- //
double MexUtilities::mxArray_to_double(const mxArray *input)
{

	double *p = (double *)mxGetData(input);

	return *p;

}


// -------------------------------------------------------------------------------------------- //
int MexUtilities::mxArray_to_int(const mxArray *input)
{
	int *i;

	// retrieving data and casting to int
	i=(int *)mxGetData(input);

	return *i;
}

// -------------------------------------------------------------------------------------------- //
bool MexUtilities::mxArray_to_bool(const mxArray *input)
{
	bool *i;

	// retrieving data and casting to int
	i=(bool *)mxGetData(input);


	return *i;
}

// -------------------------------------------------------------------------------------------- //
char MexUtilities::mxArray_to_char(const mxArray *input)
{
	char *p = (char *)mxGetData(input);

	return *p;

}

// -------------------------------------------------------------------------------------------- //
char MexUtilities::mxArray_to_char(const mxArray *inputStruct,mwIndex index,const char propName[])
{

	const mxArray *inputStructProperty ;
	if(mxIsStruct(inputStruct))
	{

		// creating pointer to the data store under the propName property
		inputStructProperty  = mxGetField(inputStruct,index,propName);

	}
	else // treat as object
	{
		
		inputStructProperty  = mxGetProperty(inputStruct,index,propName);

	}

	char *p = (char *)mxGetData(inputStructProperty);

	return *p;

}

// -------------------------------------------------------------------------------------------- //
char* MexUtilities::mxArray_to_char_array(const mxArray *input,MexDataExtractionMode mode)
{

	// checking if data is of char type
	if(!mxIsChar(input))
	{

		mexErrMsgTxt("input data must be a char type");

	}

	// determining mxArray input size
	mwSize rows = mxGetM(input);
	mwSize columns = mxGetN(input);

	// retrieving pointer to char data in mxArray input
	char *p = new char[rows*columns + 1];
	
	if(mxGetString(input,p,rows*columns+1) != 0)
	{
		mexErrMsgTxt("char data could not be copied");

	}

	// creating output char array
	char *outputArray = NULL; //new char[rows*columns + 1];

	mwIndex ind=0;

	switch(mode)
	{
	case COPY_DATA:

		return p;
		break;

	case APPEND_ROW_WISE:

		outputArray = new char[rows*columns + 1];		

		// assigning data to faces array
		for(mwIndex i=0;i<rows;i++)
		{
			for(mwIndex j=0;j<columns;j++)
			{
				outputArray[ind]=p[rows*j + i]; // decreasing by one since c++ arrays are zero based
				ind++;
				// faces[i][j]=faces_array(rows*j+i);
			}
		}

		outputArray[ind] = '\0';
		delete [] p;

		return outputArray;
		break;

	default:

		return p;
		break;

	}

}

// -------------------------------------------------------------------------------------------- //
char* MexUtilities::mxArray_to_char_array(const mxArray* inputStruct,mwIndex index,const char propName[],MexDataExtractionMode mode)
{

	const mxArray *inputStructProperty;
	if(mxIsStruct(inputStruct))
	{

		// creating pointer to the data store under the propName property
		inputStructProperty = mxGetField(inputStruct,index,propName);

	}
	else // treat as object
	{
		
		inputStructProperty = mxGetProperty(inputStruct,index,propName);

	}

	// checking if data is of char type
	if(!mxIsChar(inputStructProperty))
	{

		mexErrMsgTxt("input data must be a char type");

	}

	// determining mxArray input size
	mwSize rows = mxGetM(inputStructProperty);
	mwSize columns = mxGetN(inputStructProperty);

		// retrieving pointer to char data in mxArray input
	char *p = new char[rows*columns + 1];
	
	if(mxGetString(inputStructProperty,p,rows*columns+1) != 0)
	{
		mexErrMsgTxt("char data could not be copied");

	}

	// creating output char array
	char *outputArray = NULL; //new char[rows*columns + 1];

	mwIndex ind=0;

	switch(mode)
	{
	case COPY_DATA:

		return p;
		break;

	case APPEND_ROW_WISE:

		outputArray = new char[rows*columns + 1];		

		// assigning data to faces array
		for(mwIndex i=0;i<rows;i++)
		{
			for(mwIndex j=0;j<columns;j++)
			{
				outputArray[ind]=p[rows*j + i]; // decreasing by one since c++ arrays are zero based
				ind++;
				// faces[i][j]=faces_array(rows*j+i);
			}
		}

		outputArray[ind] = '\0';
		delete [] p;

		return outputArray;
		break;

	default:

		return p;
		break;

	}

}

// -------------------------------------------------------------------------------------------- //
string MexUtilities::mxArray_to_string(const mxArray *input)
{

	char *p = MexUtilities::mxArray_to_char_array(input,COPY_DATA);

	string outString(p);
	delete [] p;
	p = NULL;

	return outString;

}

// -------------------------------------------------------------------------------------------- //
string MexUtilities::mxArray_to_string(const mxArray *inputStruct,mwIndex index,const char propName[])
{

	char *p = MexUtilities::mxArray_to_char_array(inputStruct,index,propName,COPY_DATA);

	string outString(p);
	delete [] p;
	p = NULL;

	return outString;

}

// -------------------------------------------------------------------------------------------- //
double* MexUtilities::mxArray_to_double_array(const mxArray *inputStruct,mwIndex index,const char propName[],MexDataExtractionMode mode)
{
	

	const mxArray *propertyValue;
	if(mxIsStruct(inputStruct))
	{

		// creating pointer to the data store under the propName property
		propertyValue = mxGetField(inputStruct,index,propName);

	}
	else // treat as object
	{
		
		propertyValue = mxGetProperty(inputStruct,index,propName);

	}

	// retrieving the array size 
	mwSize rows=mxGetM(propertyValue);
	mwSize columns=mxGetN(propertyValue);

	// retrieving data and casting to double
	double *p=(double *)mxGetData(propertyValue);
	
	// creating 1D double Array
	double *outputArray = NULL; //new double[rows*columns];

	// creating index
	mwIndex ind=0;

	switch(mode)
	{
	case DO_NOT_COPY_DATA:
		
		return p;
		break;

	case COPY_DATA:

		outputArray = new double[rows*columns];

		// assigning data to faces array
		for(mwIndex i=0;i<rows;i++)
		{
			for(mwIndex j=0;j<columns;j++)
			{
				outputArray[ind]=p[j+columns*i]; // decreasing by one since c++ arrays are zero based
				ind++;
				// faces[i][j]=faces_array(rows*j+i);
			}
		}

		return outputArray;
		break;

	case APPEND_ROW_WISE:

		outputArray = new double[rows*columns];		

		// assigning data to faces array
		for(mwIndex i=0;i<rows;i++)
		{
			for(mwIndex j=0;j<columns;j++)
			{
				outputArray[ind]=p[rows*j + i]; // decreasing by one since c++ arrays are zero based
				ind++;
				// faces[i][j]=faces_array(rows*j+i);
			}
		}

		return outputArray;
		break;

	case ADD_ONE:

		outputArray = new double[rows*columns];

		// assigning data to faces array
		for(mwIndex i=0;i<rows;i++)
		{
			for(mwIndex j=0;j<columns;j++)
			{
				outputArray[ind]=p[j+columns*i] + 1; // decreasing by one since c++ arrays are zero based
				ind++;
				// faces[i][j]=faces_array(rows*j+i);
			}
		}

		return outputArray;
		break;

	case ADD_ONE_AND_APPEND_ROW_WISE:

		outputArray = new double[rows*columns];		

		// assigning data to faces array
		for(mwIndex i=0;i<rows;i++)
		{
			for(mwIndex j=0;j<columns;j++)
			{
				outputArray[ind]=p[rows*j + i]+1; // decreasing by one since c++ arrays are zero based
				ind++;
				// faces[i][j]=faces_array(rows*j+i);
			}
		}

		return outputArray;
		break;

	default:

		return p;
		break;

	}

}

// -------------------------------------------------------------------------------------------- //
double* MexUtilities::mxArray_to_double_array2D(const mxArray *inputStruct,mwIndex index,const char propName[],MexDataExtractionMode  mode)
{
	return NULL;
}

// -------------------------------------------------------------------------------------------- //
int* MexUtilities::mxArray_to_int_array(const mxArray *input,MexDataExtractionMode mode)
{

	// checking if data type is valid
	if(!mxIsInt32(input) || !mxIsInt16(input))
	{
		
		mexErrMsgTxt("input data must be an int type");
		return NULL;

	}

	// obtaining array size
	mwSize rows = mxGetM(input);
	mwSize columns = mxGetN(input);

	// casting to int Pointer
	int *p = (int *)mxGetData(input);

	int *outputArray = NULL;
	int ind=0;

	switch(mode)
	{
	case DO_NOT_COPY_DATA:
		
		return p;
		break;

	case COPY_DATA:

		outputArray = new int[rows*columns];

		// assigning data to faces array
		for(mwIndex i=0;i<rows;i++)
		{
			for(mwIndex j=0;j<columns;j++)
			{
				outputArray[ind]=p[j+columns*i]; // decreasing by one since c++ arrays are zero based
				ind++;
				// faces[i][j]=faces_array(rows*j+i);
			}
		}

		return outputArray;
		break;

	case APPEND_ROW_WISE:

		outputArray = new int[rows*columns];		

		// assigning data to faces array
		for(mwIndex i=0;i<rows;i++)
		{
			for(mwIndex j=0;j<columns;j++)
			{
				outputArray[ind]=p[rows*j + i]; // decreasing by one since c++ arrays are zero based
				ind++;
				// faces[i][j]=faces_array(rows*j+i);
			}
		}

		return outputArray;
		break;

	case ADD_ONE:

		outputArray = new int[rows*columns];

		// assigning data to faces array
		for(mwIndex i=0;i<rows;i++)
		{
			for(mwIndex j=0;j<columns;j++)
			{
				outputArray[ind]=p[j+columns*i] + 1; // decreasing by one since c++ arrays are zero based
				ind++;
				// faces[i][j]=faces_array(rows*j+i);
			}
		}

		return outputArray;
		break;

	case ADD_ONE_AND_APPEND_ROW_WISE:

		outputArray = new int[rows*columns];		

		// assigning data to faces array
		for(mwIndex i=0;i<rows;i++)
		{
			for(mwIndex j=0;j<columns;j++)
			{
				outputArray[ind]=p[rows*j + i]+1; // decreasing by one since c++ arrays are zero based
				ind++;
				// faces[i][j]=faces_array(rows*j+i);
			}
		}

		return outputArray;
		break;

	default:

		return p;
		break;

	}

	//return outputArray;
}

// -------------------------------------------------------------------------------------------- //
int* MexUtilities::mxArray_to_int_array(const mxArray *inputStruct,mwIndex index,const char propName[],MexDataExtractionMode mode)
{

	// extracting faces data
	//string propName="Faces";
	const mxArray *inputStructProperty;
	if(mxIsStruct(inputStruct))
	{

		// creating pointer to the data store under the propName property
		inputStructProperty = mxGetField(inputStruct,index,propName);

	}
	else // treat as object
	{
		
		inputStructProperty = mxGetProperty(inputStruct,index,propName);

	}

	// obtaining array size
	mwSize rows = mxGetM(inputStructProperty);
	mwSize columns = mxGetN(inputStructProperty);

	// casting to int Pointer
	int *p = (int *)mxGetData(inputStructProperty);

	// constructing faces array
	int *outputArray = NULL; // = new int[rows*columns];

	
	// initializing index
	int ind=0;

	switch(mode)
	{
	case DO_NOT_COPY_DATA:
		
		return p;
		break;

	case COPY_DATA:

		outputArray = new int[rows*columns];

		// assigning data to faces array
		for(mwIndex i=0;i<rows;i++)
		{
			for(mwIndex j=0;j<columns;j++)
			{
				outputArray[ind]=p[j+columns*i]; // decreasing by one since c++ arrays are zero based
				ind++;
				// faces[i][j]=faces_array(rows*j+i);
			}
		}

		return outputArray;
		break;

	case APPEND_ROW_WISE:

		outputArray = new int[rows*columns];		

		// assigning data to faces array
		for(mwIndex i=0;i<rows;i++)
		{
			for(mwIndex j=0;j<columns;j++)
			{
				outputArray[ind]=p[rows*j + i]; // decreasing by one since c++ arrays are zero based
				ind++;
				// faces[i][j]=faces_array(rows*j+i);
			}
		}

		return outputArray;
		break;

	case ADD_ONE:

		outputArray = new int[rows*columns];

		// assigning data to faces array
		for(mwIndex i=0;i<rows;i++)
		{
			for(mwIndex j=0;j<columns;j++)
			{
				outputArray[ind]=p[j+columns*i] + 1; // decreasing by one since c++ arrays are zero based
				ind++;
				// faces[i][j]=faces_array(rows*j+i);
			}
		}

		return outputArray;
		break;

	case ADD_ONE_AND_APPEND_ROW_WISE:

		outputArray = new int[rows*columns];		

		// assigning data to faces array
		for(mwIndex i=0;i<rows;i++)
		{
			for(mwIndex j=0;j<columns;j++)
			{
				outputArray[ind]=p[rows*j + i]+1; // decreasing by one since c++ arrays are zero based
				ind++;
				// faces[i][j]=faces_array(rows*j+i);
			}
		}

		return outputArray;
		break;

	default:

		return p;
		break;

	}

}

// -------------------------------------------------------------------------------------------- //
int MexUtilities::mxArray_row_size(const mxArray *input)
{
	// obtaining array size
	int rows = mxGetM(input);	//	obtaining number of rows

	return rows;
}

// -------------------------------------------------------------------------------------------- //
int MexUtilities::mxArray_row_size(const mxArray *inputStruct,mwIndex index,const char propName[])
{
	const mxArray *inputStructProperty;
	if(mxIsStruct(inputStruct))
	{

		// creating pointer to the data store under the propName property
		inputStructProperty = mxGetField(inputStruct,index,propName);

	}
	else // treat as object
	{
		
		inputStructProperty = mxGetProperty(inputStruct,index,propName);

	}

	//	obtaining number of rows
	int rows = mxGetM(inputStructProperty);	

	return rows;
}

// -------------------------------------------------------------------------------------------- //
double* MexUtilities::mxArray_to_double_array(const mxArray* input,MexDataExtractionMode mode)
{
	
	if(!mxIsDouble(input))
	{
		
		mexErrMsgTxt("input must be numeric");
		return NULL;

	}

	// obtaining array sizes
	mwSize rows = mxGetM(input);
	mwSize columns = mxGetN(input);
		
	// casting to double pointer
	double *p=(double *)mxGetData(input);

	// constructing vertices array
	double *outputArray = NULL; //= new double[columns*rows];

	mwSize ind=0;

	switch(mode)
	{
	case DO_NOT_COPY_DATA:
		
		return p;
		break;

	case COPY_DATA:

		outputArray = new double[rows*columns];

		// assigning data to faces array
		for(mwIndex i=0;i<rows;i++)
		{
			for(mwIndex j=0;j<columns;j++)
			{
				outputArray[ind]=p[j+columns*i]; // decreasing by one since c++ arrays are zero based
				ind++;
				// faces[i][j]=faces_array(rows*j+i);
			}
		}

		return outputArray;
		break;

	case APPEND_ROW_WISE:

		outputArray = new double[rows*columns];		

		// assigning data to faces array
		for(mwIndex i=0;i<rows;i++)
		{
			for(mwIndex j=0;j<columns;j++)
			{
				outputArray[ind]=p[rows*j + i]; // decreasing by one since c++ arrays are zero based
				ind++;
				// faces[i][j]=faces_array(rows*j+i);
			}
		}

		return outputArray;
		break;

	case ADD_ONE:

		outputArray = new double[rows*columns];

		// assigning data to faces array
		for(mwIndex i=0;i<rows;i++)
		{
			for(mwIndex j=0;j<columns;j++)
			{
				outputArray[ind]=p[j+columns*i] + 1; // decreasing by one since c++ arrays are zero based
				ind++;
				// faces[i][j]=faces_array(rows*j+i);
			}
		}

		return outputArray;
		break;

	case ADD_ONE_AND_APPEND_ROW_WISE:

		outputArray = new double[rows*columns];		

		// assigning data to faces array
		for(mwIndex i=0;i<rows;i++)
		{
			for(mwIndex j=0;j<columns;j++)
			{
				outputArray[ind]=p[rows*j + i]+1; // decreasing by one since c++ arrays are zero based
				ind++;
				// faces[i][j]=faces_array(rows*j+i);
			}
		}

		return outputArray;
		break;

	default:

		return p;
		break;

	}

}



// -------------------------------------------------------------------------------------------- //
int MexUtilities::mxArray_column_size(const mxArray *input)
{

	// obtaining array size
	int columns= mxGetN(input);

	return columns;
}

// -------------------------------------------------------------------------------------------- //
int MexUtilities::mxArray_column_size(const mxArray *inputStruct,mwIndex index,const char propName[])
{
	
	// obtaining array size
	const mxArray *inputStructProperty;
	if(mxIsStruct(inputStruct))
	{

		// creating pointer to the data store under the propName property
		inputStructProperty = mxGetField(inputStruct,index,propName);

	}
	else // treat as object
	{
		
		inputStructProperty = mxGetProperty(inputStruct,index,propName);

	}

	// obtaining array size
	int columns= mxGetN(inputStructProperty);

	return columns;
}

// -------------------------------------------------------------------------------------------- //
mxArray* MexUtilities::bool_to_mxArray(bool boolean)
{
	mxArray *output = mxCreateLogicalScalar(boolean);
	return output;
}

// -------------------------------------------------------------------------------------------- //
mxArray* MexUtilities::int_to_mxArray(const int &val)
{
	mwSize arraySize[2];
	arraySize[0]=1;
	arraySize[1]=1;

	mxArray* output = mxCreateNumericArray(2,&arraySize[0],mxINT32_CLASS,mxREAL);

	int *outputVal = (int *)mxGetData(output);

	outputVal[0]=val;

	return output;
}

// -------------------------------------------------------------------------------------------- //
mxArray* MexUtilities::intArray_to_mxArray(const int *val,mwSize size,bool isRowVector)
{
	mwSize arraySize[2];

	if(isRowVector)
	{
		arraySize[0]=1;
		arraySize[1]=size;
	}
	else
	{
		arraySize[0]=size;
		arraySize[1]=1;
	}

	mxArray *output = mxCreateNumericArray(2,&arraySize[0],mxINT32_CLASS,mxREAL);
		
	int *outputVal = (int *)mxGetData(output);

	for(mwSize i=0;i<size;i++)
	{
		outputVal[i] = val[i];
	}

	return output;
}

// -------------------------------------------------------------------------------------------- //
mxArray* MexUtilities::double_to_mxArray(const double &val)
{
	mwSize arraySize[2];
	arraySize[0]=1;
	arraySize[1]=1;

	mxArray *output = mxCreateNumericArray(2,&arraySize[0],mxDOUBLE_CLASS,mxREAL);

	double *outputVal = (double *)mxGetData(output);

	outputVal[0]= val;
	
	return output;
}

// -------------------------------------------------------------------------------------------- //
mxArray* MexUtilities::doubleArray_to_mxArray(const double *val,mwSize size,bool isRowVector)
{
	mwSize arraySize[2];

	if(isRowVector)
	{
		arraySize[0]=1;
		arraySize[1]=size;
	}
	else
	{
		arraySize[0]=size;
		arraySize[1]=1;
	}

	mxArray *output = mxCreateNumericArray(2,&arraySize[0],mxDOUBLE_CLASS,mxREAL);

	double *outputVal = (double *)mxGetData(output);

	for(mwSize i = 0;i<size;i++)
	{
		outputVal[i]= val[i];
	}

	return output;
}

// -------------------------------------------------------------------------------------------- //
mxArray* MexUtilities::doubleArray_to_mxMatrix(const double *val, mwSize rows, mwSize columns, bool appendRowWise)
{

	mwSize arraySize[2];

	arraySize[0] = rows;
	arraySize[1] = columns;

	mxArray *output = mxCreateNumericArray(2,&arraySize[0],mxDOUBLE_CLASS,mxREAL);
	double *outputVal = (double *)mxGetData(output);

	if(appendRowWise)
	{

		for(mwSize i = 0; i<rows; i++)
		{

			for(mwSize j = 0; j<columns; j++)
			{

				outputVal[rows*j + i] = val[i*columns + j];

			}

		}

	}
	else
	{

		for(mwSize i = 0; i<rows; i++)
		{

			for(mwSize j = 0; j<columns; j++)
			{

				outputVal[i*columns + j] = val[i*columns + j];

			}

		}

	}

	return output;

}


// -------------------------------------------------------------------------------------------- //
mxArray* MexUtilities::intArray_to_mxMatrix(const int *val, mwSize rows, mwSize columns, bool appendRowWise)
{

	mwSize arraySize[2];

	arraySize[0] = rows;
	arraySize[1] = columns;

	mxArray *output = mxCreateNumericArray(2,&arraySize[0],mxINT32_CLASS,mxREAL);
	int *outputVal = (int *)mxGetData(output);

	if(appendRowWise)
	{

		for(mwSize i = 0; i<rows; i++)
		{

			for(mwSize j = 0; j<columns; j++)
			{

				outputVal[rows*j + i] = val[i*columns + j];

			}

		}

	}
	else
	{

		for(mwSize i = 0; i<rows; i++)
		{

			for(mwSize j = 0; j<columns; j++)
			{

				outputVal[i*columns + j] = val[i*columns + j];

			}

		}

	}

	return output;

}

// -------------------------------------------------------------------------------------------- //
mxArray* MexUtilities::charArray_to_mxArray(const char *val,mwSize size,bool isRowVector)
{
	mwSize arraySize[2];
	
	if(isRowVector)
	{
		arraySize[0] = 1;
		arraySize[1] = size;
	}
	else
	{
		arraySize[0] = size;
		arraySize[1] = 1;
	}


	
	mxArray *output = mxCreateCharArray(2,&arraySize[0]);

	mxChar *outputVal = mxGetChars(output);
	//char *outputVal = (char *)mxGetData(output);

	for(mwSize i = 0; i < size;i++)
	{

		outputVal[i] = val[i];

	}
	

	//mxArray *output = mxCreateString(val);

	return output;

}




