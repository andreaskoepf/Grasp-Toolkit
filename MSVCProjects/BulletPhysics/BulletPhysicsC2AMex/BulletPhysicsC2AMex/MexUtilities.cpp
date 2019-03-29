

#include "MexUtilities.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Utility functions

btVector3 MexUtilities::mxArray_to_btVector3(const mxArray *inputStruct,mwIndex index,const char propName[])
{
	// instantiating components of btVector3
	btScalar *p;

	// instantiating pointer to mxArray corresponding to the property value
	const mxArray *propertyValuePointer=mxGetProperty(inputStruct,index,propName);

	// retrieving data and casting to btScalar
	p=(btScalar *)mxGetData(propertyValuePointer);
	

	return btVector3(*p,*(p+1),*(p+2));
	
}

// -------------------------------------------------------------------------------------------- //
btVector4 MexUtilities::mxArray_to_btVector4(const mxArray *inputStruct,mwIndex index,const char propName[])
{
	btScalar *p;
	
	// instantiating pointer to mxArray corresponding to the property value
	const mxArray *propertyValuePointer=mxGetProperty(inputStruct,index,propName);

	// retrieving data and casting to btScalar
	p=(btScalar *)mxGetData(propertyValuePointer);
	

	return btVector4(*p,*(p+1),*(p+2),*(p+3));
}

// -------------------------------------------------------------------------------------------- //

btQuaternion MexUtilities::mxArray_to_btQuaternion(const mxArray *inputStruct,mwIndex index,const char propName[])
{	
	btScalar *p;
	
	// instantiating pointer to mxArray corresponding to the property value
	const mxArray *propertyValuePointer=mxGetProperty(inputStruct,index,propName);

	// retrieving data and casting to btScalar
	p=(btScalar *)mxGetData(propertyValuePointer);
	

	return btQuaternion(*p,*(p+1),*(p+2),*(p+3));
}

// -------------------------------------------------------------------------------------------- //
btScalar MexUtilities::mxArray_to_btScalar(const mxArray *inputStruct,mwIndex index,const char propName[])
{
	btScalar *p;
	
	// instantiating pointer to mxArray corresponding to the property value
	const mxArray *propertyValuePointer=mxGetProperty(inputStruct,index,propName);

	// retrieving data and casting to btScalar
	p=(btScalar *)mxGetData(propertyValuePointer);
	

	return btScalar(*p);
}

// -------------------------------------------------------------------------------------------- //
int MexUtilities::mxArray_to_int(const mxArray *inputStruct,mwIndex index,const char propName[])
{
	int *i;

	// instantiating pointer to mxArray corresponding to the property value
	const mxArray *propertyValuePointer = mxGetProperty(inputStruct,index,propName);

	// retrieving data and casting to int
	i=(int *)mxGetData(propertyValuePointer);

	return *i;
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
btTransform MexUtilities::mxArray_to_btTransform(const mxArray* input)
{


	
	
	// creating pointer to inputStruct data
	btScalar *transformPtr = (btScalar *)mxGetData(input);
	
	// retrieving the array size 
	mwSize rows=mxGetM(input);
	mwSize columns=mxGetN(input);

	// inputStruct array must be a 4 by 4 matrix
	if((rows!=4)&&(columns!=4))
		mexErrMsgTxt("\nA 4 x 4 Array was not passed\n");

	// creating basis
	btMatrix3x3 rotationMatrix(transformPtr[0],transformPtr[4],transformPtr[8],transformPtr[1],transformPtr[5],transformPtr[9],transformPtr[2],transformPtr[6],transformPtr[10]);

	

#ifdef IN_DEBUG_MODE_LEVEL_2
	mexPrintf("[%1.4f\t%1.4f\t%1.4f]\n",rotationMatrix.getRow(0).getX(),rotationMatrix.getBasis().getRow(0).getY(),rotationMatrix.getBasis().getRow(0).getZ());
	mexPrintf("[%1.4f\t%1.4f\t%1.4f]\n",rotationMatrix.getRow(1).getX(),rotationMatrix.getBasis().getRow(1).getY(),rotationMatrix.getBasis().getRow(1).getZ());
	mexPrintf("[%1.4f\t%1.4f\t%1.4f]\n",rotationMatrix.getRow(2).getX(),rotationMatrix.getBasis().getRow(2).getY(),rotationMatrix.getBasis().getRow(2).getZ());
#endif


	btVector3 origin(transformPtr[12],transformPtr[13],transformPtr[14]);

	return btTransform(rotationMatrix,origin);

}

// -------------------------------------------------------------------------------------------- //
btScalar* MexUtilities::mxArray_to_btScalarArray1D(const mxArray *inputStruct,mwIndex index,const char propName[])
{
	// creating pointer to the data store under the propName property
	const mxArray *propertyValue = mxGetProperty(inputStruct,index,propName);
	
	// retrieving the array size 
	mwSize rows=mxGetM(propertyValue);
	mwSize columns=mxGetN(propertyValue);

	// retrieving data and casting to btScalar
	btScalar *p=(btScalar *)mxGetData(propertyValue);
	
	// creating 1D btScalar Array
	btScalar *outArray=new btScalar[rows*columns];

	// creating index
	mwIndex ind=0;

#ifdef IN_DEBUG_MODE_LEVEL_2
	   	
	mexPrintf("\nStart of Array");
	mexPrintf("\nrows:\t%i",rows);
	mexPrintf("\ncolumns:\t%i\n",columns);
	mexPrintf("------------------------------------------------------------\n"); 

#endif

	// storing data in array
	for(mwSize i=0;i<rows;i++)
	{
		
#ifdef IN_DEBUG_MODE_LEVEL_2

		mexPrintf("\n");

#endif
		
		
		for(mwSize j=0;j<columns;j++)
		{

			// storing data into output array
			outArray[ind]=p[j*rows+i];
			ind++;
			
#ifdef IN_DEBUG_MODE_LEVEL_2
	   	
	mexPrintf("[ %i, %i] = %1.3f\t,",i,j,p[j*rows+i]);	


#endif
		}
	}

#ifdef IN_DEBUG_MODE_LEVEL_2
	   	
	mexPrintf("\nEnd of Array\n");
	mexPrintf("------------------------------------------------------------\n"); 

#endif

	return outArray;
	

}

// -------------------------------------------------------------------------------------------- //
btScalar* MexUtilities::mxArray_to_btScalarArray2D(const mxArray *inputStruct,mwIndex index,const char propName[])
{
}

// -------------------------------------------------------------------------------------------- //
btTriangleIndexVertexArray* MexUtilities::mxArray_to_btTriangleIndexVertexArray(const mxArray *inputStruct,mwIndex index)
{

	// mxArraying vertices data
	string propName1="Vertices";
	const mxArray *verticesPointer=mxGetProperty(inputStruct,index,propName1.c_str());

	// obtaining array size
	// the Vertices property contains a 4 x n array where n is the number of vertices
	mwSize rows = mxGetM(verticesPointer);
	mwSize columns = mxGetN(verticesPointer);
		
	// casting to btScalar pointer
	btScalar *vertices2D=(btScalar *)mxGetData(verticesPointer);

	// constructing vertices array
	int NumVertices=columns;
	btScalar *Vertices= new btScalar[NumVertices*(rows-1)];
	// btScalar *vertices =new btScalar[numVertices*(rows-1)];
	mwSize ind=0;

	// assigning data to vertices array
	for(mwIndex j=0;j<columns;j++)
	{
		for(mwIndex i=0;i<rows;i++)
		{
			if(i!=3)
			{
				Vertices[ind]=vertices2D[rows*j+i];
				// vertices[ind]=vertices2D[rows*j+i];
				ind++;
			}
			else
			{
				break;
			}
		}
	}

	// mxArraying faces data
	string propName2="Faces";
	const mxArray *facesPointer=mxGetProperty(inputStruct,index,propName2.c_str());

	// obtaining array size
	rows = mxGetM(facesPointer);
	columns = mxGetN(facesPointer);

	// casting to int Pointer
	int *faces_array = (int *)mxGetData(facesPointer);

	// constructing faces array
	int NumFaces=rows;
	int *Faces = new int[NumFaces*columns];

	

	ind=0;

	// assigning data to faces array
	for(mwIndex i=0;i<rows;i++)
	{
		for(mwIndex j=0;j<columns;j++)
		{
			Faces[ind]=faces_array[rows*j+i]-1; // 1 is substracted because all c arrays are zero based
			ind++;
			// faces[i][j]=faces_array(rows*j+i);
		}
	}

	btTriangleIndexVertexArray* indexVertexArray = new btTriangleIndexVertexArray(NumFaces,Faces,3*sizeof(int),NumVertices,Vertices,3*sizeof(btScalar));

	return indexVertexArray;

}


// -------------------------------------------------------------------------------------------- //
btTriangleIndexVertexArray* MexUtilities::mxArray_to_btTriangleIndexVertexArray(const mxArray *inputStruct,mwIndex index,const char verticesPropName[],
																				const char facesPropName[])
{

	// mxArraying vertices data
	//string propName1="Vertices";
	const mxArray *verticesPointer=mxGetProperty(inputStruct,index,verticesPropName);

	// obtaining array size
	// the Vertices property contains a 4 x n array where n is the number of vertices
	mwSize rows = mxGetM(verticesPointer);
	mwSize columns = mxGetN(verticesPointer);
		
	// casting to btScalar pointer
	btScalar *vertices2D=(btScalar *)mxGetData(verticesPointer);

	// constructing vertices array
	int NumVertices=columns;
	btScalar *Vertices= new btScalar[NumVertices*(rows-1)];
	// btScalar *vertices =new btScalar[numVertices*(rows-1)];
	mwSize ind=0;

	// assigning data to vertices array
	for(mwIndex j=0;j<columns;j++)
	{
		for(mwIndex i=0;i<rows;i++)
		{
			if(i!=3)
			{
				Vertices[ind]=vertices2D[rows*j+i];
				// vertices[ind]=vertices2D[rows*j+i];
				ind++;
			}
			else
			{
				break;
			}
		}
	}

	// mxArraying faces data
	//string propName2="Faces";
	const mxArray *facesPointer=mxGetProperty(inputStruct,index,facesPropName);

	// obtaining array size
	rows = mxGetM(facesPointer);
	columns = mxGetN(facesPointer);

	// casting to int Pointer
	int *faces_array = (int *)mxGetData(facesPointer);

	// constructing faces array
	int NumFaces=rows;
	int *Faces = new int[NumFaces*columns];

	

	ind=0;

	// assigning data to faces array
	for(mwIndex i=0;i<rows;i++)
	{
		for(mwIndex j=0;j<columns;j++)
		{
			Faces[ind]=faces_array[rows*j+i]-1;
			ind++;
			// faces[i][j]=faces_array(rows*j+i);
		}
	}

	btTriangleIndexVertexArray* indexVertexArray = new btTriangleIndexVertexArray(NumFaces,Faces,3*sizeof(int),NumVertices,Vertices,3*sizeof(btScalar));

	return indexVertexArray;

}




// -------------------------------------------------------------------------------------------- //
int* MexUtilities::mxArray_to_int_array(const mxArray *inputStruct,mwIndex index)
{

	// extracting faces data
	string propName="Faces";
	const mxArray *facesPointer=mxGetProperty(inputStruct,index,propName.c_str());

	// obtaining array size
	mwSize rows = mxGetM(facesPointer);
	mwSize columns = mxGetN(facesPointer);

	// casting to int Pointer
	int *faces_array = (int *)mxGetData(facesPointer);

	// constructing faces array
	int *faces = new int[rows*columns];

	
	// initializing index
	int ind=0;

	// assigning data to faces array
	for(mwIndex i=0;i<rows;i++)
	{
		for(mwIndex j=0;j<columns;j++)
		{
			faces[ind]=faces_array[rows*j+i]-1; // decreasing by one since c++ arrays are zero based
			ind++;
			// faces[i][j]=faces_array(rows*j+i);
		}
	}

	return faces;
}


// -------------------------------------------------------------------------------------------- //
int* MexUtilities::mxArray_to_int_array(const mxArray *inputStruct,mwIndex index,const char facesPropName[])
{

	// extracting faces data
	//string propName="Faces";
	const mxArray *facesPointer=mxGetProperty(inputStruct,index,facesPropName);

	// obtaining array size
	mwSize rows = mxGetM(facesPointer);
	mwSize columns = mxGetN(facesPointer);

	// casting to int Pointer
	int *faces_array = (int *)mxGetData(facesPointer);

	// constructing faces array
	int *faces = new int[rows*columns];

	
	// initializing index
	int ind=0;

	// assigning data to faces array
	for(mwIndex i=0;i<rows;i++)
	{
		for(mwIndex j=0;j<columns;j++)
		{
			faces[ind]=faces_array[rows*j+i]-1; // decreasing by one since c++ arrays are zero based
			ind++;
			// faces[i][j]=faces_array(rows*j+i);
		}
	}

	return faces;
}

// -------------------------------------------------------------------------------------------- //
int MexUtilities::mxArray_row_size(const mxArray *inputStruct,mwIndex index)
{
	// initializing returm array
	int numFaces;
	
	// extracting faces data
	string propName="Faces";
	const mxArray *facesPointer=mxGetProperty(inputStruct,index,propName.c_str());

	// obtaining array size
	numFaces = mxGetM(facesPointer);	//	obtaining number of rows

	return numFaces;
}

// -------------------------------------------------------------------------------------------- //
int MexUtilities::mxArray_row_size(const mxArray *inputStruct,mwIndex index,const char propName[])
{
	// initializing returm array
	int numFaces;
	
	// extracting faces data
	//string propName="Faces";
	const mxArray *facesPointer=mxGetProperty(inputStruct,index,propName);

	// obtaining array size
	numFaces = mxGetM(facesPointer);	//	obtaining number of rows

	return numFaces;
}

// -------------------------------------------------------------------------------------------- //
btScalar* MexUtilities::mxArray_to_float_array(const mxArray* inputStruct,mwIndex index)
{
	// extracting vertices data
	string propName="Vertices";
	const mxArray *verticesPointer=mxGetProperty(inputStruct,index,propName.c_str());

	// obtaining array size
	// the Vertices property contains a 4 x n array where n is the number of vertices
	mwSize rows = mxGetM(verticesPointer);
	mwSize columns = mxGetN(verticesPointer);
		
	// casting to btScalar pointer
	btScalar *vertices2D=(btScalar *)mxGetData(verticesPointer);

	// constructing vertices array
	btScalar *vertices= new btScalar[columns*(rows-1)];
	// btScalar *vertices =new btScalar[numVertices*(rows-1)];
	mwSize ind=0;

	// assigning data to vertices array
#ifdef IN_DEBUG_MODE_LEVEL_2
	   	
	mexPrintf("\nExtracting Vertices Array \n");
	mexPrintf("rows\t:\t%i\n",rows);
	mexPrintf("columns\t:\t%i\n",columns);
	mexPrintf("------------------------------------------------------------\n"); 

#endif

	for(mwIndex j=0;j<columns;j++)
	{
		
		
#ifdef IN_DEBUG_MODE_LEVEL_2
	   	
			mexPrintf("\n");

#endif	
		
		
		for(mwIndex i=0;i<rows;i++)
		{



			if(i!=3)
			{
				vertices[ind]=vertices2D[rows*j+i];
				// vertices[ind]=vertices2D[rows*j+i];

				

#ifdef IN_DEBUG_MODE_LEVEL_2
	   	
				mexPrintf("[%i %i (%i)]\t=\t%1.4f\t",i,j,ind,vertices2D[rows*j+i]);

#endif
				ind++;

			}
			else
			{
				break;
			}
		}
	}

#ifdef IN_DEBUG_MODE_LEVEL_2
	   	
	mexPrintf("\nEnd of Vertices Extraction n");
	mexPrintf("------------------------------------------------------------\n"); 

#endif

	return vertices;
}


// -------------------------------------------------------------------------------------------- //
btScalar* MexUtilities::mxArray_to_float_array(const mxArray* inputStruct,mwIndex index,const char verticesPropName[])
{
	// extracting vertices data
	const mxArray *verticesPointer=mxGetProperty(inputStruct,index,verticesPropName);

	// obtaining array size
	// the Vertices property contains a 4 x n array where n is the number of vertices
	mwSize rows = mxGetM(verticesPointer);
	mwSize columns = mxGetN(verticesPointer);
		
	// casting to btScalar pointer
	btScalar *vertices2D=(btScalar *)mxGetData(verticesPointer);

	// constructing vertices array
	btScalar *vertices= new btScalar[columns*(rows-1)];
	// btScalar *vertices =new btScalar[numVertices*(rows-1)];
	mwSize ind=0;

	// assigning data to vertices array
#ifdef IN_DEBUG_MODE_LEVEL_2
	   	
	mexPrintf("\nExtracting Vertices Array \n");
	mexPrintf("rows\t:\t%i\n",rows);
	mexPrintf("columns\t:\t%i\n",columns);
	mexPrintf("------------------------------------------------------------\n"); 

#endif

	for(mwIndex j=0;j<columns;j++)
	{
		
		
#ifdef IN_DEBUG_MODE_LEVEL_2
	   	
			mexPrintf("\n");

#endif	
		
		
		for(mwIndex i=0;i<rows;i++)
		{



			if(i!=3)
			{
				vertices[ind]=vertices2D[rows*j+i];
				// vertices[ind]=vertices2D[rows*j+i];

				

#ifdef IN_DEBUG_MODE_LEVEL_2
	   	
				mexPrintf("[%i %i (%i)]\t=\t%1.4f\t",i,j,ind,vertices2D[rows*j+i]);

#endif
				ind++;

			}
			else
			{
				break;
			}
		}
	}

#ifdef IN_DEBUG_MODE_LEVEL_2
	   	
	mexPrintf("\nEnd of Vertices Extraction n");
	mexPrintf("------------------------------------------------------------\n"); 

#endif

	return vertices;
}


// -------------------------------------------------------------------------------------------- //
int MexUtilities::mxArray_column_size(const mxArray *inputStruct,mwIndex index)
{
	// initializing return array
	int numVertices;
	
	// extracting vertices data
	string propName="Vertices";
	const mxArray *verticesPointer=mxGetProperty(inputStruct,index,propName.c_str());

	// obtaining array size
	// the Vertices property contains a 4 x n array where n is the number of vertices (number of columns in the array)
	numVertices= mxGetN(verticesPointer);

	return numVertices;
}

// -------------------------------------------------------------------------------------------- //
int MexUtilities::mxArray_column_size(const mxArray *inputStruct,mwIndex index,const char propName[])
{
	// initializing return array
	int nColumns;
	
	// extracting vertices data
	//string propName="Vertices";
	const mxArray *verticesPointer=mxGetProperty(inputStruct,index,propName);

	// obtaining array size
	// the Vertices property contains a 4 x n array where n is the number of vertices (number of columns in the array)
	nColumns= mxGetN(verticesPointer);

	return nColumns;
}

// -------------------------------------------------------------------------------------------- //
mxArray* MexUtilities::btVector3_to_mxArray(const btVector3 &vec)
{
	
	// designating array size
	mwSize arraySize[2];
	arraySize[0]=3;
	arraySize[1]=1;

	// declaring and initiating output mxArray
	mxArray *output = mxCreateNumericArray(mwSize(2),&arraySize[0],MXDATA_CLASS,mxREAL);;

	// populating output mxArray	
	btScalar* outArray=(btScalar *)mxGetData(output);
	outArray[0]=btScalar(vec.getX());
	outArray[1]=btScalar(vec.getY());
	outArray[2]=btScalar(vec.getZ());

	return output;
}

// -------------------------------------------------------------------------------------------- //
mxArray* MexUtilities::btVector3_to_mxArray(const btVector3 &vec,bool isRowVector)
{
	
	// designating array size
	mwSize arraySize[2];
	if(!isRowVector)
	{
		arraySize[0]=3;
		arraySize[1]=1;
	}
	else
	{
		arraySize[0]=1;
		arraySize[1]=3;
	}

	// declaring and initiating output mxArray
	mxArray *output = mxCreateNumericArray(mwSize(2),&arraySize[0],MXDATA_CLASS,mxREAL);;

	// populating output mxArray	
	btScalar* outArray=(btScalar *)mxGetData(output);
	outArray[0]=btScalar(vec.getX());
	outArray[1]=btScalar(vec.getY());
	outArray[2]=btScalar(vec.getZ());

	return output;
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

	if(!isRowVector)
	{
		arraySize[0]=size;
		arraySize[1]=1;
	}
	else
	{
		arraySize[0]=1;
		arraySize[1]=size;
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


// -------------------------------------------------------------------------------------------- //
mxArray* MexUtilities::btScalar_to_mxArray(const btScalar &val)
{
	mwSize arraySize[2];
	arraySize[0]=1;
	arraySize[1]=1;

	mxArray *output = mxCreateNumericArray(2,&arraySize[0],MXDATA_CLASS,mxREAL);

	btScalar *outputVal = (btScalar *)mxGetData(output);

	outputVal[0]= val;
	
	return output;
}

// -------------------------------------------------------------------------------------------- //
mxArray* MexUtilities::btScalarArray_to_mxArray(const btScalar *val,mwSize size,bool isRowVector)
{
	mwSize arraySize[2];

	if(!isRowVector)
	{
		arraySize[0]=size;
		arraySize[1]=1;
	}
	else
	{
		arraySize[0]=1;
		arraySize[1]=size;
	}

	mxArray *output = mxCreateNumericArray(2,&arraySize[0],MXDATA_CLASS,mxREAL);

	btScalar *outputVal = (btScalar *)mxGetData(output);

	for(mwSize i = 0;i<size;i++)
	{
		outputVal[i]= val[i];
	}

	return output;
}
// -------------------------------------------------------------------------------------------- //
mxArray* MexUtilities::btTransform_to_mxArray(const btTransform &transform)
{
	mwSize arraySize[2];
	arraySize[0]=4;
	arraySize[1]=4;

	mxArray *output=mxCreateNumericArray(mwSize(2),&arraySize[0],MXDATA_CLASS,mxREAL);

	// acquiring pointer to output data
	btScalar* outArray=(btScalar *)mxGetData(output);

	// setting the rotational part of the matrix	
	for(int i=0;i<3;i++)
	{
		
		outArray[4*i]=transform.getBasis().getColumn(i).getX();
		outArray[4*i+1]=transform.getBasis().getColumn(i).getY();
		outArray[4*i+2]=transform.getBasis().getColumn(i).getZ();
		outArray[4*i+3]=btScalar(0); // last row is filled with zeros		
	}

	outArray[12]=transform.getOrigin().getX();
	outArray[13]=transform.getOrigin().getY();
	outArray[14]=transform.getOrigin().getZ();
	outArray[15]=btScalar(1);

	return output;
}

// -------------------------------------------------------------------------------------------- //
void MexUtilities::print_btTransform(const btTransform &transform)
{
	
	mexPrintf("\n");

	btScalar rot[3][3], pos[3];

	for(int i = 0 ; i<3 ; i++)
	{
		for(int j = 0; j<3 ; j++)
		{
			rot[i][j] = transform.getBasis().getRow(i).m_floats[j];
		}

		pos[i] = transform.getOrigin().m_floats[i];

		mexPrintf("\t%1.4f\t%1.4f\t%1.4f\t%1.4f\n",rot[i][0],rot[i][1],rot[i][2],pos[i]);


	}

}