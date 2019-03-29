
//#include <string>
#include "Solid.h"
#include "ObjectHandle.h"
#include "TrimeshConvexDecomposition.h"


/* Observations:

	- The collisionPairTest in the Solid class can encounter runtime errors when it is called while the simulation is running.  Pausing the simulations
	  prior to calling this method is safe since only one process tries to access resources during the duration of this call.  Consider using mutexes or 
	  any other mechanisms for safe multithreading operations.

*/

// creating contact structure field names
const char *FieldNames[]={"ContactPointOnA","ContactPointOnB","ContactPointWorldOnA","ContactPointWorldOnB","ContactNormalOnA","ContactNormalOnB",
								"ContactNormalWorldOnB","InterpenetrationDistance","CombinedFriction","FrictionModel","CombinedRestitution","AppliedImpulse",
								"LateralFrictionInitialized","AppliedImpulseLateral1","AppliedImpulseLateral2","ContactMotion1","ContactMotion2",
								"ContactCFM1","ContactCFM2","LifeTime","LateralFrictionDirection1","LateralFrictionDirection2"};

static int NumberOfContactStructureFields = 22;

// -------------------------------------------------------------------------------------------- //
Solid::Solid(const mxArray *input)
{

	
	// obtaining the class name
	//const char *pClassName=mxGetClassName(input);
	
	// retrieving the Geometry id

	// initializing pointers to null
	TrimeshData = 0;
	Vertices = 0;
	Faces = 0;
	DynamicWorld=0;

#ifdef IN_DEBUG_MODE_LEVEL_1
	mexPrintf("\n\n------------------------------------------------------------");
	mexPrintf("\n-----------------Solid Object Construction------------------");
	mexPrintf("\n------------------------------------------------------------\n");
#endif


	int geometryId = MexUtilities::mxArray_to_int(input,mwIndex(0),"GeometryID");

	switch(geometryId)
	{
	case PLANE:
		constructStaticPlane(input);

		GeometryType=string("StaticPlane");
		GeometryId=PLANE;

		break;
	case BOX:
		constructBox(input);

		GeometryType=string("Box");
		GeometryId=BOX;

		break;

	case SPHERE:
		constructSphere(input);

		GeometryType=string("Sphere");
		GeometryId=SPHERE;

		break;
	case TRIMESH:
		constructTrimesh(input);

		GeometryType=string("Trimesh");
		GeometryId=TRIMESH;

		break;
	case STATICTRIMESH:
		constructStaticTrimesh(input);

		GeometryType=string("StaticTrimesh");
		GeometryId=STATICTRIMESH;

		break;
	default:
		mexPrintf("\nGeometryID = %i not recognized, no action was taken\n",geometryId);

		GeometryType=string("none");
		GeometryId=-1;

		break;
	}

	COGTransform.setIdentity();
	COGTransform.setOrigin(COG);
	

	updateTransform();

#ifdef IN_DEBUG_MODE_LEVEL_1
	printProperties();  

	mexPrintf("\n\n------------------------------------------------------------");
	mexPrintf("\n------------End Of Solid Object Construction----------------");
	mexPrintf("\n------------------------------------------------------------\n");
#endif

}


// -------------------------------------------------------------------------------------------- //
Solid::~Solid()
{

	/*
	if(LocalEnvironment!=NULL)
	{
		LocalEnvironment->DynamicsWorld->removeRigidBody(RigidBody);
	}
	*/

	//delete CollisionShape;
	delete MotionState;
	delete RigidBody;
	delete Transform;

	
	if(GeometryId==TRIMESH || GeometryId==STATICTRIMESH)
	{
		// deleting shild shapes
		// casting pointer to compound shape
#ifdef USE_DEFAULT_COLLISION
		if(CollisionShape->isCompound())
		{
			btCompoundShape *compound = (btCompoundShape *)CollisionShape;

#ifdef IN_DEBUG_MODE_LEVEL_1

			mexPrintf("Destroying child shapes\n");

#endif
			for(int i=0;i<compound->getNumChildShapes();i++)
			{
				// casting to collision shape
				btCollisionShape *childShape = compound->getChildShape(i);
				delete childShape;
#ifdef IN_DEBUG_MODE_LEVEL_1

			mexPrintf("Destroyed child shape #%i\n",i);

#endif

			}
		}
#endif

		delete CollisionShape;

#ifdef USE_DEFAULT_COLLISION
#ifdef IN_DEBUG_MODE_LEVEL_1

		mexPrintf("Destroyed compound shape\n");

#endif
#endif
		
		/*
		if(TrimeshData!=NULL)
		{
			delete TrimeshData;
			TrimeshData = 0;
		}

		if(Vertices!=NULL)
		{
			delete[] Vertices;
			Vertices=0;
		}

		if(Faces!=NULL)
		{
			delete[] Faces;
			Faces = 0;
		}
		*/

	}
	else
	{

		delete CollisionShape;




	}


	// deleting triangulation attributes
	if(TrimeshData!=NULL)
	{
		delete TrimeshData;
		TrimeshData = 0;
	}

	if(Vertices!=NULL)
	{
		delete[] Vertices;
		Vertices=0;
	}

	if(Faces!=NULL)
	{
		delete[] Faces;
		Faces = 0;
	}



	

#ifdef IN_DEBUG_MODE_LEVEL_1

	mexPrintf("Solid Object destroyed\n");

#endif
	
	// phisics environment should delete the collision object
}


// -------------------------------------------------------------------------------------------- //
void Solid::getPosition(mxArray *output[])
{
	
	updateTransform();

	ArraySize[0]=3;
	ArraySize[1]=1;
	
	//mexPrintf("creating mxArray\n");
	output[0]=mxCreateNumericArray(mwSize(2),ArraySize,MXDATA_CLASS,mxREAL);
	
	// placing the requested data into the output mxArray
	//mexPrintf("acquiring pointer to output mxArray\n");
	
	btScalar* outArray=(btScalar *)mxGetData(output[0]);

	//mexPrintf("setting output pointer equal to Position array pointer\n");

	
	//outArray[0]=Position[0];
	//outArray[1]=Position[1];
	//outArray[2]=Position[2];

	outArray[0]=btScalar(Transform->getOrigin().getX());
	outArray[1]=btScalar(Transform->getOrigin().getY());
	outArray[2]=btScalar(Transform->getOrigin().getZ());
	
	//mxSetData(output[0],(void *)Position);

	
}

// -------------------------------------------------------------------------------------------- //
void Solid::getRotation(mxArray *output[])
{
	//
	updateTransform();

	ArraySize[0]=1;
	ArraySize[1]=4;
	output[0]=mxCreateNumericArray(mwSize(2),ArraySize,MXDATA_CLASS,mxREAL);

	// placing the requested data into the output mxArray
	//mxSetData(output,(void *)Quaternion);

	//mexPrintf("acquiring pointer to output mxArray\n");
	
	btScalar* outArray=(btScalar *)mxGetData(output[0]);

	//mexPrintf("setting output pointer equal to Quaternion array pointer\n");
	//*outArray=Quaternion;
/*
	for(int i=0;i<4;i++)
		outArray[i]=Quaternion[i];
*/
	outArray[0]=btScalar(Transform->getRotation().getX());
	outArray[1]=btScalar(Transform->getRotation().getY());
	outArray[2]=btScalar(Transform->getRotation().getZ());
	outArray[3]=btScalar(Transform->getRotation().getW());

}

// -------------------------------------------------------------------------------------------- //
void Solid::getTransform(mxArray *output[])
{
	updateTransform();

	ArraySize[0]=4;
	ArraySize[1]=4;

	output[0]=mxCreateNumericArray(mwSize(2),ArraySize,MXDATA_CLASS,mxREAL);

	// acquiring pointer to output data
	btScalar* outArray=(btScalar *)mxGetData(output[0]);

	// setting the rotational part of the matrix	
	for(int i=0;i<3;i++)
	{
		
		outArray[4*i]=Transform->getBasis().getColumn(i).getX();
		outArray[4*i+1]=Transform->getBasis().getColumn(i).getY();
		outArray[4*i+2]=Transform->getBasis().getColumn(i).getZ();
		outArray[4*i+3]=btScalar(0); // last row is filled with zeros		
	}

	outArray[12]=Transform->getOrigin().getX();
	outArray[13]=Transform->getOrigin().getY();
	outArray[14]=Transform->getOrigin().getZ();
	outArray[15]=btScalar(1);

}

// -------------------------------------------------------------------------------------------- //
void Solid::collisionPairTest(const mxArray *solidHandle,mxArray *output[],int nargout)
{
	
	// if no output arguments are passed the do not conduct the collision test
	if(nargout==0)
		return;

	// creating contact result callback structure
	struct CustomContactResultCallback result;

	// retriving second solid object
	Solid *solid2 = Solid::get_object_pointer(solidHandle);

	// calling contact Pair Test method from dynamics world
	if(DynamicWorld!=NULL)
	{
#ifdef IN_DEBUG_MODE_LEVEL_2
		mexPrintf("\nCalling DynamicWorld::contactPairTest\n");
#endif

		DynamicWorld->contactPairTest((btCollisionObject*)RigidBody,(btCollisionObject*)solid2->RigidBody,result);
	}

	// creating return arguments
	// the return arguments are a boolean indicating if a collision took place as well as a structure array if there are sufficient outputs
	if(nargout>=1)
	{
		output[0]=mxCreateLogicalScalar(result.Collided);
	}

	
	if(nargout>=2)
	{
	
		if(result.Collided) // create structure 
		{
		

			mwSize arraySize[2];
			arraySize[0]=1;
			arraySize[1]=result.NumberOfContactPoints;

			// creating structure array
			output[1]= mxCreateStructArray(2,arraySize,NumberOfContactStructureFields,FieldNames);

			// updating Transform in order to compute normal vectors in local coordinates
			updateTransform();
			solid2->updateTransform();

			// normals vectors
			btVector3 normalStart(0,0,0), normalEnd(0,0,0), normal(0,0,0), normalWorldOnB; 

			// transform
			btTransform objAInvTransform(Transform->inverse());
			btTransform objBInvTransform(solid2->Transform->inverse());

			

#ifdef IN_DEBUG_MODE_LEVEL_2

			mexPrintf("\nAppending ContactPoint Properties\n");

#endif
			// setting field values
			int index=0;
			for(vector<btManifoldPoint*>::iterator i=result.ContactPoints.begin();i!=result.ContactPoints.end();i++)
			{
				// creating pointer to manifold point'
				btManifoldPoint* contactPoint=*i;

				if(contactPoint==NULL)
				{
					continue;
				}
				
				
#ifdef IN_DEBUG_MODE_LEVEL_2
				mexPrintf("\nContact # %i",index+1);
#endif



				// --------------------------------------------------------------------------------------------------//
				// setting  Contact Point On A  ----------------------------------------------------------------//
				// --------------------------------------------------------------------------------------------------//
				
#ifdef IN_DEBUG_MODE_LEVEL_2
				mexPrintf("\nContactPointOnA:\t%1.3f\t%1.3f\t%1.3f",contactPoint->m_localPointA.getX(),
					contactPoint->m_localPointA.getY(),contactPoint->m_localPointA.getZ());
#endif

				mxSetFieldByNumber(output[1],index,mxGetFieldNumber(output[1],"ContactPointOnA"),
					MexUtilities::btVector3_to_mxArray(COGTransform(contactPoint->m_localPointA)));



				// --------------------------------------------------------------------------------------------------//
				// setting field Contact Point On B  ----------------------------------------------------------------//
				// --------------------------------------------------------------------------------------------------//
				/*
				arraySize[0]=1;
				arraySize[1]=3;

				fieldValue = mxCreateNumericArray(2,arraySize,MXDATA_CLASS,mxREAL);

				pFieldValue = (btScalar *)mxGetData(fieldValue);

				pFieldValue[0]=contactPoint->m_localPointB.getX();
				pFieldValue[1]=contactPoint->m_localPointB.getY();
				pFieldValue[2]=contactPoint->m_localPointB.getZ();
				*/

#ifdef IN_DEBUG_MODE_LEVEL_2
				mexPrintf("\nContactPointOnB:\t%1.3f\t%1.3f\t%1.3f",contactPoint->m_localPointB.getX(),
					contactPoint->m_localPointB.getY(),contactPoint->m_localPointB.getZ());
#endif


				mxSetFieldByNumber(output[1],index,mxGetFieldNumber(output[1],"ContactPointOnB"),
					MexUtilities::btVector3_to_mxArray(solid2->COGTransform(contactPoint->m_localPointB)));

				// --------------------------------------------------------------------------------------------------//
				// setting field Contact Point World On A  ----------------------------------------------------------//
				// --------------------------------------------------------------------------------------------------//

#ifdef IN_DEBUG_MODE_LEVEL_2
				mexPrintf("\nContactPointWorldOnA:\t%1.3f\t%1.3f\t%1.3f",contactPoint->getPositionWorldOnA().getX(),
					contactPoint->getPositionWorldOnA().getY(),contactPoint->getPositionWorldOnA().getZ());
#endif

				mxSetFieldByNumber(output[1],index,mxGetFieldNumber(output[1],"ContactPointWorldOnA"),
					MexUtilities::btVector3_to_mxArray(contactPoint->getPositionWorldOnA()));

				// --------------------------------------------------------------------------------------------------//
				// setting field Contact Point World On B  ----------------------------------------------------------//
				// --------------------------------------------------------------------------------------------------//

#ifdef IN_DEBUG_MODE_LEVEL_2
				mexPrintf("\nContactPointWorldOnB:\t%1.3f\t%1.3f\t%1.3f",contactPoint->getPositionWorldOnB().getX(),
					contactPoint->getPositionWorldOnB().getY(),contactPoint->getPositionWorldOnB().getZ());
#endif

				mxSetFieldByNumber(output[1],index,mxGetFieldNumber(output[1],"ContactPointWorldOnB"),
					MexUtilities::btVector3_to_mxArray(contactPoint->getPositionWorldOnB()));

				
				// --------------------------------------------------------------------------------------------------//
				// setting Contact Normal On A       ----------------------------------------------------------------//
				// --------------------------------------------------------------------------------------------------//

				//computing relative normals
				/*
				normalWorldOnB.setValue(contactPoint->m_normalWorldOnB.getX(),contactPoint->m_normalWorldOnB.getY(),
					contactPoint->m_normalWorldOnB.getZ());
					*/

				normalWorldOnB = btScalar(-1)*contactPoint->m_normalWorldOnB.normalized();

				// computing normal on A
				normalStart = objAInvTransform(btVector3(0.f,0.f,0.f));
				//normalEnd = objAInvTransform(-1.f*normalWorldOnB);
				normalEnd = objAInvTransform(-1.f*normalWorldOnB);

				normal = normalEnd - normalStart;
				normal.normalize();

				mxSetFieldByNumber(output[1],index,mxGetFieldNumber(output[1],"ContactNormalOnA"),
					MexUtilities::btVector3_to_mxArray(normal));

				
				
				// --------------------------------------------------------------------------------------------------//
				// setting Contact Normal On B       ----------------------------------------------------------------//
				// --------------------------------------------------------------------------------------------------//


#ifdef IN_DEBUG_MODE_LEVEL_2
				mexPrintf("\nContactNormalOnB:\t%1.3f\t%1.3f\t%1.3f",contactPoint->m_normalWorldOnB.getX(),
					contactPoint->m_normalWorldOnB.getY(),contactPoint->m_normalWorldOnB.getZ());
#endif

				// computing normal on A
				normalStart = objBInvTransform(btVector3(0.f,0.f,0.f));
				normalEnd = objBInvTransform(normalWorldOnB);

				normal = normalEnd - normalStart;
				normal.normalize();

				mxSetFieldByNumber(output[1],index,mxGetFieldNumber(output[1],"ContactNormalOnB"),
					MexUtilities::btVector3_to_mxArray(normal));

				// --------------------------------------------------------------------------------------------------//
				// setting Contact Normal World On B       ----------------------------------------------------------//
				// --------------------------------------------------------------------------------------------------//

#ifdef IN_DEBUG_MODE_LEVEL_2
				mexPrintf("\nContactNormalWorldOnB:\t%1.3f\t%1.3f\t%1.3f",contactPoint->m_normalWorldOnB.getX(),
					contactPoint->m_normalWorldOnB.getY(),contactPoint->m_normalWorldOnB.getZ());
#endif
				
				mxSetFieldByNumber(output[1],index,mxGetFieldNumber(output[1],"ContactNormalWorldOnB"),
					MexUtilities::btVector3_to_mxArray(normalWorldOnB));



				// --------------------------------------------------------------------------------------------------//
				// setting field Interpenetration Distance-----------------------------------------------------------//
				// --------------------------------------------------------------------------------------------------//

#ifdef IN_DEBUG_MODE_LEVEL_1
				mexPrintf("\nInterpenetrationDistance:\t%1.3f",contactPoint->m_distance1);
#endif

				mxSetFieldByNumber(output[1],index,mxGetFieldNumber(output[1],"InterpenetrationDistance"),
					MexUtilities::btScalar_to_mxArray(contactPoint->m_distance1));


				// --------------------------------------------------------------------------------------------------//
				// setting field combined friction ----------------------------------------------------------------//
				// --------------------------------------------------------------------------------------------------//


#ifdef IN_DEBUG_MODE_LEVEL_2
				mexPrintf("\nCombinedFriction:\t%1.3f",contactPoint->m_combinedFriction);
#endif

				mxSetFieldByNumber(output[1],index,mxGetFieldNumber(output[1],"CombinedFriction"),
					MexUtilities::btScalar_to_mxArray(contactPoint->m_combinedFriction));


				// --------------------------------------------------------------------------------------------------//
				// setting field combined restitution ----------------------------------------------------------------//
				// --------------------------------------------------------------------------------------------------//

#ifdef IN_DEBUG_MODE_LEVEL_2
				mexPrintf("\nFrictionModel:\t%1.3f",contactPoint->m_combinedRestitution);
#endif

				mxSetFieldByNumber(output[1],index,mxGetFieldNumber(output[1],"FrictionModel"),
					MexUtilities::charArray_to_mxArray("PCF",mwSize(3)));

				// --------------------------------------------------------------------------------------------------//
				// setting field combined restitution ----------------------------------------------------------------//
				// --------------------------------------------------------------------------------------------------//

#ifdef IN_DEBUG_MODE_LEVEL_2
				mexPrintf("\nCombinedRestitution:\t%1.3f",contactPoint->m_combinedRestitution);
#endif

				mxSetFieldByNumber(output[1],index,mxGetFieldNumber(output[1],"CombinedRestitution"),
					MexUtilities::btScalar_to_mxArray(contactPoint->m_combinedRestitution));



				// --------------------------------------------------------------------------------------------------//
				// setting field applied Impulse ----------------------------------------------------------------//
				// --------------------------------------------------------------------------------------------------//

#ifdef IN_DEBUG_MODE_LEVEL_2
				mexPrintf("\nAppliedImpulse:\t%1.3f",contactPoint->m_appliedImpulse);
#endif

				mxSetFieldByNumber(output[1],index,mxGetFieldNumber(output[1],"AppliedImpulse"),
					MexUtilities::btScalar_to_mxArray(contactPoint->m_appliedImpulse));

				

				// --------------------------------------------------------------------------------------------------//
				// setting field lateral friction initialized ----------------------------------------------------------------//
				// --------------------------------------------------------------------------------------------------//

#ifdef IN_DEBUG_MODE_LEVEL_2
				mexPrintf("\nLateralFrictionInitialized:\t%i",contactPoint->m_lateralFrictionInitialized);
#endif
				
				mxSetFieldByNumber(output[1],index,mxGetFieldNumber(output[1],"LateralFrictionInitialized"),
					MexUtilities::bool_to_mxArray(contactPoint->m_lateralFrictionInitialized));



				// --------------------------------------------------------------------------------------------------//
				// setting field appliedImpulseLateral1 ----------------------------------------------------------------//
				// --------------------------------------------------------------------------------------------------//

#ifdef IN_DEBUG_MODE_LEVEL_2
				mexPrintf("\nAppliedImpulseLateral1:\t%1.3f",contactPoint->m_appliedImpulseLateral1);
#endif

				mxSetFieldByNumber(output[1],index,mxGetFieldNumber(output[1],"AppliedImpulseLateral1"),
					MexUtilities::btScalar_to_mxArray(contactPoint->m_appliedImpulseLateral1));



				// --------------------------------------------------------------------------------------------------//
				// setting field applied impulse lateral 2 ----------------------------------------------------------------//
				// --------------------------------------------------------------------------------------------------//

#ifdef IN_DEBUG_MODE_LEVEL_2
				mexPrintf("\nAppliedImpulseLateral2:\t%1.3f",contactPoint->m_appliedImpulseLateral2);
#endif

				mxSetFieldByNumber(output[1],index,mxGetFieldNumber(output[1],"AppliedImpulseLateral2"),
					MexUtilities::btScalar_to_mxArray(contactPoint->m_appliedImpulseLateral2));




				// --------------------------------------------------------------------------------------------------//
				// setting field contact motion 1 ----------------------------------------------------------------//
				// --------------------------------------------------------------------------------------------------//

#ifdef IN_DEBUG_MODE_LEVEL_2
				mexPrintf("\nContactMotion1:\t%1.3f",contactPoint->m_contactMotion1);
#endif

				mxSetFieldByNumber(output[1],index,mxGetFieldNumber(output[1],"ContactMotion1"),
					MexUtilities::btScalar_to_mxArray(contactPoint->m_contactMotion1));



				// --------------------------------------------------------------------------------------------------//
				// setting field contact motion 2 ----------------------------------------------------------------//
				// --------------------------------------------------------------------------------------------------//

#ifdef IN_DEBUG_MODE_LEVEL_2
				mexPrintf("\nContactMotion2:\t%1.3f",contactPoint->m_contactMotion2);
#endif

				mxSetFieldByNumber(output[1],index,mxGetFieldNumber(output[1],"ContactMotion2"),
					MexUtilities::btScalar_to_mxArray(contactPoint->m_contactMotion2));


				// --------------------------------------------------------------------------------------------------//
				// setting field contact CFM 1 ----------------------------------------------------------------//
				// --------------------------------------------------------------------------------------------------//

#ifdef IN_DEBUG_MODE_LEVEL_2
				mexPrintf("\nContactCFM1:\t%1.3f",contactPoint->m_contactCFM1);
#endif

				mxSetFieldByNumber(output[1],index,mxGetFieldNumber(output[1],"ContactCFM1"),
					MexUtilities::btScalar_to_mxArray(contactPoint->m_contactCFM1));



				// --------------------------------------------------------------------------------------------------//
				// setting field contact CFM 2 ----------------------------------------------------------------//
				// --------------------------------------------------------------------------------------------------//

#ifdef IN_DEBUG_MODE_LEVEL_2
				mexPrintf("\nContactCFM2:\t%1.3f",contactPoint->m_contactCFM2);
#endif

				mxSetFieldByNumber(output[1],index,mxGetFieldNumber(output[1],"ContactCFM2"),
					MexUtilities::btScalar_to_mxArray(contactPoint->m_contactCFM2));

/*
				// setting field life time ----------------------------------------------------------------//
				arraySize[0]=1;
				arraySize[1]=1;

				fieldValue = mxCreateNumericArray(2,arraySize,mxINT32_CLASS,mxREAL);

				//bool *pFielValue2 = (bool *)mxGetData(fieldValue);

				//pFielValue[0]=contactPoint->m_lateralFrictionInitialized;
				*(int *)mxGetData(fieldValue)=contactPoint->m_lifeTime;

#ifdef IN_DEBUG_MODE_LEVEL_1
				mexPrintf("\nLateralFrictionInitialized:\t%index",contactPoint->m_lifeTime);
#endif

				mxSetFieldByNumber(output[1],index,mxGetFieldNumber(output[1],"LateralFrictionInitialized"),fieldValue);

*/


				// --------------------------------------------------------------------------------------------------//
				// setting field lateral friction dir 1 ----------------------------------------------------------------//
				// --------------------------------------------------------------------------------------------------//

#ifdef IN_DEBUG_MODE_LEVEL_2
				mexPrintf("\nLateralFrictionDirection1:\t%1.3f\t%1.3f\t%1.3f",contactPoint->m_lateralFrictionDir1.getX(),
					contactPoint->m_lateralFrictionDir1.getY(),contactPoint->m_lateralFrictionDir1.getZ());
#endif

				mxSetFieldByNumber(output[1],index,mxGetFieldNumber(output[1],"LateralFrictionDirection1"),
					MexUtilities::btVector3_to_mxArray(contactPoint->m_lateralFrictionDir1));


				// --------------------------------------------------------------------------------------------------//
				// setting field lateral friction dir 2 ----------------------------------------------------------------//
				// --------------------------------------------------------------------------------------------------//

#ifdef IN_DEBUG_MODE_LEVEL_2
				mexPrintf("\nLateralFrictionDirection2:\t%1.3f\t%1.3f\t%1.3f\n",contactPoint->m_lateralFrictionDir2.getX(),
					contactPoint->m_lateralFrictionDir2.getY(),contactPoint->m_lateralFrictionDir2.getZ());
#endif

				mxSetFieldByNumber(output[1],index,mxGetFieldNumber(output[1],"LateralFrictionDirection2"),
					MexUtilities::btVector3_to_mxArray(contactPoint->m_lateralFrictionDir2));



				// increasing index count
				index++;
			}

		}
		else
		{

#ifdef IN_DEBUG_MODE_LEVEL_2
		
			printMethodCallDetails("collisionPairTest",SOLID_COLLISION_PAIR_TEST);
			mexPrintf("\nCreating 1 x 1 empty return structure");

#endif
			// create empty structure
			mwSize arraySize[2];
			arraySize[0]=1;
			arraySize[1]=1;
			output[1]= mxCreateStructArray(2,arraySize,NumberOfContactStructureFields,FieldNames);

#ifdef IN_DEBUG_MODE_LEVEL_2
			
			mexPrintf("\nSuccessfully created return structure\n");

#endif

		}

	}

#ifdef IN_DEBUG_MODE_LEVEL_2

	mexPrintf("\nExiting collisionPairTest\n");

#endif

}


// -------------------------------------------------------------------------------------------- //
void Solid::setTransform(const mxArray *transform)
{
	
	
	if(IsDynamic==1) // this command can only be issued if the body is in kinematic mode
		return;

	/*
	// creating pointer to input data
	btScalar *transformPtr = (btScalar *)mxGetData(transform);
	
	// retrieving the array size 
	mwSize rows=mxGetM(transform);
	mwSize columns=mxGetN(transform);

	// input array must be a 4 by 4 matrix
	if((rows!=4)&&(columns!=4))
		return;

	// creating basis
	btMatrix3x3 rotationMatrix(transformPtr[0],transformPtr[4],transformPtr[8],transformPtr[1],transformPtr[5],transformPtr[9],transformPtr[2],transformPtr[6],transformPtr[10]);

	Transform->setBasis(rotationMatrix);

#ifdef IN_DEBUG_MODE_LEVEL_2
	mexPrintf("[%1.4f\t%1.4f\t%1.4f]\n",Transform->getBasis().getRow(0).getX(),Transform->getBasis().getRow(0).getY(),Transform->getBasis().getRow(0).getZ());
	mexPrintf("[%1.4f\t%1.4f\t%1.4f]\n",Transform->getBasis().getRow(1).getX(),Transform->getBasis().getRow(1).getY(),Transform->getBasis().getRow(1).getZ());
	mexPrintf("[%1.4f\t%1.4f\t%1.4f]\n",Transform->getBasis().getRow(2).getX(),Transform->getBasis().getRow(2).getY(),Transform->getBasis().getRow(2).getZ());
#endif

	// setting translation transform data
	Transform->getOrigin().setX(transformPtr[12]);
	Transform->getOrigin().setY(transformPtr[13]);
	Transform->getOrigin().setZ(transformPtr[14]);
	*/

	*Transform = MexUtilities::mxArray_to_btTransform(transform);


	*Transform*=COGTransform;

	RigidBody->getMotionState()->setWorldTransform(*Transform);
	

	



}

// -------------------------------------------------------------------------------------------- //
void Solid::addConstraint(const mxArray* handle,const mxArray* inputs[])
{
	// retrieving connecting solid
	Solid* adjacentBody = Solid::get_object_pointer(handle);

	// retrieving integer that indicates constraint type
	int constraintType=MexUtilities::mxArray_to_int(inputs[0]);

	switch(constraintType)
	{
	case REVOLUTE:
		// extracting data

		break;
	case UNIVERSAL:

		break;
	case SPHERICAL:

		break;

	default:

		mexPrintf("This type of joint is not supported\n");
		break;
	}


}

// -------------------------------------------------------------------------------------------- //
void Solid::updateTransform()
{



	RigidBody->getMotionState()->getWorldTransform(*Transform);
	
	// multiplying by inverse of center of gravity transform
	*Transform*=COGTransform.inverse();
	

}
// -------------------------------------------------------------------------------------------- //
void Solid::setDynamic(int isDynamic)
{

	
	if(isDynamic==0) // kinematic
	{
		RigidBody->setCollisionFlags(RigidBody->getCollisionFlags()|btCollisionObject::CF_KINEMATIC_OBJECT);
		RigidBody->setActivationState(DISABLE_DEACTIVATION);
	}	
	/*else if(isDynamic<0) 
	{
		RigidBody->setCollisionFlags(RigidBody->getCollisionFlags()& btCollisionObject::CF_STATIC_OBJECT);
		//RigidBody->setActivationState(WANTS_DEACTIVATION);
	}*/
	


	IsDynamic=isDynamic;
}

// -------------------------------------------------------------------------------------------- //
void Solid::printProperties()
{

	// setting quaternion values

	Quaternion[0]=Transform->getRotation().getX();
	Quaternion[1]=Transform->getRotation().getY();
	Quaternion[2]=Transform->getRotation().getZ();
	Quaternion[3]=Transform->getRotation().getW();

	// setting postion values

	Position[0]=Transform->getOrigin().getX();
	Position[1]=Transform->getOrigin().getY();
	Position[2]=Transform->getOrigin().getZ();
	


	updateTransform();
	mexPrintf("Solid Object Properties:\n");
	mexPrintf("Geometry Type\t\t:	%s\n",GeometryType.c_str());
	mexPrintf("GeometryID\t\t:\t[ %i]\n",GeometryId);
	mexPrintf("Position\t\t:\t[ %1.3f, %1.3f, %1.3f]\n",Position[0],Position[1],Position[2]);
	mexPrintf("Quaternion\t\t:\t[ %1.3f, %1.3f, %1.3f, %1.3f]\n",Quaternion[0],Quaternion[1],Quaternion[2],Quaternion[3]);
	mexPrintf("Dimensions\t\t:\t[ %1.3f, %1.3f, %1.3f]\n",Dimensions[0],Dimensions[1],Dimensions[2]);
	mexPrintf("Mass\t\t\t:\t[ %1.3f]\n",Mass);
	mexPrintf("IsDynamic\t\t:\t[ %i]\n",IsDynamic);

	if(GeometryId==TRIMESH)
	{
		mexPrintf("Number of Faces\t:\t[ %i 3]\n",NumFaces);
		mexPrintf("Number of Vertices\t:\t[ %i 3]\n",NumVertices);
	}


}

// -------------------------------------------------------------------------------------------- //
void Solid::printTrimesh()
{
	mexPrintf("------------------------------------------------------------\n"); 
	mexPrintf("Start of Vertices Data:\n");
	mexPrintf("rows\t:\t%i\n",NumVertices);
	mexPrintf("columns\t:\t%i\n",3);
	int ind = 0;
	for(int i=0;i<NumVertices;i++)
	{
		mexPrintf("\n");
		for(int j=0;j<3;j++)
		{
			mexPrintf("\t%1.4f",Vertices[ind]);
			ind++;
		}
	}

	mexPrintf("\nEnd of Vertices Data:\n");
	mexPrintf("------------------------------------------------------------\n"); 

	mexPrintf("------------------------------------------------------------\n"); 
	mexPrintf("Start of Faces Data:\n");
	mexPrintf("rows\t:\t%i\n",NumFaces);
	mexPrintf("columns\t:\t%i\n",3);
	ind = 0;
	for(int i=0;i<NumFaces;i++)
	{
		mexPrintf("\n");
		for(int j=0;j<3;j++)
		{
			mexPrintf("\t%i",Faces[ind]);
			ind++;
		}
	}

	mexPrintf("\nEnd of Faces Data:\n");
	mexPrintf("------------------------------------------------------------\n"); 

}

// -------------------------------------------------------------------------------------------- //
void Solid::printMethodCallDetails(const string &methodName,int methodIndex)
{

	mexPrintf("Class\t\t\t:\t%s\n","Solid");
	mexPrintf("Method Call\t\t:\t%s\n",methodName.c_str());
	mexPrintf("Method Index\t\t:\t%i\n",methodIndex);
}




/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// constructor helpers
void Solid::constructBox(const mxArray *input)
{
		
#ifdef IN_DEBUG_MODE_LEVEL_1
	mexPrintf("\nSolid Object Shape:\tBox\n");
#endif
	
	
		// populating all geometric and triangulation attributes
		populateTriangulationAttributes(input);


		// retrieving dimensions vector
		btVector3 dimensions=MexUtilities::mxArray_to_btVector3(input,mwIndex(0),"Dimensions");

		/*
		Dimensions[0]=dimensions.getX();
		Dimensions[1]=dimensions.getY();
		Dimensions[2]=dimensions.getZ();
		*/

		// scaling dimensions to 1 half
		dimensions*=(btScalar(0.5f));
		
		
		
		// constructing collision shape
		CollisionShape = new btBoxShape(dimensions);		
		

		// obtaining position
		btVector3 position=MexUtilities::mxArray_to_btVector3(input,mwIndex(0),"Position");

		// obtaining orientation
		btQuaternion quaternion=MexUtilities::mxArray_to_btQuaternion(input,mwIndex(0),"Quaternion");

		// creating homogeneous transform
		Transform = new btTransform(quaternion,position);

		// instantiating motion state
		MotionState = new btDefaultMotionState(*Transform);

		// get mass
		Mass=MexUtilities::mxArray_to_btScalar(input,mwIndex(0),"Mass");		

		// computing inertia
		Inertia = btVector3(0,0,0);
		CollisionShape->calculateLocalInertia(Mass,Inertia);

		// obtaining isDynamic property
		int isDynamic = MexUtilities::mxArray_to_int(input,mwIndex(0),"IsDynamic");

		// constructing rigid body construction info object
		btScalar mass;
		btVector3 inertia;
		if(isDynamic != 0)
		{
			mass=Mass;
			inertia=Inertia;
		}
		else
		{
			mass = btScalar(0);
			inertia= btVector3(0,0,0);
		}

		 btRigidBody::btRigidBodyConstructionInfo bodyCI(mass,MotionState,CollisionShape,inertia);

		// instantiating rigid body
		RigidBody = new btRigidBody(bodyCI);

		setDynamic(isDynamic);

		
}

// -------------------------------------------------------------------------------------------- //
void Solid::constructSphere(const mxArray *input)
{

#ifdef IN_DEBUG_MODE_LEVEL_1
	mexPrintf("\nSolid Object Shape:\tSphere\n");
#endif
	
	/*
	// retrieving dimensions vector
	btVector3 dimensions=MexUtilities::mxArray_to_btVector3(input,mwIndex(0),"Dimensions");
	// scaling dimensions to 1 half
	Dimensions[0]=dimensions.getX();
	Dimensions[1]=dimensions.getY();
	Dimensions[2]=dimensions.getZ();
	*/

	// populating all geometric and triangulation attributes
	populateTriangulationAttributes(input);
	
	// retrieving radius
	btScalar radius=MexUtilities::mxArray_to_btScalar(input,mwIndex(0),"Radius");
	
	// constructing collision shape
	CollisionShape = new btSphereShape(radius);

	// obtaining position
	btVector3 position = MexUtilities::mxArray_to_btVector3(input,mwIndex(0),"Position");

	// obtaining quaternion
	btQuaternion quaternion = MexUtilities::mxArray_to_btQuaternion(input,mwIndex(0),"Quaternion");

	// instantiating homogeneous transfomr
	Transform = new btTransform(quaternion,position);

	// instantiating motion state
	MotionState = new btDefaultMotionState(*Transform);

	// get mass
	Mass=MexUtilities::mxArray_to_btScalar(input,mwIndex(0),"Mass");		

	// computing inertia
	Inertia = btVector3(0,0,0);
	CollisionShape->calculateLocalInertia(Mass,Inertia);

	// obtaining isDynamic property
	int isDynamic = MexUtilities::mxArray_to_int(input,mwIndex(0),"IsDynamic");

	// constructing rigid body construction info object
	btScalar mass;
	btVector3 inertia;
	if(isDynamic != 0)
	{
		mass=Mass;
		inertia=Inertia;
	}
	else
	{
		mass = btScalar(0);
		inertia= btVector3(0,0,0);
	}

	 btRigidBody::btRigidBodyConstructionInfo bodyCI(mass,MotionState,CollisionShape,inertia);

	// instantiating rigid body
	RigidBody = new btRigidBody(bodyCI);

	setDynamic(isDynamic);

}

// -------------------------------------------------------------------------------------------- //
void Solid::constructTrimesh(const mxArray *input)
{
	
#ifdef IN_DEBUG_MODE_LEVEL_1
	mexPrintf("\nSolid Object Shape:\tTrimesh\n");
	mexPrintf("\nStarting construction of Trimesh Data");
#endif
	
	/*

	// retrieving dimensions vector
	btVector3 dimensions=MexUtilities::mxArray_to_btVector3(input,mwIndex(0),"Dimensions");
	// scaling dimensions to 1 half
	Dimensions[0]=dimensions.getX();
	Dimensions[1]=dimensions.getY();
	Dimensions[2]=dimensions.getZ();

	// retrieving triangle index vertex array
//	 TrimeshData= Solid::extract_btTriangleIndexVertexArray(input,mwIndex(0));



	// retrieving faces data
	Faces=MexUtilities::mxArray_to_int_array(input,mwIndex(0));

	// retrieving faces size
	NumFaces=MexUtilities::mxArray_row_size(input,mwIndex(0));

	// retrieving vertices data
	Vertices=MexUtilities::mxArray_to_float_array(input,mwIndex(0));

	// retrieving vertices size
	NumVertices=MexUtilities::mxArray_column_size(input,mwIndex(0));

	// retreiving cog
	COG = MexUtilities::mxArray_to_btVector3(input,mwIndex(0),"COG");

	// offsetting vertices data by cog
	
	for(int i=0;i<NumVertices;i++)
	{
		Vertices[i*3]=Vertices[i*3]-COG.getX();
		Vertices[i*3+1]=Vertices[i*3+1]-COG.getY();
		Vertices[i*3+2]=Vertices[i*3+2]-COG.getZ();
	}
	

	// creating trimesh data 
	TrimeshData = new btTriangleIndexVertexArray(NumFaces,Faces,3*sizeof(int),NumVertices,Vertices,3*sizeof(btScalar));
	*/

	// populating all geometric and triangulation attributes
	populateTriangulationAttributes(input);
	

	// creating trimesh convex decomposition object when using normal configuration
#ifdef USE_DEFAULT_COLLISION

	// construction global pointer to resulting compound shape
	btCompoundShape *parentShape;

	// instantiating a static mesh in order to determine if it is concave or convex
	btCollisionShape *tempShape =new btBvhTriangleMeshShape(TrimeshData,true,true);

	if(tempShape->isConcave())
	{
	
#ifdef IN_DEBUG_MODE_LEVEL_1

		mexPrintf("\nCreating TrimeshConvexDecomposition Object");

#endif
		TrimeshConvexDecomposition trimeshDecomposition(NumFaces,Faces,NumVertices,Vertices);


	

		parentShape = trimeshDecomposition.computeConvexDecomposition();

#ifdef IN_DEBUG_MODE_LEVEL_1
		mexPrintf("\nStoring Compound Shape");
#endif

		
		
		
		
		// trimesh data not needed
		delete TrimeshData;
		TrimeshData= NULL;

		
	}
	else
	{

		// building compound shape first in order to make it possible to compute the inertia from the cog
		
		btConvexTriangleMeshShape *childShape = new btConvexTriangleMeshShape(TrimeshData,true);
		btTransform trans;
		trans.setIdentity();
		//trans.setOrigin((trans.getOrigin()-cog));

		parentShape = new btCompoundShape(false);
		parentShape->addChildShape(trans,childShape);

	}
	// deleting temporary shape
	delete tempShape;


	
#endif

	
	
#ifdef USE_GIMPACT_COLLISION
	
	

#ifdef IN_DEBUG_MODE_LEVEL_2

	printTrimesh();

#endif
	
	// instantiating collision shape
	
	btGImpactMeshShape *parentShape = new btGImpactMeshShape(TrimeshData);
	parentShape->updateBound();


	//CollisionShape=trimesh;

#endif



	// setting collision shape
	CollisionShape=parentShape;

	// obtaining position
	btVector3 position = MexUtilities::mxArray_to_btVector3(input,mwIndex(0),"Position");

	// obtaining quaternion
	btQuaternion quaternion = MexUtilities::mxArray_to_btQuaternion(input,mwIndex(0),"Quaternion");

	//
	Transform = new btTransform(quaternion,position);

	// creagin cog transform
	btTransform cogTransform;
	cogTransform.setIdentity();
	cogTransform.setOrigin(COG);

	// instantiating motion state
	MotionState = new btDefaultMotionState((*Transform)*cogTransform);


	// get mass
	Mass=MexUtilities::mxArray_to_btScalar(input,mwIndex(0),"Mass");		

	// computing inertia at the cog
	Inertia = btVector3(0,0,0);
	CollisionShape->calculateLocalInertia(Mass,Inertia);

	// obtaining isDynamic property
	int isDynamic = MexUtilities::mxArray_to_int(input,mwIndex(0),"IsDynamic");

	// constructing rigid body construction info object
	btScalar mass;
	btVector3 inertia;
	if(isDynamic != 0)
	{
		mass=Mass;
		inertia=Inertia;
	}
	else
	{
		mass = btScalar(0);
		inertia= btVector3(0,0,0);
	}

	 btRigidBody::btRigidBodyConstructionInfo bodyCI(mass,MotionState,CollisionShape,inertia);


	// instantiating rigid body
	RigidBody = new btRigidBody(bodyCI);
	
	setDynamic(isDynamic);


}
// -------------------------------------------------------------------------------------------- //
void Solid::constructStaticTrimesh(const mxArray *input)
{
#ifdef IN_DEBUG_MODE_LEVEL_1
	mexPrintf("\nSolid Object Shape:\tTrimesh\n");
	mexPrintf("\nStarting construction of Trimesh Data");
#endif
	
	
	/*
	// retrieving dimensions vector
	btVector3 dimensions=MexUtilities::mxArray_to_btVector3(input,mwIndex(0),"Dimensions");
	// scaling dimensions to 1 half
	Dimensions[0]=dimensions.getX();
	Dimensions[1]=dimensions.getY();
	Dimensions[2]=dimensions.getZ();

	// retrieving triangle index vertex array
//	 TrimeshData= Solid::extract_btTriangleIndexVertexArray(input,mwIndex(0));



	// retrieving faces data
	Faces=MexUtilities::mxArray_to_int_array(input,mwIndex(0));

	// retrieving faces size
	NumFaces=MexUtilities::mxArray_row_size(input,mwIndex(0));

	// retrieving vertices data
	Vertices=MexUtilities::mxArray_to_float_array(input,mwIndex(0));

	// retrieving vertices size
	NumVertices=MexUtilities::mxArray_column_size(input,mwIndex(0));

	// retreiving cog
	COG = MexUtilities::mxArray_to_btVector3(input,mwIndex(0),"COG");

	// offsetting vertices data by cog
	
	for(int i=0;i<NumVertices;i++)
	{
		Vertices[i*3]=Vertices[i*3]-COG.getX();
		Vertices[i*3+1]=Vertices[i*3+1]-COG.getY();
		Vertices[i*3+2]=Vertices[i*3+2]-COG.getZ();
	}
	

	// creating trimesh data 
	TrimeshData = new btTriangleIndexVertexArray(NumFaces,Faces,3*sizeof(int),NumVertices,Vertices,3*sizeof(btScalar));

	*/

	// populating all geometric and triangulation attributes
	populateTriangulationAttributes(input);


	

	// creating trimesh convex decomposition object when using normal configuration
#ifdef USE_DEFAULT_COLLISION

	// instantiating a static mesh in order to determine if it is concave or convex
	btCollisionShape *parentShape =new btBvhTriangleMeshShape(TrimeshData,true,true);


#endif

	

#ifdef USE_GIMPACT_COLLISION
	
	

#ifdef IN_DEBUG_MODE_LEVEL_2

	printTrimesh();

#endif
	
	// instantiating collision shape
	
	btGImpactMeshShape *parentShape = new btGImpactMeshShape(TrimeshData);
	parentShape->updateBound();


	//CollisionShape=trimesh;

#endif




	// setting collision shape
	CollisionShape=parentShape;

	// obtaining position
	btVector3 position = MexUtilities::mxArray_to_btVector3(input,mwIndex(0),"Position");

	// obtaining quaternion
	btQuaternion quaternion = MexUtilities::mxArray_to_btQuaternion(input,mwIndex(0),"Quaternion");

	//
	Transform = new btTransform(quaternion,position);

	// creagin cog transform
	btTransform cogTransform;
	cogTransform.setIdentity();
	cogTransform.setOrigin(COG);

	// instantiating motion state
	MotionState = new btDefaultMotionState((*Transform)*cogTransform);


	// get mass
	Mass=MexUtilities::mxArray_to_btScalar(input,mwIndex(0),"Mass");		

	// computing inertia at the cog
	Inertia = btVector3(0,0,0);
	CollisionShape->calculateLocalInertia(Mass,Inertia);

	// obtaining isDynamic property
	int isDynamic = MexUtilities::mxArray_to_int(input,mwIndex(0),"IsDynamic");

	// constructing rigid body construction info object
	btScalar mass;
	btVector3 inertia;

	mass = btScalar(0);
	inertia= btVector3(0,0,0);
	

	 btRigidBody::btRigidBodyConstructionInfo bodyCI(mass,MotionState,CollisionShape,inertia);


	// instantiating rigid body
	RigidBody = new btRigidBody(bodyCI);
	
	//setDynamic(isDynamic);

}
// -------------------------------------------------------------------------------------------- //
void Solid::constructStaticPlane(const mxArray *input)
{
	
#ifdef IN_DEBUG_MODE_LEVEL_1
	mexPrintf("\nSolid Object Shape:\tStaticPlane\n");
#endif

	// populating all geometric and triangulation attributes
	populateTriangulationAttributes(input);


	// setting plane dimensions equal to zero
	Dimensions[0]=0;
	Dimensions[1]=0;
	Dimensions[2]=0;


	// retrieving normal vector
	btVector3 normalVector=MexUtilities::mxArray_to_btVector3(input,mwIndex(0),"PlaneNormal");

	btScalar planeConstant=MexUtilities::mxArray_to_btScalar(input,mwIndex(0),"PlaneConstant");

#ifdef IN_DEBUG_MODE_LEVEL_2

	mexPrintf("Constructed StaticPlane with the following properties\n");
	mexPrintf("NormalVector\t\t:\t[ %1.3f, %1.3f, %1.3f]\n",normalVector.getX(),normalVector.getY(),normalVector.getZ());
	mexPrintf("NormalConstant\t\t:\t[ %1.3f]\n",planeConstant);
	mexPrintf("------------------------------------------------------------\n");

#endif
	
	// constructing collision shape
	CollisionShape = new btStaticPlaneShape(normalVector,planeConstant);

	// obtaining position
	//btVector3 position = MexUtilities::mxArray_to_btVector3(input,mwIndex(0),"Position");

	// obtaining quaternion
	//btQuaternion quaternion = MexUtilities::mxArray_to_btQuaternion(input,mwIndex(0),"Quaternion");

	// instantiating homogeneous transfomr
	Transform = new btTransform();

	Transform->setIdentity();

	// instantiating motion state
	MotionState = new btDefaultMotionState(*Transform);

	// get mass
	Mass=MexUtilities::mxArray_to_btScalar(input,mwIndex(0),"Mass");		

	// computing inertia
	Inertia = btVector3(0,0,0);
	CollisionShape->calculateLocalInertia(Mass,Inertia);

	// obtaining isDynamic property
	int isDynamic = MexUtilities::mxArray_to_int(input,mwIndex(0),"IsDynamic");

	// constructing rigid body construction info object
	btScalar mass;
	btVector3 inertia;
	if(isDynamic != 0)
	{
		mass=Mass;
		inertia=Inertia;
	}
	else
	{
		mass = btScalar(0);
		inertia= btVector3(0,0,0);
	}

	 btRigidBody::btRigidBodyConstructionInfo bodyCI(mass,MotionState,CollisionShape,inertia);

	// instantiating rigid body
	RigidBody = new btRigidBody(bodyCI);

	//setDynamic(isDynamic);
}


void Solid::populateTriangulationAttributes(const mxArray *input)
{

	
	// retrieving dimensions vector
	btVector3 dimensions=MexUtilities::mxArray_to_btVector3(input,mwIndex(0),"Dimensions");
	// scaling dimensions to 1 half
	Dimensions[0]=dimensions.getX();
	Dimensions[1]=dimensions.getY();
	Dimensions[2]=dimensions.getZ();


	// retrieving faces data
	Faces=MexUtilities::mxArray_to_int_array(input,mwIndex(0));

	// retrieving faces size
	NumFaces=MexUtilities::mxArray_row_size(input,mwIndex(0));

	// retrieving vertices data
	Vertices=MexUtilities::mxArray_to_float_array(input,mwIndex(0));

	// retrieving vertices size
	NumVertices=MexUtilities::mxArray_column_size(input,mwIndex(0));

	// retreiving cog
	COG = MexUtilities::mxArray_to_btVector3(input,mwIndex(0),"COG");

	// offsetting vertices data by cog
	
	for(int i=0;i<NumVertices;i++)
	{
		Vertices[i*3]=Vertices[i*3]-COG.getX();
		Vertices[i*3+1]=Vertices[i*3+1]-COG.getY();
		Vertices[i*3+2]=Vertices[i*3+2]-COG.getZ();
	}
	

	// creating trimesh data 
	TrimeshData = new btTriangleIndexVertexArray(NumFaces,Faces,3*sizeof(int),NumVertices,Vertices,3*sizeof(btScalar));

}






/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Handle manipulation functions
void Solid::create_handle(int nargin,const mxArray *inputs[],mxArray **output)
{
	
	
	
	Solid *solid= new Solid(inputs[CONSTRUCTION_DATA_INDEX]);
	//mexPrintf("Created pointer to Solid Object, pointer value= %#x, \n",solid);
	ObjectHandle<Solid> *handle = new ObjectHandle<Solid>(solid);
	
	*output=handle->to_mex_handle();

#ifdef IN_DEBUG_MODE_LEVEL_1
	/*mexPrintf("------------------------------------------------------------\n");
	mexPrintf("Created handle to pointer to Solid Object, new pointer value= %#x, \n",solid);
	*/
#endif

}
// -------------------------------------------------------------------------------------------- //
void Solid::destroy_handle(const mxArray *handle) // handle=prhs[2]
{
	destroy_object<Solid>(handle);
}

// -------------------------------------------------------------------------------------------- //
Solid* Solid::get_object_pointer(const mxArray *handle)
{
	Solid &solid=get_object<Solid>(handle);
	return &solid;
}

// -------------------------------------------------------------------------------------------- //
void Solid::method_selector(int nargin,const mxArray *inputs[],int nargout,mxArray *outputs[])
{
		
	// declaring Solid Pointer
	static Solid *solidPointer;
	
	
	
	// checking that the method identifier index is of an integer data type
	if(!mxIsInt8(inputs[METHOD_IDENTIFIER_INDEX])&&!mxIsInt16(inputs[METHOD_IDENTIFIER_INDEX])&&!mxIsInt32(inputs[METHOD_IDENTIFIER_INDEX])&&!mxIsInt64(inputs[METHOD_IDENTIFIER_INDEX]))
	{
		mexErrMsgTxt("must pass a integer data type for the method identifier index\n");
		return;
	}

	// getting an int pointer to the method identifier index
	int *function_index=(int *)mxGetData(inputs[METHOD_IDENTIFIER_INDEX]);

	// obtaining the pointer to the SimplePhysicsEnvironment object
	if(*function_index!=SOLID_CONSTRUCTOR)
	{
			solidPointer=Solid::get_object_pointer(inputs[HANDLE_IDENTIFIER_INDEX]);
			
	}


	// selecting method
	switch (*function_index)
	{
	case SOLID_CONSTRUCTOR:


#ifdef IN_DEBUG_MODE_LEVEL_2

		Solid::printMethodCallDetails("Constructor",SOLID_CONSTRUCTOR);		
		mexPrintf("------------------------------------------------------------\n");    	
		mexPrintf("Start of \"Constructor\" method call\n\n");
#endif		
		//
		Solid::create_handle(nargin,inputs,&outputs[0]);


#ifdef IN_DEBUG_MODE_LEVEL_2
		mexPrintf("\nEnd of \"Constructor\" method call\n");
		mexPrintf("------------------------------------------------------------\n");   
#endif

		
		break;


	case SOLID_GET_ROTATION:

#ifdef IN_DEBUG_MODE_LEVEL_2
		
		Solid::printMethodCallDetails("getRotation()",SOLID_GET_ROTATION);

#endif

		solidPointer->getRotation(outputs);


		break;


	case SOLID_GET_POSITION:

#ifdef IN_DEBUG_MODE_LEVEL_2
		
		Solid::printMethodCallDetails("getPosition()",SOLID_GET_POSITION);

#endif
		
		
		solidPointer->getPosition(outputs);
		

		break;

	case SOLID_ADD_CONSTRAINT:

#ifdef IN_DEBUG_MODE_LEVEL_2
		
		Solid::printMethodCallDetails("addConstraint",SOLID_ADD_CONSTRAINT);
		mexPrintf("------------------------------------------------------------\n");    	
		mexPrintf("Start of \"addConstraint()\" method call\n\n");

#endif

		solidPointer->addConstraint(inputs[START_OF_INPUT_DATA_INDEX],inputs+START_OF_INPUT_DATA_INDEX+1);

#ifdef IN_DEBUG_MODE_LEVEL_2
	   	
	mexPrintf("\nEnd of \"addConstraint()\" method call\n");
	mexPrintf("------------------------------------------------------------\n"); 

#endif
		
	case SOLID_UPDATE_TRANSFORM:

#ifdef IN_DEBUG_MODE_LEVEL_2
		
		Solid::printMethodCallDetails("updateTransform",SOLID_UPDATE_TRANSFORM);
		mexPrintf("------------------------------------------------------------\n");    	
		mexPrintf("Start of \"updateTransform()\" method call\n\n");

#endif

		solidPointer->updateTransform();

#ifdef IN_DEBUG_MODE_LEVEL_2
	   	
	mexPrintf("\nEnd of \"updateTransform()\" method call\n");
	mexPrintf("------------------------------------------------------------\n"); 

#endif



		
		break;

	case SOLID_SET_TRANSFORM:

#ifdef IN_DEBUG_MODE_LEVEL_2
		
		Solid::printMethodCallDetails("setTransform",SOLID_SET_TRANSFORM);
		mexPrintf("------------------------------------------------------------\n");    	
		mexPrintf("Start of \"setTransform()\" method call\n\n");

#endif

		solidPointer->setTransform(inputs[START_OF_INPUT_DATA_INDEX]);

#ifdef IN_DEBUG_MODE_LEVEL_2
	   	
	mexPrintf("\nEnd of \"setTransform()\" method call\n");
	mexPrintf("------------------------------------------------------------\n"); 

#endif



		
		break;

	case SOLID_GET_TRANSFORM:

#ifdef IN_DEBUG_MODE_LEVEL_2
		
		Solid::printMethodCallDetails("getTransform",SOLID_GET_TRANSFORM);
		mexPrintf("------------------------------------------------------------\n");    	
		mexPrintf("Start of \"getTransform()\" method call\n\n");

#endif

		solidPointer->getTransform(outputs);

#ifdef IN_DEBUG_MODE_LEVEL_2
	   	
	mexPrintf("\nEnd of \"getTransform()\" method call\n");
	mexPrintf("------------------------------------------------------------\n"); 

#endif



		
		break;

	case SOLID_COLLISION_PAIR_TEST:

#ifdef IN_DEBUG_MODE_LEVEL_2
		
		Solid::printMethodCallDetails("collisionPairTest()",SOLID_COLLISION_PAIR_TEST);
		mexPrintf("------------------------------------------------------------\n");    	
		mexPrintf("Start of \"collisionPairTest()\" method call\n\n");

#endif

		solidPointer->collisionPairTest(inputs[START_OF_INPUT_DATA_INDEX],outputs,nargout);

#ifdef IN_DEBUG_MODE_LEVEL_2
	   	
	mexPrintf("\nEnd of \"collisionPairTest()\" method call\n");
	mexPrintf("------------------------------------------------------------\n"); 

#endif



		
		break;

	case SOLID_PRINT_PROPERTIES:

#ifdef IN_DEBUG_MODE_LEVEL_2

		Solid::printMethodCallDetails("printProperties()",SOLID_PRINT_PROPERTIES);
		mexPrintf("------------------------------------------------------------\n");    	
		mexPrintf("Start of \"printProperties()\" method call\n\n");
#endif
			
		solidPointer->printProperties();

#ifdef IN_DEBUG_MODE_LEVEL_2	   	
		mexPrintf("\nEnd of \"printProperties()\" method call\n");
		mexPrintf("------------------------------------------------------------\n"); 
#endif


		break;

	
		case SOLID_PRINT_TRIMESH:

#ifdef IN_DEBUG_MODE_LEVEL_2

		Solid::printMethodCallDetails("printTrimesh()",SOLID_PRINT_TRIMESH);
		mexPrintf("------------------------------------------------------------\n");    	
		mexPrintf("Start of \"printTrimesh()\" method call\n\n");
#endif
			
		solidPointer->printTrimesh();

#ifdef IN_DEBUG_MODE_LEVEL_2	   	
		mexPrintf("\nEnd of \"printTrimesh()\" method call\n");
		mexPrintf("------------------------------------------------------------\n"); 
#endif


		break;
	
	case SOLID_DESTRUCTOR:

#ifdef IN_DEBUG_MODE_LEVEL_2
		
		Solid::printMethodCallDetails("Destructor",SOLID_DESTRUCTOR);
		mexPrintf("------------------------------------------------------------\n");    	
		mexPrintf("Start of \"Destructor\" method call\n\n");
#endif

		// deletes the handle and the solid object to which the handle is associated with
		Solid::destroy_handle(inputs[HANDLE_IDENTIFIER_INDEX]);

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
// implementing properties for the ContactResultCallback
CustomContactResultCallback::CustomContactResultCallback()
{
	NumberOfContactPoints=0;
	Collided=false;
}


// -------------------------------------------------------------------------------------------- //
btScalar CustomContactResultCallback::addSingleResult(btManifoldPoint& cp,	
		const btCollisionObject* colObj0,int partId0,int index0,const btCollisionObject* colObj1,int partId1,int index1)
{
	if(!Collided)
	{
		Collided=true;
	}
	// creating copy of manifold point
	btManifoldPoint *contactPoint = new btManifoldPoint();
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


	// storing pointer to manifold in container	
	ContactPoints.push_back(contactPoint);
	
	// increasing count of detected contact points
	NumberOfContactPoints++;

#ifdef IN_DEBUG_MODE_LEVEL_2
	mexPrintf("\nContact # %i",NumberOfContactPoints);
	mexPrintf("\nPositionWorldOnA:\t%1.3f\t%1.3f\t%1.3f",cp.getPositionWorldOnA().getX(),
		cp.getPositionWorldOnA().getY(),cp.getPositionWorldOnA().getZ());
#endif



#ifdef IN_DEBUG_MODE_LEVEL_2
	mexPrintf("\nCall to CustomContactResultCallback::addSingleResuslt\n");
#endif

	return (btScalar)NumberOfContactPoints;
}


// -------------------------------------------------------------------------------------------- //
CustomContactResultCallback::~CustomContactResultCallback()
{
	// destroying all copies of manifold point

	if(NumberOfContactPoints == 0)
	{
		return;

	}

	for(vector<btManifoldPoint*>::iterator i=ContactPoints.begin();i!=ContactPoints.end();i++)
	{
		btManifoldPoint *contactPoint = *i;

		if(contactPoint!=NULL)
		{
			delete contactPoint;
#ifdef IN_DEBUG_MODE_LEVEL_2
		mexPrintf("\nDeleted manifold point");
#endif
		}

	}
}








