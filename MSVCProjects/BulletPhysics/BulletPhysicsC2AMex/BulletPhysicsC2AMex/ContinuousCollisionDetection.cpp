
#include "ContinuousCollisionDetection.h"
#include "ObjectHandle.h"

// global variables required by C2A
int step = 0;
int number_of_steps;
int query_type = 1;
double tolerance = .05;
PQP_REAL toc;
int nItr;
int NTr;
//

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

// -------------------------------------------------------------------------------------------- //
// solver interface
//static btVoronoiSimplexSolver VoronoiSimplexSolver;

// constructor
ContinuousCollisionDetection::ContinuousCollisionDetection(const mxArray *obj)
{

#ifdef IN_DEBUG_MODE_LEVEL_2
	mexPrintf("\n\n------------------------------------------------------------");
	mexPrintf("\n---------ContinuousCollisionDetection Construction----------");
	mexPrintf("\n------------------------------------------------------------\n");
#endif
	// initializing solver interface
	//SimplexSolverInterface = &VoronoiSimplexSolver;

#ifdef IN_DEBUG_MODE_LEVEL_2
	mexPrintf("\n\tInitialized Simplex SolverInterface");
#endif

	//PenetrationDepthSolver = 0;

#ifdef IN_DEBUG_MODE_LEVEL_2
	mexPrintf("\n\tInitialized pointer to ConvexPenetrationDepthSolver to NULL");
#endif

#ifdef IN_DEBUG_MODE_LEVEL_2
	mexPrintf("\n\tInitializing C2A_Model pointers to NULL\n");
#endif

	ObjectA=0;
	ObjectB=0;
	ObjectAModel = 0;
	ObjectBModel = 0;

	LocalTransformA.setIdentity();
	LocalTransformB.setIdentity();
	//CCDCaster = 0;

#ifdef IN_DEBUG_MODE_LEVEL_2
	mexPrintf("\n\n------------------------------------------------------------");
	mexPrintf("\n---End Of ContinuousCollisionDetection Object Construction--");
	mexPrintf("\n------------------------------------------------------------\n");
#endif

#ifdef IN_DEBUG_MODE_LEVEL_1
	
	mexPrintf("\n\tContinuousCollisionDetection mex object Successfully created\n");

#endif

}

// destructor
ContinuousCollisionDetection::~ContinuousCollisionDetection()
{
	/*
	if(PenetrationDepthSolver)
		delete PenetrationDepthSolver;

	if(CCDCaster)
		delete CCDCaster;

	*/

	if(ObjectAModel)
		delete ObjectAModel;

	if(ObjectBModel)
		delete ObjectBModel;


#ifdef IN_DEBUG_MODE_LEVEL_1
	mexPrintf("\nContinuousCollisionDetection Object destroyed\n");
#endif

}

void ContinuousCollisionDetection::performCCDTest(int nargin,const mxArray *inputs[],int nargout,mxArray *output[])
{
	// initializing btTransform data array
	btTransform transformData[4];

#ifdef IN_DEBUG_MODE_LEVEL_2
	ContinuousCollisionDetection::printMethodCallDetails("performCCDTest",CCD_PERFORMCCDTEST);
	mexPrintf("\nContinuousCollisionDetection Object extracting input data \n");
#endif

	
	// obtaining transform data for object A
	transformData[0] = (MexUtilities::mxArray_to_btTransform(inputs[0]))*LocalTransformA.inverse();
	transformData[1] = (MexUtilities::mxArray_to_btTransform(inputs[1]))*LocalTransformA.inverse();

#ifdef IN_DEBUG_MODE_LEVEL_2
	mexPrintf("\nInitial Matrix for object a\n");
	MexUtilities::print_btTransform(transformData[0]);
	mexPrintf("\nFinal Matrix for object a\n");
	MexUtilities::print_btTransform(transformData[1]);
#endif

	// obtaining transform data for object B
	transformData[2] = (MexUtilities::mxArray_to_btTransform(inputs[2]))*LocalTransformB.inverse();
	transformData[3] = (MexUtilities::mxArray_to_btTransform(inputs[3]))*LocalTransformB.inverse();



#ifdef IN_DEBUG_MODE_LEVEL_2
	mexPrintf("\nContinuousCollisionDetection Object end of input data extraction\n");
#endif



	if((ObjectA==NULL) && (ObjectB==NULL)) // quit if both objects have not been set
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





#ifdef IN_DEBUG_MODE_LEVEL_2
	mexPrintf("\nContinuousCollisionDetection Object calling calcTimeOfImpact\n");
#endif
	
	// --------------------------------------------ccd setup------------------------------------------ //

	// creating return structure	
	C2A_TimeOfContactResult result;



	// performing ccd test
	int numTest = 10;

	// hit transforms
	btTransform hitTransformA, hitTransformB;

	// collision flag
	//C2A_Result collisionFlag;
	int collisionFlag;

#ifdef IN_DEBUG_MODE_LEVEL_2
	mexPrintf("\ncalling solveC2A\n");
#endif

	// performing CCD test	
	collisionFlag = solveC2A(transformData[0],transformData[1],transformData[2],transformData[3],hitTransformA,hitTransformB,numTest,0.0f,result);



#ifdef IN_DEBUG_MODE_LEVEL_2
	mexPrintf("\nC2A test performed, constructing return structures\n");
#endif
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
		case C2A_Result::TOCFound:
			{
				// setting field NumContacts  -------------------------------------------------------- //
				mxSetFieldByNumber(output[1],0,mxGetFieldNumber(output[1],"NumContacts"),
					MexUtilities::int_to_mxArray(result.num_contact));

				// setting field CollisionFlag  ------------------------------------------------------ //
				mxSetFieldByNumber(output[1],0,mxGetFieldNumber(output[1],"CollisionFlag"),
					MexUtilities::int_to_mxArray(collisionFlag));

				// setting field TOC         -------------------------------------------------------- //
				mxSetFieldByNumber(output[1],0,mxGetFieldNumber(output[1],"TOC"),
					MexUtilities::btScalar_to_mxArray(result.toc));

				// setting field TOC_TransformA  ---------------------------------------------------- //
				mxSetFieldByNumber(output[1],0,mxGetFieldNumber(output[1],"TOC_TransformA"),
					MexUtilities::btTransform_to_mxArray((hitTransformA*=LocalTransformA)));

				// setting field TOC_TransformB  ---------------------------------------------------- //
				mxSetFieldByNumber(output[1],0,mxGetFieldNumber(output[1],"TOC_TransformB"),
					MexUtilities::btTransform_to_mxArray((hitTransformB*=LocalTransformB)));

				// setting field QueryTime       ---------------------------------------------------- //
				mxSetFieldByNumber(output[1],0,mxGetFieldNumber(output[1],"QueryTime"),
					MexUtilities::btScalar_to_mxArray(result.query_time_secs));

				// creating contact result structure ------------------------------------------------- //
				mwSize contactStructArraySize[2];
				contactStructArraySize[0]=1;
				contactStructArraySize[1] = mwSize(result.num_contact);
				mxArray *contactResultStruct = mxCreateStructArray(2,contactStructArraySize,NumberOfContactResultFieldNames,
					ContactResultFieldNames);

				// declaring variables used to compute relative normal and contact points
				btVector3 contactPoint, contactPointLocal, contactPointWorld, normalWorldOnB(0,0,0), normalStart, normalEnd, normal;
				
				// declaring index
				mwIndex index = 0;
				// inserting data in contact result structure
				for(ContactFList::iterator i = result.cont_l.begin(); i != result.cont_l.end() ; i++ )
				{
					// retrieving current contact
					ContactF &contact = *i;


					// setting field ContactPointOnA  ----------------------------------------------------- //

					// computing contact point
					contactPoint = btVector3(contact.P_A[0],contact.P_A[1],contact.P_A[2]);
					contactPointLocal = LocalTransformA.inverse()(contactPoint);
					contactPointWorld = hitTransformA(contactPointLocal);
					 
					mxSetFieldByNumber(contactResultStruct,index,mxGetFieldNumber(contactResultStruct,"ContactPointOnA"),
						MexUtilities::btVector3_to_mxArray(contactPointLocal));

					// setting field ContactPointWorldOnA  ------------------------------------------------- //					 
					mxSetFieldByNumber(contactResultStruct,index,mxGetFieldNumber(contactResultStruct,"ContactPointWorldOnA"),
						MexUtilities::btVector3_to_mxArray(contactPointWorld));


					// setting field ContactPointOnB  ----------------------------------------------------- //

					// computing contact point

					contactPoint = btVector3(contact.P_B[0],contact.P_B[1],contact.P_B[2]);
					contactPointLocal = LocalTransformB.inverse()(contactPoint);
					contactPointWorld = hitTransformB(contactPointLocal);

					mxSetFieldByNumber(contactResultStruct,index,mxGetFieldNumber(contactResultStruct,"ContactPointOnB"),
						MexUtilities::btVector3_to_mxArray(contactPointLocal));


					// setting field ContactPointWorldOnB  ------------------------------------------------- //					 
					mxSetFieldByNumber(contactResultStruct,index,mxGetFieldNumber(contactResultStruct,"ContactPointWorldOnB"),
						MexUtilities::btVector3_to_mxArray(contactPointWorld));



					// setting field ContactNormalOnA  ----------------------------------------------------- //
					normalWorldOnB.setX(contact.Normal.X());
					normalWorldOnB.setY(contact.Normal.Y());
					normalWorldOnB.setZ(contact.Normal.Z());

					normalStart = hitTransformA.inverse()(btVector3(0.f,0.f,0.f));
					normalEnd = hitTransformA.inverse()(-1.f*normalWorldOnB);

					normal = normalEnd - normalStart;
					normal.normalize();

					mxSetFieldByNumber(contactResultStruct,index,mxGetFieldNumber(contactResultStruct,"ContactNormalOnA"),
						MexUtilities::btVector3_to_mxArray(normal));

					// setting field ContactNormalOnB  ----------------------------------------------------- //
					normalStart = hitTransformB.inverse()(btVector3(0.f,0.f,0.f));
					normalEnd = hitTransformB.inverse()(normalWorldOnB);

					normal = normalEnd - normalStart;
					normal.normalize();

					mxSetFieldByNumber(contactResultStruct,index,mxGetFieldNumber(contactResultStruct,"ContactNormalOnB"),
						MexUtilities::btVector3_to_mxArray(normal));

					// setting field ContactNormalWorldOnA  ----------------------------------------------------- //
					mxSetFieldByNumber(contactResultStruct,index,mxGetFieldNumber(contactResultStruct,"ContactNormalWorldOnA"),
						MexUtilities::btVector3_to_mxArray(-1.f*(normalWorldOnB.normalized())));


					// setting field ContactNormalWorldOnB  ----------------------------------------------------- //
					mxSetFieldByNumber(contactResultStruct,index,mxGetFieldNumber(contactResultStruct,"ContactNormalWorldOnB"),
						MexUtilities::btVector3_to_mxArray(normalWorldOnB.normalized()));

					// setting field InterpenetrationDistance -------------------------------------------------- //
					mxSetFieldByNumber(contactResultStruct,index,mxGetFieldNumber(contactResultStruct,"InterpenetrationDistance"),
						MexUtilities::btScalar_to_mxArray(contact.Distance));

					// setting default Combined Friction
					mxSetFieldByNumber(contactResultStruct,index,mxGetFieldNumber(contactResultStruct,"CombinedFriction"),
						MexUtilities::btScalar_to_mxArray(sDefaultCombinedFriction));

					// setting field Friction Model
					mxSetFieldByNumber(contactResultStruct,index,mxGetFieldNumber(contactResultStruct,"FrictionModel"),
						MexUtilities::charArray_to_mxArray("PCF",3));

					index++;

				}

				// setting field ContactResult         -------------------------------------------------- //
				mxSetFieldByNumber(output[1],0,mxGetFieldNumber(output[1],"ContactPoints"),
						contactResultStruct);

				break;
			}
		case C2A_Result::CollisionFree:
			{
				// setting field NumContacts  -------------------------------------------------------- //
				mxSetFieldByNumber(output[1],0,mxGetFieldNumber(output[1],"NumContacts"),
					MexUtilities::int_to_mxArray(0));

				// setting field CollisionFlag  ------------------------------------------------------ //
				mxSetFieldByNumber(output[1],0,mxGetFieldNumber(output[1],"CollisionFlag"),
					MexUtilities::int_to_mxArray(collisionFlag));

				// setting field TOC         -------------------------------------------------------- //
				mxSetFieldByNumber(output[1],0,mxGetFieldNumber(output[1],"TOC"),
					MexUtilities::btScalar_to_mxArray(1.f));

				// setting field TOC_TransformA  ---------------------------------------------------- //
				mxSetFieldByNumber(output[1],0,mxGetFieldNumber(output[1],"TOC_TransformA"),
					MexUtilities::btTransform_to_mxArray((hitTransformA*LocalTransformA)));

				// setting field TOC_TransformB  ---------------------------------------------------- //
				mxSetFieldByNumber(output[1],0,mxGetFieldNumber(output[1],"TOC_TransformB"),
					MexUtilities::btTransform_to_mxArray((hitTransformB*LocalTransformB)));

				// setting field QueryTime       ---------------------------------------------------- //
				mxSetFieldByNumber(output[1],0,mxGetFieldNumber(output[1],"QueryTime"),
					MexUtilities::btScalar_to_mxArray(result.query_time_secs));

				break;
			}
		case C2A_Result::CollisionFound:
			{

				// setting field NumContacts  -------------------------------------------------------- //
				mxSetFieldByNumber(output[1],0,mxGetFieldNumber(output[1],"NumContacts"),
					MexUtilities::int_to_mxArray(result.num_contact));

				// setting field CollisionFlag  ------------------------------------------------------ //
				mxSetFieldByNumber(output[1],0,mxGetFieldNumber(output[1],"CollisionFlag"),
					MexUtilities::int_to_mxArray(collisionFlag));

				// setting field TOC         -------------------------------------------------------- //
				mxSetFieldByNumber(output[1],0,mxGetFieldNumber(output[1],"TOC"),
					MexUtilities::btScalar_to_mxArray(0.f));

				// setting field TOC_TransformA  ---------------------------------------------------- //
				mxSetFieldByNumber(output[1],0,mxGetFieldNumber(output[1],"TOC_TransformA"),
					MexUtilities::btTransform_to_mxArray((hitTransformA*LocalTransformA)));

				// setting field TOC_TransformB  ---------------------------------------------------- //
				mxSetFieldByNumber(output[1],0,mxGetFieldNumber(output[1],"TOC_TransformB"),
					MexUtilities::btTransform_to_mxArray((hitTransformB*LocalTransformB)));

				// setting field QueryTime       ---------------------------------------------------- //
				mxSetFieldByNumber(output[1],0,mxGetFieldNumber(output[1],"QueryTime"),
					MexUtilities::btScalar_to_mxArray(0.f));

				break;
			}
		}
	}

	// deleting all resources
	//delete motionA;
	//delete motionB;



}

/*
void ContinuousCollisionDetection::resetCCDCaster()
{
	
#ifdef IN_DEBUG_MODE_LEVEL_2

	ContinuousCollisionDetection::printMethodCallDetails("resetCCDCaster",-2);
	mexPrintf("ContinuousCollisionDetection Object calling resetCCDCaster\n");
#endif

	if(ObjectA==NULL || ObjectB==NULL)
	{
		return;
	}

	if(CCDCaster)
		delete CCDCaster;

	// this might need to be changed in order to account for each shape type, especially compounds and gimpact types

	// obtaining shape types for each body
	btCollisionShape *shapeA = ObjectA->CollisionShape;
	btCollisionShape *shapeB = ObjectB->CollisionShape;

	if(shapeA->isCompound() && shapeB->isCompound())
	{
		// storing collision type
		CollisionType=CCD_COMPOUND_VS_COMPOUND;

		// selecting corresponding collision function 
		ccdTestFunction = &ContinuousCollisionDetection::ccdTestCompoundvsCompoundShapes;

		/*
		// storing convex collision shape A
		btCompoundShape *tempShape = static_cast<btCompoundShape *>(ObjectA->CollisionShape);
		ConvexShapeA = static_cast<btConvexShape *>(tempShape->getChildShape(0));

		// storing convex collision shape B
		tempShape = static_cast<btCompoundShape *>(ObjectB->CollisionShape);
		ConvexShapeB = static_cast<btConvexShape *>(tempShape->getChildShape(0));
		*/

/*
	}

	

	if(shapeA->isCompound() && shapeB->isConvex())
	{
		// storing collision type
		CollisionType = CCD_COMPOUND_VS_CONVEX;

		// selecting corresponding collision function 
		ccdTestFunction = &ContinuousCollisionDetection::ccdTestCompoundvsConvexShapes;

		/*

		// storing convex collision shape A
		btCompoundShape *tempShape = static_cast<btCompoundShape *>(ObjectA->CollisionShape);
		ConvexShapeA = static_cast<btConvexShape *>(tempShape->getChildShape(0));

		// storing convex collision shape B
		ConvexShapeB = static_cast<btConvexShape *>(ObjectB->CollisionShape);

		*/

/*
	}

	if(shapeA->isConvex() && shapeB->isCompound())
	{
		// storing collision type
		CollisionType = CCD_CONVEX_VS_COMPOUND;

		// selecting corresponding collision function 
		ccdTestFunction = &ContinuousCollisionDetection::ccdTestConvexvsCompoundShapes;

		/*
		// storing convex collision shape A
		ConvexShapeA = static_cast<btConvexShape *>(ObjectA->CollisionShape);

		// storing convex collision shape B
		btCompoundShape *tempShape = static_cast<btCompoundShape *>(ObjectB->CollisionShape);
		ConvexShapeB = static_cast<btConvexShape *>(tempShape->getChildShape(0));
		*/

/*
	}

	if(shapeA->isConvex() && shapeB->isConvex())
	{
		// storing collision type
		CollisionType = CCD_CONVEX_VS_CONVEX;

		// selecting corresponding collision function 
		ccdTestFunction = &ContinuousCollisionDetection::ccdTestConvexvsConvexShapes;

		/*
		// storing convex collision shape A
		ConvexShapeA = static_cast<btConvexShape *>(ObjectA->CollisionShape);

		// storing convex collision shape B
		ConvexShapeB = static_cast<btConvexShape *>(ObjectB->CollisionShape);
		*/

/*

	}

	// as an alternative, a pointer to a member function can be created 



	//btConvexShape *shapeA = (btConvexShape*)ObjectA->CollisionShape;
	//btConvexShape *shapeB = (btConvexShape*)ObjectB->CollisionShape;
#ifdef IN_DEBUG_MODE_LEVEL_2
	mexPrintf("\nContinuousCollisionDetection Object attempting to create ccdCaster\n");
#endif

	// CCDCaster = new btContinuousConvexCollision(shapeA,shapeB,SimplexSolverInterface,PenetrationDepthSolver);
	// CCDCaster = new btContinuousConvexCollision(ConvexShapeA,ConvexShapeB,SimplexSolverInterface,PenetrationDepthSolver);

#ifdef IN_DEBUG_MODE_LEVEL_2
	mexPrintf("\nContinuousCollisionDetection Object successfully created ccdCaster\n");
#endif
}

*/



void ContinuousCollisionDetection::setObjectA(int nargin,const mxArray *inputs[])
{
	ObjectA=Solid::get_object_pointer(inputs[START_OF_INPUT_DATA_INDEX]);

	if(nargin>START_OF_INPUT_DATA_INDEX+1)
	{

#ifdef IN_DEBUG_MODE_LEVEL_2
		mexPrintf("\n%i number of arguments , construction localTransform\n",nargin);
#endif
		LocalTransformA = MexUtilities::mxArray_to_btTransform(inputs[START_OF_INPUT_DATA_INDEX+1]);
	}
	else
	{
		LocalTransformA.setIdentity();
	}
	
	
	if(ObjectAModel)
		delete ObjectAModel;

	// instantiating PQP_Model Object
	/*
	btTransform localOffset;
	localOffset.setIdentity();
	ObjectAModel = C2AUtilities::create_C2A_Model(ObjectA,localOffset);
	LocalTransformA = ObjectA->COGTransform.inverse();
	*/

	ObjectAModel = C2AUtilities::create_C2A_Model(ObjectA,LocalTransformA*ObjectA->COGTransform);
	
	// computing to COG computed by PQP model
	//PQPCOGTransformA.setOrigin(btVector3(ObjectAModel->com[0],ObjectAModel->com[1],ObjectAModel->com[2]));



#ifdef IN_DEBUG_MODE_LEVEL_2
	mexPrintf("\nObject A cog as computed by PQP:\n");
	mexPrintf("\t%1.3f\n\t%1.3f\n\t%1.3f\n\n",ObjectAModel->com[0],ObjectAModel->com[1],ObjectAModel->com[2]);
#endif

#ifdef IN_DEBUG_MODE_LEVEL_1
	mexPrintf("\nObject A added to ContinuousCollisionDetection Object\n");
#endif

	// offseting local transform to account for cog
	/*
	btTransform cogTransform;
	cogTransform.setIdentity();
	cogTransform.setOrigin(btVector3(ObjectAModel->com[0],ObjectAModel->com[1],ObjectAModel->com[2]));
	LocalTransformA*=cogTransform;
	*/




	/*
	PQP_REAL com[3]={0,0,0};

	ObjectAModel->SetCenterOfMass(com);
	*/
	
	
	//resetCCDCaster();
}

void ContinuousCollisionDetection::setObjectB(int nargin,const mxArray *inputs[])
{
	ObjectB=Solid::get_object_pointer(inputs[START_OF_INPUT_DATA_INDEX]);

	if(nargin>START_OF_INPUT_DATA_INDEX+1)
	{
#ifdef IN_DEBUG_MODE_LEVEL_2
		mexPrintf("\n%i number of arguments , construction localTransform\n",nargin);
#endif
		LocalTransformB = MexUtilities::mxArray_to_btTransform(inputs[START_OF_INPUT_DATA_INDEX+1]);
	}
	else
	{
		LocalTransformB.setIdentity();
	}

	if(ObjectBModel)
		delete ObjectBModel;

	// instantiating PQP_Model Object

	/*
	btTransform localOffset;
	localOffset.setIdentity();
	ObjectBModel = C2AUtilities::create_C2A_Model(ObjectB,localOffset);
	LocalTransformB = ObjectB->COGTransform.inverse();
	*/

	ObjectBModel = C2AUtilities::create_C2A_Model(ObjectB,LocalTransformB*ObjectB->COGTransform);
	

	// computing to COG computed by PQP model
	//PQPCOGTransformB.setOrigin(btVector3(ObjectBModel->com[0],ObjectBModel->com[1],ObjectBModel->com[2]));

	
	
	

#ifdef IN_DEBUG_MODE_LEVEL_2
	mexPrintf("\nObject B cog as computed by PQP:\n");
	mexPrintf("\t%1.3f\n\t%1.3f\n\t%1.3f\n\n",ObjectBModel->com[0],ObjectBModel->com[1],ObjectBModel->com[2]);
#endif

#ifdef IN_DEBUG_MODE_LEVEL_1
	mexPrintf("\nObject B added to ContinuousCollisionDetection Object\n");
#endif

	
	// offseting local transform to account for cog
	/*
	btTransform cogTransform;
	cogTransform.setIdentity();
	cogTransform.setOrigin(btVector3(ObjectBModel->com[0],ObjectBModel->com[1],ObjectBModel->com[2]));
	LocalTransformB*=cogTransform;
	*/

	/*
	PQP_REAL com[3]={0,0,0};
	ObjectBModel->SetCenterOfMass(com);
	*/

	
	


	//resetCCDCaster();
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

		PQP_CollideResult res_col = PQP_CollideResult();
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
#ifdef IN_DEBUG_MODE_LEVEL_2
			mexPrintf("\nAlready at Collision, exiting C2A solve\n");
#endif

			objectATransformTOC = btTransform(objectATransform0);
			objectBTransformTOC = btTransform(objectBTransform0);
			collisionFlag = C2A_Result::CollisionFound; // collision found at time 0

#ifdef IN_DEBUG_MODE_LEVEL_2
			mexPrintf("\nmex Message:\tCollision Found at time 0\n");

#endif
		}
		else
		{

#ifdef IN_DEBUG_MODE_LEVEL_2
			mexPrintf("\nPerforming iterations\n");

#endif

			for(int i=0;i<number_of_iterations;i++)
			{

				CInterpMotion_Linear *motionA = C2AUtilities::create_C2A_CInterpMotion_Linear(objectATransform0New,objectATransformfNew,t_delta,d_delta);
				CInterpMotion_Linear *motionB = C2AUtilities::create_C2A_CInterpMotion_Linear(objectBTransform0New,objectBTransformfNew,t_delta,d_delta);

				//CInterpMotion_Slerp *motionA = C2AUtilities::create_C2A_CInterpMotion_Slerp(objectATransform0,objectATransformf,t_delta,d_delta);
				//CInterpMotion_Slerp *motionB = C2AUtilities::create_C2A_CInterpMotion_Slerp(objectBTransform0,objectBTransformf,t_delta,d_delta);


				motionA->m_toc_delta = d_delta;
				motionB->m_toc_delta = d_delta;


				// calculating toc
				C2A_QueryTimeOfContact(motionA,motionB,&dres,ObjectAModel,ObjectBModel,motionA->m_toc_delta,t_delta,0);

				dres.cont_l.clear();

				delete motionA;
				delete motionB;
			}

			//}

#ifdef IN_DEBUG_MODE_LEVEL_2
			mexPrintf("\nEnded Iterations\n");
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
					//CInterpMotion_Linear *motionA = C2AUtilities::create_C2A_CInterpMotion(objectATransform0,objectATransformf,t_delta,d_delta);
					//CInterpMotion_Linear *motionB = C2AUtilities::create_C2A_CInterpMotion(objectBTransform0,objectBTransformf,t_delta,d_delta);
					
					//CInterpMotion *motionA = C2AUtilities::create_C2A_CInterpMotion(objectATransform0,objectATransformf,t_delta,d_delta);
					//CInterpMotion *motionB = C2AUtilities::create_C2A_CInterpMotion(objectBTransform0,objectBTransformf,t_delta,d_delta);

					CInterpMotion_Linear *motionA = C2AUtilities::create_C2A_CInterpMotion_Linear(objectATransform0,objectATransformf,t_delta,d_delta);
					CInterpMotion_Linear *motionB = C2AUtilities::create_C2A_CInterpMotion_Linear(objectBTransform0,objectBTransformf,t_delta,d_delta);

					// time of collision found

#ifdef IN_DEBUG_MODE_LEVEL_2
					mexPrintf("\nPlacing data in btTransforms\n");
#endif
					
					PQP_REAL qua[7];
					motionA->integrate(dres.toc,qua);
					objectATransformTOC.setRotation(btQuaternion(qua[1],qua[2],qua[3],qua[0]));
					objectATransformTOC.setOrigin(btVector3(qua[4],qua[5],qua[6]));

					motionB->integrate(dres.toc,qua);
					objectBTransformTOC.setRotation(btQuaternion(qua[1],qua[2],qua[3],qua[0]));
					objectBTransformTOC.setOrigin(btVector3(qua[4],qua[5],qua[6]));

					Transform trans0, trans1;

#ifdef IN_DEBUG_MODE_LEVEL_2
					mexPrintf("\nPlacing data from btTransforms to c2a transforms\n");
#endif
					C2AUtilities::btTransform_to_Transform(objectATransformTOC,trans0);
					C2AUtilities::btTransform_to_Transform(objectBTransformTOC,trans1);

#ifdef IN_DEBUG_MODE_LEVEL_2
					mexPrintf("\nDone placing data into c2a transforms\n");
#endif

					double threshold = 2*dres.distance+0.001 + th_ca;

#ifdef IN_DEBUG_MODE_LEVEL_2
					mexPrintf("\nCalling C2A_QueryContact\n");
#endif

					C2A_QueryContact(motionA,motionB,&dres,ObjectAModel,ObjectBModel,threshold);

#ifdef IN_DEBUG_MODE_LEVEL_2
					mexPrintf("\nCalling Contact_normal_new\n");
#endif

					Contact_normal_new(&dres,ObjectAModel,ObjectBModel,trans0,trans1);//changed in 6.10

#ifdef IN_DEBUG_MODE_LEVEL_2
					mexPrintf("\nDone computing normal\n");
#endif


					collisionFlag =  C2A_Result::TOCFound;

					delete motionA;
					delete motionB;
				}

			}				
			else
			{
				
				objectATransformTOC = btTransform(objectATransform0);
				objectBTransformTOC = btTransform(objectBTransform0);
								
				collisionFlag = C2A_Result::CollisionFree; // no collision occurs
			}

				

			

		}

		return collisionFlag;		


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

#ifdef IN_DEBUG_MODE_LEVEL_2
	/*mexPrintf("------------------------------------------------------------\n");
	mexPrintf("Created handle to pointer to CCD Object, new pointer value= %#x, \n",ccd);
	*/
#endif

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

// -------------------------------------------------------------------------------------------- //
// -------------------------------------------------------------------------------------------- //
// -------------------------------------------------------------------------------------------- //
// dicarded methods

/*
// collision methods
bool ContinuousCollisionDetection::ccdTestCompoundvsCompoundShapes(btTransform &startTransformA,btTransform &endTransformA,
																   btTransform &startTransformB,btTransform &endTransformB,btConvexCast::CastResult &result)
{
	bool collided;

	// initializing variables
	btCompoundShape *tempShapeA = static_cast<btCompoundShape*>(ObjectA->CollisionShape);
	int numOfChildShapesInA = tempShapeA->getNumChildShapes();

	btCompoundShape *tempShapeB = static_cast<btCompoundShape*>(ObjectB->CollisionShape);
	int numOfChildShapesInB = tempShapeB->getNumChildShapes();

	btTransform childShapeOfATransform;
	btTransform childShapeOfBTransform;

	btConvexCast::CastResult tempResult;
	int fraction = 1; //	, currentFraction;
	

	for(int ni = 0;ni<numOfChildShapesInA;ni++)
	{
		for(int mi = 0;mi<numOfChildShapesInB;mi++)
		{

			ConvexShapeA = static_cast<btConvexShape *>(tempShapeA->getChildShape(ni));
			ConvexShapeB = static_cast<btConvexShape *>(tempShapeB->getChildShape(mi));

			childShapeOfATransform=tempShapeA->getChildTransform(ni);
			childShapeOfBTransform=tempShapeB->getChildTransform(mi);

			CCDCaster = new btContinuousConvexCollision(ConvexShapeA,ConvexShapeB,SimplexSolverInterface,PenetrationDepthSolver);

			SimplexSolverInterface->reset();

			// performing 
			collided = CCDCaster->calcTimeOfImpact(startTransformA*childShapeOfATransform,endTransformA*childShapeOfATransform,
				startTransformB*childShapeOfBTransform,endTransformB*childShapeOfBTransform,tempResult);

			if(collided)
			{
				
				if(fraction>tempResult.m_fraction)
				{
					fraction = tempResult.m_fraction;
					result.m_hitPoint = tempResult.m_hitPoint;
					result.m_allowedPenetration = tempResult.m_allowedPenetration;
					result.m_normal = tempResult.m_normal;
					result.m_fraction = tempResult.m_fraction;
				}
			}

			delete CCDCaster;
		}
	}

	CCDCaster=0;
	
	return collided;
}

bool ContinuousCollisionDetection::ccdTestCompoundvsConvexShapes(btTransform &startTransformA,btTransform &endTransformA,
																 btTransform &startTransformB,btTransform &endTransformB,btConvexCast::CastResult &result)
{
	
	bool collided;

	// initializing variables
	btCompoundShape *tempShapeA = static_cast<btCompoundShape*>(ObjectA->CollisionShape);
	int numOfChildShapesInA = tempShapeA->getNumChildShapes();

	ConvexShapeB = static_cast<btConvexShape*>(ObjectB->CollisionShape);
	//int numOfChildShapesInB = tempShapeB->getNumChildShapes();

	btTransform childShapeOfATransform;
	//btTransform childShapeOfBTransform;

	btConvexCast::CastResult tempResult;
	int fraction = 1; //	, currentFraction;
	

	for(int ni = 0;ni<numOfChildShapesInA;ni++)
	{

		// updating convex shape to be tested 
		ConvexShapeA = static_cast<btConvexShape *>(tempShapeA->getChildShape(ni));
		//ConvexShapeB = static_cast<btConvexShape *>(tempShapeB->getChildShape(mi));

		childShapeOfATransform=tempShapeA->getChildTransform(ni);
		//childShapeOfBTransform=tempShapeB->getChildTransform(mi);

		CCDCaster = new btContinuousConvexCollision(ConvexShapeA,ConvexShapeB,SimplexSolverInterface,PenetrationDepthSolver);

		SimplexSolverInterface->reset();

		// performing 
		collided = CCDCaster->calcTimeOfImpact(startTransformA*childShapeOfATransform,endTransformA*childShapeOfATransform,
			startTransformB,endTransformB,tempResult);

		if(collided)
		{
			
			if(fraction>tempResult.m_fraction)
			{
				fraction = tempResult.m_fraction;
				result.m_hitPoint = tempResult.m_hitPoint;
				result.m_allowedPenetration = tempResult.m_allowedPenetration;
				result.m_normal = tempResult.m_normal;
				result.m_fraction = tempResult.m_fraction;
			}
		}

		delete CCDCaster;
		
	}

	CCDCaster=0;
	
	return collided;
}

bool ContinuousCollisionDetection::ccdTestConvexvsCompoundShapes(btTransform &startTransformA,btTransform &endTransformA,
																 btTransform &startTransformB,btTransform &endTransformB,btConvexCast::CastResult &result)
{
	
	bool collided;

	// initializing variables
	ConvexShapeA = static_cast<btConvexShape*>(ObjectA->CollisionShape);
	//int numOfChildShapesInA = tempShapeA->getNumChildShapes();

	btCompoundShape *tempShapeB = static_cast<btCompoundShape*>(ObjectB->CollisionShape);
	int numOfChildShapesInB = tempShapeB->getNumChildShapes();

	//btTransform childShapeOfATransform;
	btTransform childShapeOfBTransform;

	btConvexCast::CastResult tempResult;
	int fraction = 1; //	, currentFraction;
	

	for(int mi = 0;mi<numOfChildShapesInB;mi++)
	{

		//ConvexShapeA = static_cast<btConvexShape *>(tempShapeA->getChildShape(ni));

		// updating convex shape to be tested 
		ConvexShapeB = static_cast<btConvexShape *>(tempShapeB->getChildShape(mi));

		//childShapeOfATransform=tempShapeA->getChildTransform(ni);
		childShapeOfBTransform=tempShapeB->getChildTransform(mi);

		CCDCaster = new btContinuousConvexCollision(ConvexShapeA,ConvexShapeB,SimplexSolverInterface,PenetrationDepthSolver);

		SimplexSolverInterface->reset();

		// performing 
		collided = CCDCaster->calcTimeOfImpact(startTransformA,endTransformA,
			startTransformB*childShapeOfBTransform,endTransformB*childShapeOfBTransform,tempResult);

		if(collided)
		{
			
			if(fraction>tempResult.m_fraction)
			{
				fraction = tempResult.m_fraction;
				result.m_hitPoint = tempResult.m_hitPoint;
				result.m_allowedPenetration = tempResult.m_allowedPenetration;
				result.m_normal = tempResult.m_normal;
				result.m_fraction = tempResult.m_fraction;
			}
		}

		delete CCDCaster;
	}

	CCDCaster=0;
	
	return collided;
}

bool ContinuousCollisionDetection::ccdTestConvexvsConvexShapes(btTransform &startTransformA,btTransform &endTransformA,
															   btTransform &startTransformB,btTransform &endTransformB,btConvexCast::CastResult &result)
{
	bool collided;

	// initializing variables
	ConvexShapeA = static_cast<btConvexShape*>(ObjectA->CollisionShape);
	//int numOfChildShapesInA = tempShapeA->getNumChildShapes();

	ConvexShapeB = static_cast<btConvexShape*>(ObjectB->CollisionShape);
	//int numOfChildShapesInB = tempShapeB->getNumChildShapes();

	//btTransform childShapeOfATransform;
	//btTransform childShapeOfBTransform;

	//btConvexCast::CastResult tempResult;
	int fraction = 1; //	, currentFraction;
	



	//ConvexShapeA = static_cast<btConvexShape *>(tempShapeA->getChildShape(ni));
	//ConvexShapeB = static_cast<btConvexShape *>(tempShapeB->getChildShape(mi));

	//childShapeOfATransform=tempShapeA->getChildTransform(ni);
	//childShapeOfBTransform=tempShapeB->getChildTransform(mi);

	CCDCaster = new btContinuousConvexCollision(ConvexShapeA,ConvexShapeB,SimplexSolverInterface,PenetrationDepthSolver);

	SimplexSolverInterface->reset();

	// performing 
	collided = CCDCaster->calcTimeOfImpact(startTransformA,endTransformA,
		startTransformB,endTransformB,result);

	/*
	if(collided)
	{
		
		if(fraction>tempResult.m_fraction)
		{
			fraction = tempResult.m_fraction;
			result.m_hitPoint = tempResult.m_hitPoint;
			result.m_allowedPenetration = tempResult.m_allowedPenetration;
			result.m_normal = tempResult.m_normal;
			result.m_fraction = tempResult.m_fraction;
		}
	}
	*/
/*
	delete CCDCaster;

	CCDCaster=0;

	return collided;
}

*/

