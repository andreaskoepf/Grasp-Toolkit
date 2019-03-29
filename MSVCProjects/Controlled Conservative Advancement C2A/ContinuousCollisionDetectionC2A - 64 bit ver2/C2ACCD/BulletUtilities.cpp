#include "BulletUtilities.h"

// -------------------------------------------------------------------------------------------- //
btVector3 BulletUtilities::mxArray_to_btVector3(const mxArray *input)
{

	double *p = MexUtilities::mxArray_to_double_array(input);

	return btVector3(*p,*(p+1),*(p+2));

}

// -------------------------------------------------------------------------------------------- //
btTransform BulletUtilities::mxArray_to_btTransform(const mxArray *input)
{
	
	// retrieving the array size 
	mwSize rows=mxGetM(input);
	mwSize columns=mxGetN(input);

	// inputStruct array must be a 4 by 4 matrix
	if((rows!=4)&&(columns!=4))
		mexErrMsgTxt("\nBulletUtilities::mxArray_to_btTransform: A 4 x 4 Array was not passed\n");

	double *p = MexUtilities::mxArray_to_double_array(input);

	// creating basis
	btMatrix3x3 rotationMatrix(p[0],p[4],p[8],p[1],p[5],p[9],p[2],p[6],p[10]);

	btVector3 origin(p[12],p[13],p[14]);

	return btTransform(rotationMatrix,origin);

}

// -------------------------------------------------------------------------------------------- //
mxArray* BulletUtilities::btTransform_to_mxArray(const btTransform &transform)
{

	mwSize arraySize[2];
	arraySize[0]=4;
	arraySize[1]=4;

	mxArray *output=mxCreateNumericArray(mwSize(2),&arraySize[0],mxDOUBLE_CLASS,mxREAL);

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
mxArray* BulletUtilities::btVector3_to_mxArray(const btVector3 &vec)
{

		// designating array size
	mwSize arraySize[2];
	arraySize[0]=3;
	arraySize[1]=1;

	// declaring and initiating output mxArray
	mxArray *output = mxCreateNumericArray(mwSize(2),&arraySize[0],mxDOUBLE_CLASS,mxREAL);;

	// populating output mxArray	
	btScalar* outArray=(btScalar *)mxGetData(output);
	outArray[0]=btScalar(vec.getX());
	outArray[1]=btScalar(vec.getY());
	outArray[2]=btScalar(vec.getZ());

	return output;

}

// -------------------------------------------------------------------------------------------- //
mxArray* BulletUtilities::btVector3_to_mxArray(const btVector3 &vec,bool isRowVector)
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
	mxArray *output = mxCreateNumericArray(mwSize(2),&arraySize[0],mxDOUBLE_CLASS,mxREAL);;

	// populating output mxArray	
	btScalar* outArray=(btScalar *)mxGetData(output);
	outArray[0]=btScalar(vec.getX());
	outArray[1]=btScalar(vec.getY());
	outArray[2]=btScalar(vec.getZ());

	return output;

}