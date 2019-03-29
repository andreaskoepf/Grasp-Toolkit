#ifndef MEXUTILITIES_H
#define MEXUTILITIES_H

#include "mexFunction.h"
#include "btBulletDynamicsCommon.h"

class MexUtilities
{
public:

		// -------------------------------------------------------------------------------------------- //
		// -------------------------------------------------------------------------------------------- //
		// Methods for indirect data extraction from fields of object or structure inputs

			// extract data from objects or structure properties passed as arguments
			static btVector3 mxArray_to_btVector3(const mxArray* inputStruct,mwIndex index,const char propName[]);
			static btVector4 mxArray_to_btVector4(const mxArray* inputStruct,mwIndex index,const char propName[]);
			static btQuaternion mxArray_to_btQuaternion(const mxArray* inputStruct,mwIndex index,const char propName[]);
			static btScalar mxArray_to_btScalar(const mxArray* inputStruct,mwIndex index,const char propName[]);
			static int mxArray_to_int(const mxArray* inputStruct,mwIndex index,const char propName[]);
			static btScalar* mxArray_to_btScalarArray1D(const mxArray *inputStruct,mwIndex index,const char propName[]);
			static btScalar* mxArray_to_btScalarArray2D(const mxArray *inputStruct,mwIndex index,const char propName[]);
			
			// extracts triangulation data from an object or structure from the vertices and faces data stored in the
			// fields indicated by the const char arguments verticesPropName and facesPropName respectively.
			static btTriangleIndexVertexArray* mxArray_to_btTriangleIndexVertexArray(const mxArray *inputStruct,mwIndex index,const char verticesPropName[],
																					const char facesPropName[]);
																					
			// extracts triangulation data from an object or structure from the vertices and faces data stored in the
			// fields under "Vertices" and "Faces".  In this method the field names are assumed to be "Vertices" and "Faces".															
			static btTriangleIndexVertexArray* mxArray_to_btTriangleIndexVertexArray(const mxArray *inputStruct,mwIndex index);																		

			// used to extract faces array by the Solid class.  This method assumes that the field name corresponding to the
			// location of the Face data is "Faces"
			static int* mxArray_to_int_array(const mxArray *inputStruct,mwIndex index); 
			
			// used to extract faces array (triangulation data) in a given Matlab class or Matlab struct.  This method uses the name passed in the facesPropName argument
			// to locate the Face data.
			static int* mxArray_to_int_array(const mxArray *inputStruct,mwIndex index,const char facesPropName[]); 

			// used to extract the number of faces by the Solid class.  Assumes that the array is stored under the field name "Faces"
			static int mxArray_row_size(const mxArray *inputStruct,mwIndex index);
			
			// extracts the row size of an array stored in a structure of object under the object property or field name 
			// indicated by propName
			static int mxArray_row_size(const mxArray *inputStruct,mwIndex index,const char propName[]);		
	        
	        
	        
			// used to extract vertices array by the Solid class.     This method assumes that the field name corresponding to the
			static btScalar* mxArray_to_float_array(const mxArray *inputStruct,mwIndex index); 
			
			// used to extract vertices array (triangulation data) in a given Matlab class or Matlab struct.  This method uses the name passed in the verticesPropName argument
			// to locate the Vertices data.
			static btScalar* mxArray_to_float_array(const mxArray *inputStruct,mwIndex index,const char verticesPropName[]);		
			

			// used to extract number of vertices by the Solid class.  Assumes that the array is stored under the field name "Vertices"        
			static int mxArray_column_size(const mxArray *inputStruct,mwIndex index);
			 
			// extracts the column size of an array stored in a structure of object under the object property or field name 
			// indicated by propName   
			static int mxArray_column_size(const mxArray *inputStruct,mwIndex index,const char propName[]);

		// -------------------------------------------------------------------------------------------- //
		// -------------------------------------------------------------------------------------------- //
		// Methods for direct data extraction from inputs 
		
			// extract data directly from arguments, the input mxArray must be of the appropiate type and size
			static int mxArray_to_int(const mxArray* input);

			// extracts data from a 4 x 4 array and places it in a btTransform object
			static btTransform mxArray_to_btTransform(const mxArray* input);

		// -------------------------------------------------------------------------------------------- //
		// -------------------------------------------------------------------------------------------- //
		// Methods to extract data from c++ ,c and bullet data types and populate mxArray types

			// places integer value in mxArray
			static mxArray* int_to_mxArray(const int &val);

			static mxArray* bool_to_mxArray(bool boolean);

			static mxArray* intArray_to_mxArray(const int *val,mwSize size,bool isRowVector = true);

			static mxArray* btTransform_to_mxArray(const btTransform &transform);

			static mxArray* btVector3_to_mxArray(const btVector3 &vec);

			static mxArray* btVector3_to_mxArray(const btVector3 &vec,bool isRowVector);

			static mxArray* btScalar_to_mxArray(const btScalar &val);

			static mxArray* btScalarArray_to_mxArray(const btScalar *val,mwSize size,bool isRowVector = true);

			static mxArray* charArray_to_mxArray(const char *val,mwSize size,bool isRowVector = true);

		
		// -------------------------------------------------------------------------------------------- //
		// -------------------------------------------------------------------------------------------- //
		// Methods to print data on the Matlab command window

			static void print_btTransform(const btTransform &transform);
		





};

#endif
