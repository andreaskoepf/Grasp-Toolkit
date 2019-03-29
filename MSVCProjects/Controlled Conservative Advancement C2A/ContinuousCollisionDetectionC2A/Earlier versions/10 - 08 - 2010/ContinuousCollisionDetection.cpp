
#include "ContinuousCollisionDetection.h"
#include "ObjectHandle.h"
#include "LinearMath/btQuickprof.h"


// global variables required by C2A
//int step = 0;
//int number_of_steps;
//int query_type = 1;
double tolerance = .05;
//PQP_REAL toc;
//int nItr;
//int NTr;

// ccd result structure field names
const char *CCDResultFieldNames[]={"ObjectA","ObjectB","TOC_TransformA","TOC_TransformB","NumContacts","CollisionFlag","TOC","QueryTime","ContactPoints",
						"TOC_JointValues","TestIndex"};
static int NumberOfCCDResultFieldNames= 11;

// contact result substructure field names
const char *ContactResultFieldNames[]={"ContactPointOnA","ContactPointOnB","ContactPointWorldOnA","ContactPointWorldOnB","ContactNormalOnA",
						"ContactNormalOnB","ContactNormalWorldOnA","ContactNormalWorldOnB","InterpenetrationDistance","CombinedFriction","FrictionModel"};
static int NumberOfContactResultFieldNames= 11;

const double sDefaultCombinedFriction = 0.5;
const char   *sDefaultFrictionModel = "PCF";


// constructor
ContinuousCollisionDetection::ContinuousCollisionDetection(const mxArray *inputStruct)
{



	//ObjectA=0;
	//ObjectB=0;

	// initializing CCD object properties
	ObjectAModel = 0;
	ObjectBModel = 0;

	mTrimeshDataObjectA = 0;
	mTrimeshDataObjectB = 0;

	mCollisionObjectA = 0;
	mCollisionObjectB = 0;

	mVertexDataObjectA = 0;
	mVertexDataObjectB = 0;

	mFacesDataObjectA = 0;
	mFacesDataObjectB = 0;

	mIsObjectASet = false;
	mIsObjectBSet = false;

	mNumIterations = 20;
	mComputeContactPoints = true;

	LocalTransformA.setIdentity();
	LocalTransformB.setIdentity();

	// creating bullet collision world
	mCollisionConfiguration = new btDefaultCollisionConfiguration();
	mCollisionDispatcher = new btCollisionDispatcher(mCollisionConfiguration);
	mBroadphaseInterface = new btDbvtBroadphase();

	mCollisionWorld = new btCollisionWorld(mCollisionDispatcher,mBroadphaseInterface,mCollisionConfiguration);

	// using gimpact
	btCollisionDispatcher *dispatcher = static_cast<btCollisionDispatcher *>(mCollisionWorld->getDispatcher());
	btGImpactCollisionAlgorithm::registerAlgorithm(dispatcher);

}

// destructor
ContinuousCollisionDetection::~ContinuousCollisionDetection()
{

	// remove collision objects

#ifdef IN_DEBUG_MODE_2
	
	mexPrintf("\nContinuousCollisionDetection::~ContinuousCollisionDetection() removing collision objects\n");

#endif

	for(int i = mCollisionWorld->getNumCollisionObjects()-1; i>=0 ; i--)
	{

		btCollisionObject *collisionObject = mCollisionWorld->getCollisionObjectArray()[i];
		mCollisionWorld->removeCollisionObject(collisionObject);

	}

	delete mCollisionWorld;
	mCollisionWorld = 0;
	delete mBroadphaseInterface;
	delete mCollisionDispatcher;
	delete mCollisionConfiguration;

#ifdef IN_DEBUG_MODE_2

	mexPrintf("ContinuousCollisionDetection::~ContinuousCollisionDetection() done removing collision objects\n");

#endif

	removeObjectBData();
	removeObjectAData();
	

#ifdef IN_DEBUG_MODE_2

	mexPrintf("ContinuousCollisionDetection::~ContinuousCollisionDetection() removed object data\n");

#endif



}

void ContinuousCollisionDetection::computeContactPoints(const mxArray *input)
{

	mComputeContactPoints = MexUtilities::mxArray_to_bool(input);

}

void ContinuousCollisionDetection::setNumIterations(const mxArray *input)
{

	mNumIterations = MexUtilities::mxArray_to_int(input);

	if(mNumIterations < 10)
	{

		mNumIterations = 10;

	}

}	

void ContinuousCollisionDetection::performCCDTest(int nargin,const mxArray *inputs[],int nargout,mxArray *output[])
{
	// initializing btTransform data array
	btTransform transformData[4];

	
	// obtaining transform data for object A
	transformData[0] = (BulletUtilities::mxArray_to_btTransform(inputs[0]))*LocalTransformA.inverse();
	transformData[1] = (BulletUtilities::mxArray_to_btTransform(inputs[1]))*LocalTransformA.inverse();


	// obtaining transform data for object B
	transformData[2] = (BulletUtilities::mxArray_to_btTransform(inputs[2]))*LocalTransformB.inverse();
	transformData[3] = (BulletUtilities::mxArray_to_btTransform(inputs[3]))*LocalTransformB.inverse();



	if((ObjectAModel==NULL) && (ObjectBModel==NULL)) // quit if both objects have not been set
	{
	output[0]=mxCreateLogicalScalar(false);

		if(nargout>1)
		{
			// -------------------------- creating return matlab structure -------------------------- 
			// designating array size
			mwSize arraySize[2];
			arraySize[0]=1;
			arraySize[1]=1;
			output[1]= mxCreateStructArray(2,arraySize,NumberOfCCDResultFieldNames,CCDResultFieldNames);
			// ----------------------- end of return matlab structure creation -----------------------
		}

			return;
	}


	// --------------------------------------------ccd setup------------------------------------------ //

	// creating return structure	
	C2A_TimeOfContactResult result;

	result.num_contact = 0;
	result.toc = 0;
	result.distance = 0;



	// performing ccd test
	//int numTest = 10;

	// hit transforms
	btTransform hitTransformA, hitTransformB;

	// collision flag
	//C2A_Result collisionFlag;
	int collisionFlag;



	// timer object use to measure time elapsed 
	btClock timer;
	timer.reset();

	// initializing collision flag
	collisionFlag = CCD_COLLISION_FREE;

	// performing CCD test	
#ifdef IN_DEBUG_MODE_2
	mexPrintf("\ncalling solveC2A\n");
#endif

	try
	{
	collisionFlag = solveC2A(transformData[0],transformData[1],transformData[2],transformData[3],hitTransformA,hitTransformB,mNumIterations,0.0f,result);
	}
	catch(exception &e)
	{

#ifdef IN_DEBUG_MODE_2

		mexPrintf("\nError when calling solveC2A, setting flag to CCD_COLLISION_FREE\n");

#endif

		collisionFlag = CCD_COLLISION_FREE;

	}

#ifdef IN_DEBUG_MODE_2
	mexPrintf("\ndone calling solveC2A\n");
#endif
	double timeElapsed = double(timer.getTimeMilliseconds())/1000.0f;

// returning boolean
	output[0]=MexUtilities::int_to_mxArray(collisionFlag);
	

	if(nargout>1) // create structure only if sufficient output arguments are provided
	{
		// -------------------------- creating return matlab structure -------------------------- 
		// designating array size
		mwSize arraySize[2];
		arraySize[0]=1;
		arraySize[1]=1;

		output[1]= mxCreateStructArray(2,&arraySize[0],NumberOfCCDResultFieldNames,CCDResultFieldNames);

		// ----------------------- end of return matlab structure creation -----------------------

		switch(collisionFlag)
		{
		case CCD_TOC_FOUND:
			{
				btTransform tocTransformA = hitTransformA;
				btTransform tocTransformB = hitTransformB;				
				

				// setting field CollisionFlag  ------------------------------------------------------ //
				mxSetFieldByNumber(output[1],0,mxGetFieldNumber(output[1],"CollisionFlag"),
					MexUtilities::int_to_mxArray(collisionFlag));

				// setting field TOC         -------------------------------------------------------- //
				mxSetFieldByNumber(output[1],0,mxGetFieldNumber(output[1],"TOC"),
					MexUtilities::double_to_mxArray(result.toc));

				// setting field TOC_TransformA  ---------------------------------------------------- //
				mxSetFieldByNumber(output[1],0,mxGetFieldNumber(output[1],"TOC_TransformA"),
					BulletUtilities::btTransform_to_mxArray((hitTransformA*=LocalTransformA)));

				// setting field TOC_TransformB  ---------------------------------------------------- //
				mxSetFieldByNumber(output[1],0,mxGetFieldNumber(output[1],"TOC_TransformB"),
					BulletUtilities::btTransform_to_mxArray((hitTransformB*=LocalTransformB)));

				// setting field QueryTime       ---------------------------------------------------- //
				mxSetFieldByNumber(output[1],0,mxGetFieldNumber(output[1],"QueryTime"),
					MexUtilities::double_to_mxArray(timeElapsed));

				CustomContactResultCallback collisionResult;
				int numContactPoints = 0;

				if(mComputeContactPoints)
				{

					numContactPoints = performContactPairTest(tocTransformA,tocTransformB,collisionResult);

					if(numContactPoints > 0)
					{

						// creating contact result structure ------------------------------------------------- //
						mwSize contactStructArraySize[2];
						contactStructArraySize[0]=1;
						contactStructArraySize[1] = mwSize(numContactPoints);
						mxArray *contactResultStruct = mxCreateStructArray(2,contactStructArraySize,NumberOfContactResultFieldNames,
							ContactResultFieldNames);

						// declaring variables used to compute relative normal and contact points
						btVector3 contactPoint, contactPointLocal, contactPointWorld, normalWorldOnB(0,0,0), normalStart, normalEnd, normal;
						
						// declaring index
						mwIndex index = 0;
						// inserting data in contact result structure

#ifdef IN_DEBUG_MODE_2

						mexPrintf("\nEntering Data in Contact Structure 1 x %i struct\n",numContactPoints);

#endif
						for(vector<btManifoldPoint*>::iterator i = collisionResult.mContactPointContainer.begin(); i != collisionResult.mContactPointContainer.end(); i++)
						{
							// retrieving current contact
							btManifoldPoint *contact = *i;


							// setting field ContactPointOnA  ----------------------------------------------------- //

							// computing contact point
							contactPoint = contact->m_localPointA;
							contactPointLocal = LocalTransformA.inverse()(contactPoint);
							contactPointWorld = hitTransformA(contactPointLocal);
							 
							mxSetFieldByNumber(contactResultStruct,index,mxGetFieldNumber(contactResultStruct,"ContactPointOnA"),
								BulletUtilities::btVector3_to_mxArray(contactPointLocal));

							// setting field ContactPointWorldOnA  ------------------------------------------------- //					 
							mxSetFieldByNumber(contactResultStruct,index,mxGetFieldNumber(contactResultStruct,"ContactPointWorldOnA"),
								BulletUtilities::btVector3_to_mxArray(contactPointWorld));


							// setting field ContactPointOnB  ----------------------------------------------------- //

							// computing contact point

							contactPoint = contact->m_localPointB;
							contactPointLocal = LocalTransformB.inverse()(contactPoint);
							contactPointWorld = hitTransformB(contactPointLocal);

							mxSetFieldByNumber(contactResultStruct,index,mxGetFieldNumber(contactResultStruct,"ContactPointOnB"),
								BulletUtilities::btVector3_to_mxArray(contactPointLocal));


							// setting field ContactPointWorldOnB  ------------------------------------------------- //					 
							mxSetFieldByNumber(contactResultStruct,index,mxGetFieldNumber(contactResultStruct,"ContactPointWorldOnB"),
								BulletUtilities::btVector3_to_mxArray(contactPointWorld));



							// setting field ContactNormalOnA  ----------------------------------------------------- //
							normalWorldOnB = contact->m_normalWorldOnB;

							normalStart = hitTransformA.inverse()(btVector3(0.f,0.f,0.f));
							normalEnd = hitTransformA.inverse()(-1.f*normalWorldOnB);

							normal = normalEnd - normalStart;
							normal.normalize();

							mxSetFieldByNumber(contactResultStruct,index,mxGetFieldNumber(contactResultStruct,"ContactNormalOnA"),
								BulletUtilities::btVector3_to_mxArray(normal));

							// setting field ContactNormalOnB  ----------------------------------------------------- //
							normalStart = hitTransformB.inverse()(btVector3(0.f,0.f,0.f));
							normalEnd = hitTransformB.inverse()(normalWorldOnB);

							normal = normalEnd - normalStart;
							normal.normalize();

							mxSetFieldByNumber(contactResultStruct,index,mxGetFieldNumber(contactResultStruct,"ContactNormalOnB"),
								BulletUtilities::btVector3_to_mxArray(normal));

							// setting field ContactNormalWorldOnA  ----------------------------------------------------- //
							mxSetFieldByNumber(contactResultStruct,index,mxGetFieldNumber(contactResultStruct,"ContactNormalWorldOnA"),
								BulletUtilities::btVector3_to_mxArray(-1.f*(normalWorldOnB.normalized())));


							// setting field ContactNormalWorldOnB  ----------------------------------------------------- //
							mxSetFieldByNumber(contactResultStruct,index,mxGetFieldNumber(contactResultStruct,"ContactNormalWorldOnB"),
								BulletUtilities::btVector3_to_mxArray(normalWorldOnB.normalized()));

							// setting field InterpenetrationDistance -------------------------------------------------- //
							mxSetFieldByNumber(contactResultStruct,index,mxGetFieldNumber(contactResultStruct,"InterpenetrationDistance"),
								MexUtilities::double_to_mxArray(contact->getDistance()));

							// setting default Combined Friction
							mxSetFieldByNumber(contactResultStruct,index,mxGetFieldNumber(contactResultStruct,"CombinedFriction"),
								MexUtilities::double_to_mxArray(sDefaultCombinedFriction));

							// setting field Friction Model
							mxSetFieldByNumber(contactResultStruct,index,mxGetFieldNumber(contactResultStruct,"FrictionModel"),
								MexUtilities::charArray_to_mxArray("PCF",3));

							index++;

						}

#ifdef IN_DEBUG_MODE_2

						mexPrintf("\nDone entering Data in Contact Structure 1 x %i struct\n",numContactPoints);

#endif

						// setting field ContactResult         -------------------------------------------------- //
						mxSetFieldByNumber(output[1],0,mxGetFieldNumber(output[1],"ContactPoints"),
								contactResultStruct);

#ifdef IN_DEBUG_MODE_2

					mexPrintf("\nContactPoints Field Set\n",numContactPoints);

#endif

					}

					collisionResult.clearAllManifoldPoints();


				}

				// setting field NumContacts  -------------------------------------------------------- //
				mxSetFieldByNumber(output[1],0,mxGetFieldNumber(output[1],"NumContacts"),
					MexUtilities::int_to_mxArray(numContactPoints));

				break;

			}
		case CCD_COLLISION_FREE:
			{
				// setting field NumContacts  -------------------------------------------------------- //
				mxSetFieldByNumber(output[1],0,mxGetFieldNumber(output[1],"NumContacts"),
					MexUtilities::int_to_mxArray(0));

				// setting field CollisionFlag  ------------------------------------------------------ //
				mxSetFieldByNumber(output[1],0,mxGetFieldNumber(output[1],"CollisionFlag"),
					MexUtilities::int_to_mxArray(collisionFlag));

				// setting field TOC         -------------------------------------------------------- //
				mxSetFieldByNumber(output[1],0,mxGetFieldNumber(output[1],"TOC"),
					MexUtilities::double_to_mxArray(1.f));

				// setting field TOC_TransformA  ---------------------------------------------------- //
				mxSetFieldByNumber(output[1],0,mxGetFieldNumber(output[1],"TOC_TransformA"),
					BulletUtilities::btTransform_to_mxArray((hitTransformA*LocalTransformA)));

				// setting field TOC_TransformB  ---------------------------------------------------- //
				mxSetFieldByNumber(output[1],0,mxGetFieldNumber(output[1],"TOC_TransformB"),
					BulletUtilities::btTransform_to_mxArray((hitTransformB*LocalTransformB)));

				// setting field QueryTime       ---------------------------------------------------- //
				mxSetFieldByNumber(output[1],0,mxGetFieldNumber(output[1],"QueryTime"),
					MexUtilities::double_to_mxArray(timeElapsed));

				break;
			}
		case CCD_COLLISION_FOUND:
			{

				// setting field NumContacts  -------------------------------------------------------- //
				mxSetFieldByNumber(output[1],0,mxGetFieldNumber(output[1],"NumContacts"),
					MexUtilities::int_to_mxArray(result.num_contact));

				// setting field CollisionFlag  ------------------------------------------------------ //
				mxSetFieldByNumber(output[1],0,mxGetFieldNumber(output[1],"CollisionFlag"),
					MexUtilities::int_to_mxArray(collisionFlag));

				// setting field TOC         -------------------------------------------------------- //
				mxSetFieldByNumber(output[1],0,mxGetFieldNumber(output[1],"TOC"),
					MexUtilities::double_to_mxArray(0.f));

				// setting field TOC_TransformA  ---------------------------------------------------- //
				mxSetFieldByNumber(output[1],0,mxGetFieldNumber(output[1],"TOC_TransformA"),
					BulletUtilities::btTransform_to_mxArray((hitTransformA*LocalTransformA)));

				// setting field TOC_TransformB  ---------------------------------------------------- //
				mxSetFieldByNumber(output[1],0,mxGetFieldNumber(output[1],"TOC_TransformB"),
					BulletUtilities::btTransform_to_mxArray((hitTransformB*LocalTransformB)));

				// setting field QueryTime       ---------------------------------------------------- //
				mxSetFieldByNumber(output[1],0,mxGetFieldNumber(output[1],"QueryTime"),
					MexUtilities::double_to_mxArray(timeElapsed));

				break;
			}
		}
	}

}



void ContinuousCollisionDetection::setObjectA(int nargin,const mxArray *inputs[])
{
	//ObjectA=Solid::get_object_pointer(inputs[START_OF_INPUT_DATA_INDEX]);

#ifdef IN_DEBUG_MODE
	mexPrintf("\ncalling ContinuousCollisionDetection::setObjectA %i arguments\n",nargin);

	if(mxIsStruct(inputs[START_OF_INPUT_DATA_INDEX]))
	{

		mexPrintf("input array is struct with %i fields\n",mxGetNumberOfFields(inputs[START_OF_INPUT_DATA_INDEX]));

	}
	else
	{

		mexPrintf("input array is not struct");

	}
#endif

	if(nargin>START_OF_INPUT_DATA_INDEX+1)
	{

		LocalTransformA = BulletUtilities::mxArray_to_btTransform(inputs[START_OF_INPUT_DATA_INDEX+1]);
	}
	else
	{
		LocalTransformA.setIdentity();
	}
	
	// if an object already exists the delete it
	removeObjectAData();

		// creating transform that will be used to shift all vertices to a user define reference frame
	btTransform &toNewFrameTransform = LocalTransformA;


	// obtaining mesh data
#ifdef IN_DEBUG_MODE
	mexPrintf("\nContinuousCollisionDetection::setObjectB extracting vertex data\n");
#endif
	double *vertices = NULL;
	vertices = MexUtilities::mxArray_to_double_array(inputs[START_OF_INPUT_DATA_INDEX],0,"vertices",APPEND_ROW_WISE);

#ifdef IN_DEBUG_MODE
	mexPrintf("\nContinuousCollisionDetection::setObjectB extracting faces data\n");
#endif
	int *faces = MexUtilities::mxArray_to_int_array(inputs[START_OF_INPUT_DATA_INDEX],0,"faces",APPEND_ROW_WISE);

#ifdef IN_DEBUG_MODE
	mexPrintf("\nContinuousCollisionDetection::setObjectB extracting size\n");
#endif
	// obtaining mesh size
	int numFaces = MexUtilities::mxArray_row_size(inputs[START_OF_INPUT_DATA_INDEX],0,"faces");
	int numVertices = MexUtilities::mxArray_row_size(inputs[START_OF_INPUT_DATA_INDEX],0,"vertices");

	// declaring vectors that contains original and transformed vertices
	btVector3 origVertex, newVertex;
	//newVertex = new btVector3[solid->NumVertices];
#ifdef IN_DEBUG_MODE
	mexPrintf("\nContinuousCollisionDetection::setObjectB transforming vertex data\n");
#endif

	for(int i = 0; i < numVertices ; i++)
	{
		origVertex.setValue(vertices[3*i],vertices[3*i+1],vertices[3*i+2]);
		newVertex = toNewFrameTransform(origVertex);
		vertices[3*i] = newVertex.getX();
		vertices[3*i+1] = newVertex.getY();
		vertices[3*i+2] = newVertex.getZ();

	}

#ifdef IN_DEBUG_MODE
	mexPrintf("\nContinuousCollisionDetection::setObjectB substracting 1 from each element in faces array\n");
#endif
	for(int i = 0;i<numFaces;i++)
	{
		faces[3*i] = faces[3*i]-1;	// c arrays are zero based
		faces[3*i+1] = faces[3*i+1]-1;
		faces[3*i+2] = faces[3*i+2]-1;

	}



	ObjectAModel = C2AUtilities::create_C2A_Model(vertices,faces,numVertices,numFaces);

	mTrimeshDataObjectA = BulletUtilities::createTriangleIndexVertexArray(vertices,faces,numVertices,numFaces);

	btGImpactMeshShape *gimpactShape = new btGImpactMeshShape(mTrimeshDataObjectA);
	gimpactShape->updateBound();

	mCollisionObjectA = new btCollisionObject();
	mCollisionObjectA->setCollisionShape(gimpactShape);

	mVertexDataObjectA = vertices;
	mFacesDataObjectA = faces;

	mCollisionWorld->addCollisionObject(mCollisionObjectA);

	mIsObjectASet = true;
	
}

void ContinuousCollisionDetection::setObjectB(int nargin,const mxArray *inputs[])
{
	//ObjectB=Solid::get_object_pointer(inputs[START_OF_INPUT_DATA_INDEX]);

	// if an offset transform was passed then store it, otherwise use identity matrix
	if(nargin>START_OF_INPUT_DATA_INDEX+1)
	{
		LocalTransformB = BulletUtilities::mxArray_to_btTransform(inputs[START_OF_INPUT_DATA_INDEX+1]);
	}
	else
	{
		LocalTransformB.setIdentity();
	}

	// if an object already exists the delete it
	removeObjectBData();

		// creating transform that will be used to shift all vertices to a user define reference frame
	btTransform &toNewFrameTransform = LocalTransformB;


	// obtaining mesh data
#ifdef IN_DEBUG_MODE
	mexPrintf("\nContinuousCollisionDetection::setObjectB extracting vertex data\n");
#endif
	double *vertices = NULL;
	vertices = MexUtilities::mxArray_to_double_array(inputs[START_OF_INPUT_DATA_INDEX],0,"vertices",APPEND_ROW_WISE);

#ifdef IN_DEBUG_MODE
	mexPrintf("\nContinuousCollisionDetection::setObjectB extracting faces data\n");
#endif
	int *faces = MexUtilities::mxArray_to_int_array(inputs[START_OF_INPUT_DATA_INDEX],0,"faces",APPEND_ROW_WISE);

#ifdef IN_DEBUG_MODE
	mexPrintf("\nContinuousCollisionDetection::setObjectB extracting size\n");
#endif
	// obtaining mesh size
	int numFaces = MexUtilities::mxArray_row_size(inputs[START_OF_INPUT_DATA_INDEX],0,"faces");
	int numVertices = MexUtilities::mxArray_row_size(inputs[START_OF_INPUT_DATA_INDEX],0,"vertices");

	// declaring vectors that contains original and transformed vertices
	btVector3 origVertex, newVertex;
	//newVertex = new btVector3[solid->NumVertices];
#ifdef IN_DEBUG_MODE
	mexPrintf("\nContinuousCollisionDetection::setObjectB transforming vertex data\n");
#endif

	for(int i = 0; i < numVertices ; i++)
	{
		origVertex.setValue(vertices[3*i],vertices[3*i+1],vertices[3*i+2]);
		newVertex = toNewFrameTransform(origVertex);
		vertices[3*i] = newVertex.getX();
		vertices[3*i+1] = newVertex.getY();
		vertices[3*i+2] = newVertex.getZ();

	}

#ifdef IN_DEBUG_MODE
	mexPrintf("\nContinuousCollisionDetection::setObjectB substracting 1 from each element in faces array\n");
#endif
	for(int i = 0;i<numFaces;i++)
	{
		faces[3*i] = faces[3*i]-1;	// c arrays are zero based
		faces[3*i+1] = faces[3*i+1]-1;
		faces[3*i+2] = faces[3*i+2]-1;

	}



	ObjectBModel = C2AUtilities::create_C2A_Model(vertices,faces,numVertices,numFaces);

	mTrimeshDataObjectB = BulletUtilities::createTriangleIndexVertexArray(vertices,faces,numVertices,numFaces);

	btGImpactMeshShape *gimpactShape = new btGImpactMeshShape(mTrimeshDataObjectB);
	gimpactShape->updateBound();

	mCollisionObjectB = new btCollisionObject();
	mCollisionObjectB->setCollisionShape(gimpactShape);

	mVertexDataObjectB = vertices;
	mFacesDataObjectB = faces;

	mCollisionWorld->addCollisionObject(mCollisionObjectB);

	mIsObjectBSet = true;

}

void ContinuousCollisionDetection::removeObjectAData()
{

	if(mIsObjectASet)
	{

		
		if(mCollisionWorld != NULL)
		{

			mCollisionWorld->removeCollisionObject(mCollisionObjectA);

		}

#ifdef IN_DEBUG_MODE_2

		mexPrintf("\nContinuousCollisionDetection::removeObjectAData() removing C2A_Model Object\n");

#endif

		delete ObjectAModel;
		ObjectAModel = 0;		

#ifdef IN_DEBUG_MODE_2

		mexPrintf("\nContinuousCollisionDetection::removeObjectAData() removing btCollisionShape Object\n");

#endif
		btCollisionShape* shape = mCollisionObjectA->getCollisionShape();
		delete shape;

#ifdef IN_DEBUG_MODE_2

		mexPrintf("\nContinuousCollisionDetection::removeObjectAData() removing btCollisionObject Object\n");

#endif
		delete mCollisionObjectA;
		mCollisionObjectA = 0;

#ifdef IN_DEBUG_MODE_2

		mexPrintf("\nContinuousCollisionDetection::removeObjectAData() removing trimeshData Object\n");

#endif
		delete mTrimeshDataObjectA;
		mTrimeshDataObjectA = 0;


#ifdef IN_DEBUG_MODE_2

		mexPrintf("\nContinuousCollisionDetection::removeObjectAData() removing vertices Array\n");

#endif
		delete[] mVertexDataObjectA;
		mVertexDataObjectA = 0;		

#ifdef IN_DEBUG_MODE_2

		mexPrintf("\nContinuousCollisionDetection::removeObjectAData() removing faces Array\n");

#endif
		delete[] mFacesDataObjectA;
		mFacesDataObjectA = 0;

#ifdef IN_DEBUG_MODE_2

		mexPrintf("\nContinuousCollisionDetection::removeObjectAData() done removing ObjectA Data \n");

#endif

		mIsObjectASet = false;

	}

}

void ContinuousCollisionDetection::removeObjectBData()
{

	if(mIsObjectBSet)
	{

		if(mCollisionWorld != NULL)
		{

			mCollisionWorld->removeCollisionObject(mCollisionObjectB);

		}

#ifdef IN_DEBUG_MODE_2

		mexPrintf("\nContinuousCollisionDetection::removeObjectBData() removing C2A_Model Object\n");

#endif

		delete ObjectBModel;
		ObjectBModel = 0;		

#ifdef IN_DEBUG_MODE_2

		mexPrintf("\nContinuousCollisionDetection::removeObjectBData() removing btCollisionShape Object\n");

#endif

		btCollisionShape* shape = mCollisionObjectB->getCollisionShape();
		delete shape;

#ifdef IN_DEBUG_MODE_2

		mexPrintf("\nContinuousCollisionDetection::removeObjectBData() removing btCollisionObject Object\n");

#endif

		delete mCollisionObjectB;
		mCollisionObjectB = 0;

#ifdef IN_DEBUG_MODE_2

		mexPrintf("\nContinuousCollisionDetection::removeObjectBData() removing trimeshData Object\n");

#endif

		delete mTrimeshDataObjectB;
		mTrimeshDataObjectB = 0;

#ifdef IN_DEBUG_MODE_2

		mexPrintf("\nContinuousCollisionDetection::removeObjectBData() removing vertices Array\n");

#endif

		delete[] mVertexDataObjectB;
		mVertexDataObjectB = 0;		

#ifdef IN_DEBUG_MODE_2

		mexPrintf("\nContinuousCollisionDetection::removeObjectBData() removing faces Array\n");

#endif

		delete[] mFacesDataObjectB;
		mFacesDataObjectB = 0;

#ifdef IN_DEBUG_MODE_2

		mexPrintf("\nContinuousCollisionDetection::removeObjectBData() done removing ObjectB Data \n");

#endif

		mIsObjectBSet = false;

	}

}



int ContinuousCollisionDetection::performContactPairTest(btTransform &objectATransform, btTransform &objectBTransform, CustomContactResultCallback &resultCallback)
{

#ifdef IN_DEBUG_MODE_2

	mexPrintf("ContinuosCollisionDetection::performContactPairTest() performing contact pair test");

#endif

	mCollisionObjectA->setWorldTransform(objectATransform);
	mCollisionObjectB->setWorldTransform(objectBTransform);

	mCollisionWorld->contactPairTest(mCollisionObjectA,mCollisionObjectB,resultCallback);

#ifdef IN_DEBUG_MODE_2

	mexPrintf("ContinuosCollisionDetection::performContactPairTest() done performing contact pair test");

#endif

	return resultCallback.mNumOfContactPoints;

}

int ContinuousCollisionDetection::solveC2A(const btTransform &objectATransform0,const btTransform &objectATransformf,const btTransform &objectBTransform0
		,const btTransform &objectBTransformf,btTransform &objectATransformTOC,btTransform &objectBTransformTOC,int &number_of_iterations,
		PQP_REAL th_ca,C2A_TimeOfContactResult &dres)
{


	// the following procedure changes the orientation of both objects such that the rotation that results between the final and initial transforms of 
	// object A is equivalent to a rotation about the z axis by the corresponding angle.  This is done to account for the problem that causes the collision
	// detection to fail whenever rotations are performed about an arbitrary axis besides the z axis.

	// obtaining rotation matrix between transform0 to transformf of object A
	btTransform rot_02f = objectATransform0.inverse()*objectATransformf;
	rot_02f.setOrigin(btVector3(0.f,0.f,0.f));

	// obtaining angle and axis
	btScalar  theta = rot_02f.getRotation().getAngle();

	// creating corresponding rotation matrix about the z axis
	btTransform rot_02f_world(btQuaternion(btVector3(0.f,0.f,1.f),theta));

	// computing new world transform
	btTransform worldTransform = rot_02f_world*((objectATransform0*rot_02f).inverse());

	// creating new relative transformation matrices for both objects
	btTransform objectATransform0New = worldTransform*objectATransform0;
	btTransform objectATransformfNew = worldTransform*objectATransformf;
	btTransform objectBTransform0New = worldTransform*objectBTransform0;
	btTransform objectBTransformfNew = worldTransform*objectBTransformf;



	// this method needs to be modified in order to terminate the calculation whenever the collision exists at the initial configuration.
		double lamda = 0.0, lastLamda=-1.0, dlamda=0.0;

		PQP_REAL t_delta = 0.0001;
		PQP_REAL d_delta = 0.001*ObjectAModel->radius;

		// returned collision flag
		//C2A_Result collisionFlag;
		int collisionFlag;

		// checking if there exists a collision at the initial configuration

		PQP_CollideResult res_col;// = PQP_CollideResult();
		PQP_REAL R1[3][3], T1[3], R2[3][3], T2[3];

		C2AUtilities::btTransform_to_PQP(objectATransform0,R1,T1);
		C2AUtilities::btTransform_to_PQP(objectBTransform0,R2,T2);
	
		// try using the new transforms instead and also the PQP_Distance function to check for closest distance
		PQP_Collide(&res_col, R1, T1, ObjectAModel,
			R2,T2,ObjectBModel, 2);

		if(res_col.num_pairs>0)
		{
			//printf("collision at time 0");
			dres.collisionfree = false;
			dres.toc = PQP_REAL(0.f);
			dres.num_contact = res_col.NumPairs();

			//return CollisionNotFound;//collision at time 0.0
			objectATransformTOC = btTransform(objectATransform0);
			objectBTransformTOC = btTransform(objectBTransform0);
			collisionFlag = C2A_Result::CollisionFound; // collision found at time 0


		}
		else
		{

#ifdef IN_DEBUG_MODE_2
				mexPrintf("\nContinuousCollisionDetection::solveC2A iterating C2AQueryTimeOfContact\n");
#endif		
			for(int i=0;i<number_of_iterations;i++)
			{

				CInterpMotion_Linear *motionA = C2AUtilities::create_C2A_CInterpMotion_Linear(objectATransform0New,objectATransformfNew,t_delta,d_delta);
				CInterpMotion_Linear *motionB = C2AUtilities::create_C2A_CInterpMotion_Linear(objectBTransform0New,objectBTransformfNew,t_delta,d_delta);

				d_delta = 0.001*ObjectAModel->radius;

				motionA->m_toc_delta = d_delta;
				motionB->m_toc_delta = d_delta;


				// calculating toc


				C2A_QueryTimeOfContact(motionA,motionB,&dres,ObjectAModel,ObjectBModel,motionA->m_toc_delta,t_delta,0);



				dres.cont_l.clear();

				delete motionA;
				delete motionB;
			}


#ifdef IN_DEBUG_MODE_2
				mexPrintf("\nContinuousCollisionDetection::solveC2A done iterating C2AQueryTimeOfContact\n");
#endif

			if(!dres.collisionfree)
			{


				if(dres.toc == 0.f)
				{
					objectATransformTOC = btTransform(objectATransform0);
					objectBTransformTOC = btTransform(objectBTransform0);
					collisionFlag = C2A_Result::CollisionFound;
				}
				else
				{
					
					// compute transforms at toc

					CInterpMotion_Linear *motionA = C2AUtilities::create_C2A_CInterpMotion_Linear(objectATransform0,objectATransformf,t_delta,d_delta);
						CInterpMotion_Linear *motionB = C2AUtilities::create_C2A_CInterpMotion_Linear(objectBTransform0,objectBTransformf,t_delta,d_delta);

					// time of collision found

					
					PQP_REAL qua[7];
					motionA->integrate(dres.toc,qua);
					objectATransformTOC.setRotation(btQuaternion(qua[1],qua[2],qua[3],qua[0]));
					objectATransformTOC.setOrigin(btVector3(qua[4],qua[5],qua[6]));

					motionB->integrate(dres.toc,qua);
					objectBTransformTOC.setRotation(btQuaternion(qua[1],qua[2],qua[3],qua[0]));
					objectBTransformTOC.setOrigin(btVector3(qua[4],qua[5],qua[6]));

					delete motionA;
					delete motionB;

					collisionFlag =  C2A_Result::TOCFound;
					
					/*
					if(mComputeContactPoints)
					{
						CInterpMotion_Linear *motionA = C2AUtilities::create_C2A_CInterpMotion_Linear(objectATransform0,objectATransformf,t_delta,d_delta);
						CInterpMotion_Linear *motionB = C2AUtilities::create_C2A_CInterpMotion_Linear(objectBTransform0,objectBTransformf,t_delta,d_delta);

						// time of collision found

						
						PQP_REAL qua[7];
						motionA->integrate(dres.toc,qua);
						objectATransformTOC.setRotation(btQuaternion(qua[1],qua[2],qua[3],qua[0]));
						objectATransformTOC.setOrigin(btVector3(qua[4],qua[5],qua[6]));

						motionB->integrate(dres.toc,qua);
						objectBTransformTOC.setRotation(btQuaternion(qua[1],qua[2],qua[3],qua[0]));
						objectBTransformTOC.setOrigin(btVector3(qua[4],qua[5],qua[6]));

						Transform trans0, trans1;

						C2AUtilities::btTransform_to_Transform(objectATransformTOC,trans0);
						C2AUtilities::btTransform_to_Transform(objectBTransformTOC,trans1);



						double threshold = 2*dres.distance+0.001 + th_ca;

#ifdef IN_DEBUG_MODE_2
					mexPrintf("\nContinuousCollisionDetection::solveC2A calling C2AQueryContact with threshold %1.3f and toc = %1.3f\n",threshold,dres.toc);
#endif

					C2A_QueryContact(motionA,motionB,&dres,ObjectAModel,ObjectBModel,threshold);

#ifdef IN_DEBUG_MODE_2
					mexPrintf("\nContinuousCollisionDetection::solveC2A calling Contact_normal_new\n");
#endif

					Contact_normal_new(&dres,ObjectAModel,ObjectBModel,trans0,trans1);//changed in 6.10

#ifdef IN_DEBUG_MODE_2
					mexPrintf("\nContinuousCollisionDetection::solveC2A done calling Contact_normal_new\n");
#endif
					

						delete motionA;
						delete motionB;

					}
					*/

				}

			}				
			else
			{
				
				objectATransformTOC = btTransform(objectATransform0);
				objectBTransformTOC = btTransform(objectBTransform0);
								
				collisionFlag = C2A_Result::CollisionFree; // no collision occurs
			}

				

			

		}

		return ContinuousCollisionDetection::convertC2ACollisionFlag(C2A_Result(collisionFlag));		


}


CCDCollisionFlags ContinuousCollisionDetection::convertC2ACollisionFlag(C2A_Result flag)
{

	switch(flag)
	{
	case TOCFound:

		return CCD_TOC_FOUND;
		break;

	case CollisionFound:

		return CCD_COLLISION_FOUND;
		break;

	case CollisionFree:

		return CCD_COLLISION_FREE;
		break;

	default:

		return CCD_COLLISION_FREE;
		break;

	}

}


CustomContactResultCallback::CustomContactResultCallback()
{

	mNumOfContactPoints = 0;
	
}

void CustomContactResultCallback::clearAllManifoldPoints()
{

	if(mNumOfContactPoints == 0)
	{
		
		return;

	}

	for(vector< btManifoldPoint* >::iterator i = mContactPointContainer.begin(); i != mContactPointContainer.end(); i++)
	{

		btManifoldPoint* manifoldPoint = *i;

		delete manifoldPoint;

	}

	mContactPointContainer.clear();

	mNumOfContactPoints = 0;

}

btScalar CustomContactResultCallback::addSingleResult(btManifoldPoint &cp, const btCollisionObject *colObj0, int partId0, int index0, const btCollisionObject *colObj2, int partId1, int index1)
{

	btManifoldPoint *contactPoint = new btManifoldPoint();

	// copying content of passed manifold point
	contactPoint->m_appliedImpulse=cp.m_appliedImpulse;
	contactPoint->m_appliedImpulseLateral1=cp.m_appliedImpulseLateral1;
	contactPoint->m_appliedImpulseLateral2=cp.m_appliedImpulseLateral2;
	contactPoint->m_combinedFriction=cp.m_combinedFriction;
	contactPoint->m_combinedRestitution=cp.m_combinedRestitution;
	contactPoint->m_contactCFM1=cp.m_contactCFM1;
	contactPoint->m_contactCFM2=cp.m_contactCFM2;
	contactPoint->m_contactMotion1=cp.m_contactMotion1;
	contactPoint->m_contactMotion2=cp.m_contactMotion2;
	contactPoint->m_distance1=cp.m_distance1;
	contactPoint->m_index0=cp.m_index0;
	contactPoint->m_index1=cp.m_index1;
	contactPoint->m_lateralFrictionDir1=cp.m_lateralFrictionDir1;
	contactPoint->m_lateralFrictionDir2=cp.m_lateralFrictionDir2;
	contactPoint->m_lateralFrictionInitialized=cp.m_lateralFrictionInitialized;
	contactPoint->m_lifeTime=cp.m_lifeTime;
	contactPoint->m_localPointA=cp.m_localPointA;
	contactPoint->m_localPointB=cp.m_localPointB;
	contactPoint->m_normalWorldOnB=cp.m_normalWorldOnB;
	contactPoint->m_partId0=cp.m_partId0;
	contactPoint->m_partId1=cp.m_partId1;
	contactPoint->m_positionWorldOnA=cp.m_positionWorldOnA;
	contactPoint->m_positionWorldOnB=cp.m_positionWorldOnB;
	contactPoint->m_userPersistentData=cp.m_userPersistentData;

	mContactPointContainer.push_back(contactPoint);

	mNumOfContactPoints++;

	return btScalar(mNumOfContactPoints);

}

CustomContactResultCallback::~CustomContactResultCallback()
{

	clearAllManifoldPoints();

}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// helper methods
void ContinuousCollisionDetection::printMethodCallDetails(const string &methodName,int methodIndex)
{

	mexPrintf("Class\t\t\t:\t%s\n","ContinuousCollisionDetection");
	mexPrintf("Method Call\t\t:\t%s\n",methodName.c_str());
	mexPrintf("Method Index\t:\t%i\n",methodIndex);

	return;
}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Handle manipulation functions
void ContinuousCollisionDetection::create_handle(int nargin,const mxArray *inputs[],mxArray **output)
{
	
	
	
	ContinuousCollisionDetection *ccd= new ContinuousCollisionDetection(inputs[CONSTRUCTION_DATA_INDEX]);
	//mexPrintf("Created pointer to Solid Object, pointer value= %#x, \n",solid);
	ObjectHandle<ContinuousCollisionDetection> *handle = new ObjectHandle<ContinuousCollisionDetection>(ccd);
	
	*output=handle->to_mex_handle();


}

// -------------------------------------------------------------------------------------------- //
void ContinuousCollisionDetection::destroy_handle(const mxArray *handle) // handle=prhs[2]
{
	destroy_object<ContinuousCollisionDetection>(handle);
}

// -------------------------------------------------------------------------------------------- //
ContinuousCollisionDetection* ContinuousCollisionDetection::get_object_pointer(const mxArray *handle)
{
	ContinuousCollisionDetection &ccd=get_object<ContinuousCollisionDetection>(handle);
	return &ccd;
}

// -------------------------------------------------------------------------------------------- //
void ContinuousCollisionDetection::method_selector(int nargin,const mxArray *inputs[],int nargout,mxArray *outputs[])
{
	// declaring CCD Pointer
	static ContinuousCollisionDetection *ccdPointer;
	
	
	
	// checking that the method identifier index is of an integer data type
	if(!mxIsInt8(inputs[METHOD_IDENTIFIER_INDEX])&&!mxIsInt16(inputs[METHOD_IDENTIFIER_INDEX])&&!mxIsInt32(inputs[METHOD_IDENTIFIER_INDEX])&&!mxIsInt64(inputs[METHOD_IDENTIFIER_INDEX]))
	{
		mexErrMsgTxt("must pass a integer data type for the method identifier index\n");
		return;
	}

	// getting an int pointer to the method identifier index
	int *function_index=(int *)mxGetData(inputs[METHOD_IDENTIFIER_INDEX]);

	// obtaining the pointer to the SimplePhysicsEnvironment object
	if(*function_index!=CCD_CONSTRUCTOR)
	{
			ccdPointer=ContinuousCollisionDetection::get_object_pointer(inputs[HANDLE_IDENTIFIER_INDEX]);
			
	}


	// selecting method
	switch (*function_index)
	{
	case CCD_CONSTRUCTOR:


#ifdef IN_DEBUG_MODE_LEVEL_2

		ContinuousCollisionDetection::printMethodCallDetails("Constructor",CCD_CONSTRUCTOR);		
		mexPrintf("------------------------------------------------------------\n");    	
		mexPrintf("Start of \"Constructor\" method call\n\n");
#endif		
		//
		ContinuousCollisionDetection::create_handle(nargin,inputs,&outputs[0]);


#ifdef IN_DEBUG_MODE_LEVEL_2
		mexPrintf("\nEnd of \"Constructor\" method call\n");
		mexPrintf("------------------------------------------------------------\n");   
#endif

		
		break;


	case CCD_SETOBJECTA:

#ifdef IN_DEBUG_MODE_LEVEL_2
		
		ContinuousCollisionDetection::printMethodCallDetails("setObjectA()",CCD_SETOBJECTA);

#endif

		ccdPointer->setObjectA(nargin,inputs);


		break;


	case CCD_SETOBJECTB:

#ifdef IN_DEBUG_MODE_LEVEL_2
		
		ContinuousCollisionDetection::printMethodCallDetails("setObjectB()",CCD_SETOBJECTB);

#endif
		
		
		ccdPointer->setObjectB(nargin,inputs);
		

		break;

	case CCD_PERFORMCCDTEST:

#ifdef IN_DEBUG_MODE_LEVEL_2
		
		ContinuousCollisionDetection::printMethodCallDetails("performCCDTest()",CCD_PERFORMCCDTEST);

#endif

		ccdPointer->performCCDTest(nargin,inputs+START_OF_INPUT_DATA_INDEX,nargout,outputs);

		break;

	case CCD_SETNUMITERATIONS:

#ifdef IN_DEBUG_MODE_LEVEL_2
		
		ContinuousCollisionDetection::printMethodCallDetails("setNumIterations()",CCD_SETNUMITERATIONS);

#endif

		//ccdPointer->performCCDTest(nargin,inputs+START_OF_INPUT_DATA_INDEX,nargout,outputs);
		ccdPointer->setNumIterations(inputs[START_OF_INPUT_DATA_INDEX]);

		break;

	case CCD_COMPUTECONTACTPOINTS:

#ifdef IN_DEBUG_MODE_LEVEL_2
		
		ContinuousCollisionDetection::printMethodCallDetails("computeContactPoints)",CCD_COMPUTECONTACTPOINTS);

#endif

		//ccdPointer->setNumIterations(inputs+START_OF_INPUT_DATA_INDEX);
		ccdPointer->computeContactPoints(inputs[START_OF_INPUT_DATA_INDEX]);

		break;



		case CCD_DESTRUCTOR:

#ifdef IN_DEBUG_MODE_LEVEL_2
		
		ContinuousCollisionDetection:printMethodCallDetails("Destructor",CCD_DESTRUCTOR);
		mexPrintf("------------------------------------------------------------\n");    	
		mexPrintf("Start of \"Destructor\" method call\n\n");

#endif

		// deletes the handle and the solid object to which the handle is associated with
		ContinuousCollisionDetection::destroy_handle(inputs[HANDLE_IDENTIFIER_INDEX]);

#ifdef IN_DEBUG_MODE_LEVEL_2

		mexPrintf("\nEnd of \"Destructor\" method call\n");
		mexPrintf("------------------------------------------------------------\n");

#endif

		break;



	default:

		mexWarnMsgTxt("Undefined function index identifier, no action was taken");
		break;


	}

	return;


}

