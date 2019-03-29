

// this is a simple class that encapsulates all of the details required to implement the basic functionality of a physics environment

//#include "mexFunction.h"
#include "SimplePhysicsEnvironment.h"
#include "ObjectHandle.h"






// -------------------------------------------------------------------------------------------- //
SimplePhysicsEnvironment::SimplePhysicsEnvironment(const mxArray* input[])  // input=prhs[2]
{
	
	

#ifdef IN_DEBUG_MODE_LEVEL_1
	mexPrintf("\n\n------------------------------------------------------------");
	mexPrintf("\n------Simple Physics Environment Object Construction-------");
	mexPrintf("\n------------------------------------------------------------\n");
#endif
	// initializing bullet collision and dynamic obj

	CollisionConfiguration = new btDefaultCollisionConfiguration();
	Dispatcher = new btCollisionDispatcher(CollisionConfiguration);
	Broadphase = new btDbvtBroadphase();
	Solver = new btSequentialImpulseConstraintSolver();

	DynamicsWorld = new btDiscreteDynamicsWorld(Dispatcher,Broadphase,Solver,CollisionConfiguration);


	//GravityVector = btVector3(0,0,-10);
	GravityVector = MexUtilities::mxArray_to_btVector3(input[0],mwIndex(0),"Gravity");

	DynamicsWorld->setGravity(GravityVector);

#ifdef IN_DEBUG_MODE_LEVEL_1
	mexPrintf("\nSimplePhysicsEnvironment Object created\n");
#endif


	// registering the collision algorithm is necessary when using gimpact

#ifdef USE_GIMPACT_COLLISION
	btCollisionDispatcher *dispatcher = static_cast<btCollisionDispatcher *>(DynamicsWorld ->getDispatcher());
	btGImpactCollisionAlgorithm::registerAlgorithm(dispatcher);
#endif

	// instantiating simulator
	Simulator = new SimulationManager(DynamicsWorld,Broadphase,Dispatcher,CollisionConfiguration,Solver);

#ifdef IN_DEBUG_MODE_LEVEL_1

	mexPrintf("\n\n------------------------------------------------------------");
	mexPrintf("\n---End Of Simple Physics Environment Object Construction----");
	mexPrintf("\n------------------------------------------------------------\n");
#endif



}

// -------------------------------------------------------------------------------------------- //
SimplePhysicsEnvironment::~SimplePhysicsEnvironment()
{

	
	releaseData();

#ifdef IN_DEBUG_MODE_LEVEL_1
	mexPrintf("SimplePhysicsEnvironment Object destroyed\n");
#endif
		

}


// -------------------------------------------------------------------------------------------- //
// -------------------------------------------------------------------------------------------- //
void SimplePhysicsEnvironment::stepSimulation()
{

	Simulator->stepSimulation();

}

void SimplePhysicsEnvironment::initializeSimulation()
{

	Simulator->clientResetScene();  // this is needed in order to reset internal data
	
}

// -------------------------------------------------------------------------------------------- //
// -------------------------------------------------------------------------------------------- //
void SimplePhysicsEnvironment::resetSimulation()
{

	Simulator->resetSimulation();

}


// -------------------------------------------------------------------------------------------- //
// -------------------------------------------------------------------------------------------- //
void SimplePhysicsEnvironment::startSimulation()
{
	Simulator->startSimulation();
}


// -------------------------------------------------------------------------------------------- //
// -------------------------------------------------------------------------------------------- //
void SimplePhysicsEnvironment::pauseSimulation()
{
	Simulator->pauseSimulation();
}


// -------------------------------------------------------------------------------------------- //
// -------------------------------------------------------------------------------------------- //
void SimplePhysicsEnvironment::resumeSimulation()
{
	Simulator->resumeSimulation();
}

// -------------------------------------------------------------------------------------------- //
// -------------------------------------------------------------------------------------------- //
void SimplePhysicsEnvironment::stopSimulation()
{
	Simulator->stopSimulation();
}



// -------------------------------------------------------------------------------------------- //
void SimplePhysicsEnvironment::releaseData()
{

	
	if(Simulator!=NULL)
	{
#ifdef IN_DEBUG_MODE_LEVEL_1
		mexPrintf("\nDeleting Simulator\n");
#endif
		delete Simulator;
	}

	// removing GroundObject rigid body from the dynamics world
	if(GroundObject!=NULL)
			DynamicsWorld->removeRigidBody(GroundObject->RigidBody);

#ifdef IN_DEBUG_MODE_LEVEL_1
			mexPrintf("Ground Object Removed from Physics Enviroment\n");
#endif
	
	// removing solid objects from the environment

	//for(vector< const mxArray* >::iterator i=SolidHandles.begin();i!=SolidHandles.end();++i)
	//for(vector<Solid *>::iterator i=SolidContainer.begin();i!=SolidContainer.end();i++)
	//for(int i=0;i!=SolidContainer.size();i++)
	for(vector<Solid*>::iterator i=SolidContainer.begin();i!=SolidContainer.end();i++)
	{
		
		

		
		
		
		// removing rigid body from dynamics world
		//Solid* solid=Solid::get_object_pointer(*i);
		//Solid* solid=*i;
		//Solid* solid=SolidContainer[i];
		Solid* solid = *i;

		if(solid!=NULL)
		{

			DynamicsWorld->removeRigidBody(solid->RigidBody);
			

#ifdef IN_DEBUG_MODE_LEVEL_1
			mexPrintf("Solid Object Removed from Physics Enviroment\n");
#endif
			// destroying object associated with handle and 
			//Solid::destroy_handle(*i);

		}


		
		


	}


	// removing additional bodies( shot geometries )
	for (int i=DynamicsWorld->getNumCollisionObjects()-1; i>=0 ;i--)
	{
		btCollisionObject* obj = DynamicsWorld->getCollisionObjectArray()[i];
		btRigidBody* body = btRigidBody::upcast(obj);
		if (body && body->getMotionState())
		{
			delete body->getMotionState();
		}
		DynamicsWorld->removeCollisionObject( obj );
		delete obj;
	}

	
	//delete GroundShape;

#ifdef IN_DEBUG_MODE_LEVEL_1
	mexPrintf("\nDeleting Dynamics World");
#endif
	delete DynamicsWorld;

#ifdef IN_DEBUG_MODE_LEVEL_1
	mexPrintf("\nDeleting Solver");
#endif
	delete Solver;

#ifdef IN_DEBUG_MODE_LEVEL_1
	mexPrintf("\nDeleting Broadphase");
#endif
	delete Broadphase;

#ifdef IN_DEBUG_MODE_LEVEL_1
	mexPrintf("\nDeleting Dispatcher");
#endif
	delete Dispatcher;

#ifdef IN_DEBUG_MODE_LEVEL_1
	mexPrintf("\nDeleting Collision Configuration\n");
#endif
	delete CollisionConfiguration;

	

}

// -------------------------------------------------------------------------------------------- //
void SimplePhysicsEnvironment::addBody(const mxArray* handle)
{


	Solid* solid=Solid::get_object_pointer(handle);

	// adding the solid to the dynamics world
	DynamicsWorld->addRigidBody(solid->RigidBody);

	// placing pointer to DynamicsWorld in the rigid body
	solid->DynamicWorld=DynamicsWorld;  // this will be used to perform collision queries outside the simulation

	// adding handle to solid object into the solid vector
	SolidHandles.push_back(handle);
	SolidContainer.push_back(solid);

#ifdef IN_DEBUG_MODE_LEVEL_1

	mexPrintf("\nAdded Solid Object to the Physics World\n");

#endif

#ifdef IN_DEBUG_MODE_LEVEL_2

	mexPrintf("Added Solid Object with the following properties\n");
	mexPrintf("Handle Class Type: %s\n",mxGetClassName(handle));
	solid->printProperties();
	mexPrintf("------------------------------------------------------------\n");

#endif
}

// -------------------------------------------------------------------------------------------- //
void SimplePhysicsEnvironment::removeBody(const mxArray* handle)
{
	
	Solid* solid=Solid::get_object_pointer(handle);

	

	// removing the solid pointer from the container
	vector< Solid* >::iterator index = find(SolidContainer.begin(),SolidContainer.end(),solid);

	if(index!=SolidContainer.end())
	{
		SolidContainer.erase(index);

		// removing the solid to the dynamics world
		DynamicsWorld->removeRigidBody(solid->RigidBody);

#ifdef IN_DEBUG_MODE_LEVEL_1

		mexPrintf("Removed Solid Object with the following properties\n");
		mexPrintf("Handle Class Type: %s\n",mxGetClassName(handle));
		solid->printProperties();
		mexPrintf("------------------------------------------------------------\n");

#endif
	}
	else
	{
		mexPrintf("\n------------------------------------------------------------\n");
		mexPrintf("Solid Object could not be found\n");
		mexPrintf("No Solid Object was removed\n");
		mexPrintf("------------------------------------------------------------\n");
	}
	


}

// -------------------------------------------------------------------------------------------- //
void SimplePhysicsEnvironment::setGroundObject(const mxArray* handle)
{
#ifdef IN_DEBUG_MODE_LEVEL_2

	mexPrintf("attempt to retrieve solid object from handle\n");

#endif
	
	Solid* groundObjectPointer = Solid::get_object_pointer(handle);

	
	// adding ground object to the dynamics world
	DynamicsWorld->addRigidBody(groundObjectPointer->RigidBody);

	// storing the pointer to the ground
	GroundObject=groundObjectPointer;

#ifdef IN_DEBUG_MODE_LEVEL_1
	mexPrintf("\nAdded Ground Object to the Physics World\n");
#endif

#ifdef IN_DEBUG_MODE_LEVEL_2

	mexPrintf("Added Ground Object with the following properties\n");
	mexPrintf("Handle Class Type: %s\n",mxGetClassName(handle));
	groundObjectPointer->printProperties();
	mexPrintf("------------------------------------------------------------\n");
#endif

}

// -------------------------------------------------------------------------------------------- //
void SimplePhysicsEnvironment::printSolidObjects()
{

	int index=0;
	
	//Solid *solid;
	
	if(GroundObject!=NULL)
	{
		mexPrintf("------------------------------------------------------------\n");

		mexPrintf("GroundObject #\n");	
		GroundObject->printProperties();

		mexPrintf("------------------------------------------------------------\n");
	}


	// iterating over every Solid object stored in the vector array

	

	
	//for(vector< const mxArray* >::iterator i=SolidHandles.begin();i!=SolidHandles.end();++i)
	
	//for(int i=0;i!=SolidContainer.size();i++)
	for(vector<Solid *>::iterator i=SolidContainer.begin();i!=SolidContainer.end();i++)
	{
		
		mexPrintf("------------------------------------------------------------\n");
		index++;
		mexPrintf("Solid Object # %i\n",index);
		
		
		//solid=Solid::get_object_pointer(*i);
		//solid->printProperties();
		Solid* solid=*i;
		//Solid* solid=SolidContainer[i];
		solid->printProperties();

		mexPrintf("------------------------------------------------------------\n");
	}
	

}

// -------------------------------------------------------------------------------------------- //
void SimplePhysicsEnvironment::printHandleValues()
{
	
	int index=0;
	for(vector< const mxArray* >::iterator i=SolidHandles.begin();i!=SolidHandles.end();i++)
	{
		
		mexPrintf("------------------------------------------------------------\n");
		mexPrintf("Handle # %i Class Type: %s\n",index,mxGetClassName(*i));
		mexPrintf("------------------------------------------------------------\n");

		index++;
		/*
		
		index++;
		mexPrintf("Solid Object # %i Handle %#x\n",index,*i);
		mexPrintf("Pointer before: %#x, ", mine);
		

		*/
	}

	
}



// -------------------------------------------------------------------------------------------- //
void SimplePhysicsEnvironment::printMethodCallDetails(const string &methodName,int methodIndex)
{

	mexPrintf("Class\t\t\t:\t%s\n","Simple Physics Environment");
	mexPrintf("Method Call\t\t:\t%s\n",methodName.c_str());
	mexPrintf("Method Index\t\t:\t%i\n",methodIndex);
}

// -------------------------------------------------------------------------------------------- //
void SimplePhysicsEnvironment::create_handle(int nargin,const mxArray *inputs[],mxArray **output)
{
	SimplePhysicsEnvironment *environmentPointer= new SimplePhysicsEnvironment(inputs+CONSTRUCTION_DATA_INDEX);

	//mexPrintf("Created pointer to SimplePhysicsEnvironment Object, pointer value= %#x, \n",environmentPointer);

	ObjectHandle<SimplePhysicsEnvironment> *handle = new ObjectHandle<SimplePhysicsEnvironment>(environmentPointer);
	
	*output=handle->to_mex_handle();

#ifdef IN_DEBUG_MODE_LEVEL_2
	mexPrintf("Created handle to pointer to SimplePhysicsEnvironment Object, new pointer value= %#x, \n",environmentPointer);
#endif

}

// -------------------------------------------------------------------------------------------- //
void SimplePhysicsEnvironment::destroy_handle(const mxArray *handle) // handle=prhs[2]
{
	destroy_object<SimplePhysicsEnvironment>(handle);
}


// -------------------------------------------------------------------------------------------- //
SimplePhysicsEnvironment* SimplePhysicsEnvironment::get_object_pointer(const mxArray *handle)
{
	SimplePhysicsEnvironment &environment=get_object<SimplePhysicsEnvironment>(handle);
	return &environment;
}

// -------------------------------------------------------------------------------------------- //
void SimplePhysicsEnvironment::method_selector(int nargin,const mxArray *inputs[],int nargout,mxArray *outputs[])
{
		
	// declaring SimplePhysicsEnvironment Pointer
	static SimplePhysicsEnvironment *environmentPointer;
	
	
	
	// checking that the method identifier index is of an integer data type
	if(!mxIsInt8(inputs[METHOD_IDENTIFIER_INDEX])&&!mxIsInt16(inputs[METHOD_IDENTIFIER_INDEX])&&!mxIsInt32(inputs[METHOD_IDENTIFIER_INDEX])&&!mxIsInt64(inputs[METHOD_IDENTIFIER_INDEX]))
	{
		mexErrMsgTxt("must pass a integer data type for the method identifier index\n");
		return;
	}

	// getting an int pointer to the method identifier index
	int *function_index=(int *)mxGetData(inputs[METHOD_IDENTIFIER_INDEX]);

	//mexPrintf("The passed function index is: %i\n",*function_index);
	
	// obtaining the pointer to the SimplePhysicsEnvironment object
	if(*function_index!=SIMPLE_PHYSICS_ENVIRONMENT_CONSTRUCTOR)
	{
		//mexPrintf("Calling Coky::getObject\n");
			environmentPointer=SimplePhysicsEnvironment::get_object_pointer(inputs[HANDLE_IDENTIFIER_INDEX]);
			
		//mexPrintf("The pointer to the passed Coky object was obtained\n");
	}

	switch (*function_index)
	{
	case SIMPLE_PHYSICS_ENVIRONMENT_CONSTRUCTOR:
		
		//
#ifdef IN_DEBUG_MODE_LEVEL_1
		
		mexPrintf("\nLocking mex file %s until matlab exits\n",mexFunctionName());
		
#endif	
		// locking mex file so that symbols and data are not deleted when the clear command is executed from the matlab command prompt
		if(!mexIsLocked())
		{
			mexLock();
			mexAtExit(closeMexFunction);
		}



#ifdef IN_DEBUG_MODE_LEVEL_2
		SimplePhysicsEnvironment::printMethodCallDetails("Constructor",SIMPLE_PHYSICS_ENVIRONMENT_CONSTRUCTOR);
		mexPrintf("------------------------------------------------------------\n");
		mexPrintf("Start of \"Constructor\" method call\n");
#endif
		SimplePhysicsEnvironment::create_handle(nargin,inputs,&outputs[0]);

#ifdef IN_DEBUG_MODE_LEVEL_2
	mexPrintf("Simple Physics Environment Object created\n");
	mexPrintf("\nEnd of \"Constructor\" method call\n");
	mexPrintf("------------------------------------------------------------\n");
#endif
	
		break;



	// --------------------------------------------------------------------------------------------------------------------------- //
	// --------------------------------------------------------------------------------------------------------------------------- //
	case SIMPLE_PHYSICS_ENVIRONMENT_ADDBODY:

#ifdef IN_DEBUG_MODE_LEVEL_2

		SimplePhysicsEnvironment::printMethodCallDetails("addBody()",SIMPLE_PHYSICS_ENVIRONMENT_ADDBODY);
		mexPrintf("------------------------------------------------------------\n");
		mexPrintf("Start of \"addBody()\" method call\n");

#endif	


	environmentPointer->addBody(inputs[START_OF_INPUT_DATA_INDEX]);

#ifdef IN_DEBUG_MODE_LEVEL_2

	mexPrintf("\nEnd of \"addBody()\" method call\n");
	mexPrintf("------------------------------------------------------------\n");

#endif
		
		break;


	// --------------------------------------------------------------------------------------------------------------------------- //
	// --------------------------------------------------------------------------------------------------------------------------- //
	case SIMPLE_PHYSICS_ENVIRONMENT_STEPSIMULATION:	

#ifdef IN_DEBUG_MODE_LEVEL_2
		
		SimplePhysicsEnvironment::printMethodCallDetails("stepSimulation()",SIMPLE_PHYSICS_ENVIRONMENT_STEPSIMULATION);
		mexPrintf("------------------------------------------------------------\n");
		mexPrintf("Start of \"stepSimulation()\" method call\n");

#endif
		
		environmentPointer->stepSimulation();

#ifdef IN_DEBUG_MODE_LEVEL_2
	mexPrintf("\nEnd of \"stepSimulation()\" method call\n");
	mexPrintf("------------------------------------------------------------\n");
#endif



		break;


	case SIMPLE_PHYSICS_ENVIRONMENT_RESETSIMULATION:	

#ifdef IN_DEBUG_MODE_LEVEL_2
		
		SimplePhysicsEnvironment::printMethodCallDetails("resetSimulation()",SIMPLE_PHYSICS_ENVIRONMENT_RESETSIMULATION);
		mexPrintf("------------------------------------------------------------\n");
		mexPrintf("Start of \"resetSimulation()\" method call\n");

#endif
		
		environmentPointer->resetSimulation();

#ifdef IN_DEBUG_MODE_LEVEL_2
	mexPrintf("\nEnd of \"resetSimulation()\" method call\n");
	mexPrintf("------------------------------------------------------------\n");
#endif



		break;

	// --------------------------------------------------------------------------------------------------------------------------- //
	// --------------------------------------------------------------------------------------------------------------------------- //

	case SIMPLE_PHYSICS_ENVIRONMENT_INITIALIZESIMULATION:	

#ifdef IN_DEBUG_MODE_LEVEL_2
		
		SimplePhysicsEnvironment::printMethodCallDetails("initializeSimulation()",SIMPLE_PHYSICS_ENVIRONMENT_INITIALIZESIMULATION);
		mexPrintf("------------------------------------------------------------\n");
		mexPrintf("Start of \"initializeSimulation()\" method call\n");

#endif
		
		environmentPointer->initializeSimulation();

#ifdef IN_DEBUG_MODE_LEVEL_2
	mexPrintf("\nEnd of \"initializeSimulation()\" method call\n");
	mexPrintf("------------------------------------------------------------\n");
#endif



		break;

	// --------------------------------------------------------------------------------------------------------------------------- //
	// --------------------------------------------------------------------------------------------------------------------------- //
	case SIMPLE_PHYSICS_ENVIRONMENT_PRINT_SOLID_OBJECTS:

#ifdef IN_DEBUG_MODE_LEVEL_2

		SimplePhysicsEnvironment::printMethodCallDetails("printSolidObjects()",SIMPLE_PHYSICS_ENVIRONMENT_PRINT_SOLID_OBJECTS);
		mexPrintf("------------------------------------------------------------\n");
		mexPrintf("Start of \"printSolidObjects()\" method call\n");

#endif

		environmentPointer->printSolidObjects();

#ifdef IN_DEBUG_MODE_LEVEL_2
	
	mexPrintf("\nEnd of \"printSolidObjects()\" method call\n");
	mexPrintf("------------------------------------------------------------\n");

#endif

		break;


	// --------------------------------------------------------------------------------------------------------------------------- //
	// --------------------------------------------------------------------------------------------------------------------------- //
	case SIMPLE_PHYSICS_ENVIRONMENT_PRINT_HANDLE_VALUES:

#ifdef IN_DEBUG_MODE_LEVEL_2

		SimplePhysicsEnvironment::printMethodCallDetails("printHandleValues()",SIMPLE_PHYSICS_ENVIRONMENT_PRINT_HANDLE_VALUES);
		mexPrintf("------------------------------------------------------------\n");
		mexPrintf("Start of \"printHandleValues()\" method call\n");

#endif

		environmentPointer->printHandleValues();

#ifdef IN_DEBUG_MODE_LEVEL_2
	
	mexPrintf("\nEnd of \"printHandleValues()\" method call\n");
	mexPrintf("------------------------------------------------------------\n");

#endif

		break;


	// --------------------------------------------------------------------------------------------------------------------------- //
	// --------------------------------------------------------------------------------------------------------------------------- //
	case SIMPLE_PHYSICS_ENVIRONMENT_SETGROUNDOBJECT:

#ifdef IN_DEBUG_MODE_LEVEL_2

		SimplePhysicsEnvironment::printMethodCallDetails("setGroundObject()",SIMPLE_PHYSICS_ENVIRONMENT_SETGROUNDOBJECT);
		mexPrintf("------------------------------------------------------------\n");
		mexPrintf("Start of \"printHandleValues()\" method call\n");

#endif
				
		environmentPointer->setGroundObject(inputs[START_OF_INPUT_DATA_INDEX]);

#ifdef IN_DEBUG_MODE_LEVEL_2
	
	mexPrintf("\nEnd of \"setGroundObject()\" method call\n");
	mexPrintf("------------------------------------------------------------\n");

#endif

		break;


	// --------------------------------------------------------------------------------------------------------------------------- //
	// --------------------------------------------------------------------------------------------------------------------------- //
	case SIMPLE_PHYSICS_ENVIRONMENT_STARTSIMULATION:

#ifdef IN_DEBUG_MODE_LEVEL_2

		SimplePhysicsEnvironment::printMethodCallDetails("startSimulation()", SIMPLE_PHYSICS_ENVIRONMENT_STARTSIMULATION);
		mexPrintf("------------------------------------------------------------\n");
		mexPrintf("Start of \"startSimulation()\" method call\n");

#endif

		environmentPointer->startSimulation();

#ifdef IN_DEBUG_MODE_LEVEL_2
	
	mexPrintf("\nEnd of \"startSimulation()\" method call\n");
	mexPrintf("------------------------------------------------------------\n");

#endif

		break;
	
	// --------------------------------------------------------------------------------------------------------------------------- //
	// --------------------------------------------------------------------------------------------------------------------------- //
	case SIMPLE_PHYSICS_ENVIRONMENT_STOPSIMULATION:

#ifdef IN_DEBUG_MODE_LEVEL_2

		SimplePhysicsEnvironment::printMethodCallDetails("stopSimulation()",SIMPLE_PHYSICS_ENVIRONMENT_STOPSIMULATION);
		mexPrintf("------------------------------------------------------------\n");
		mexPrintf("Start of \"stopSimulation()\" method call\n");

#endif

		environmentPointer->stopSimulation();

#ifdef IN_DEBUG_MODE_LEVEL_2
	
	mexPrintf("\nEnd of \"stopSimulation()\" method call\n");
	mexPrintf("------------------------------------------------------------\n");

#endif

		break;

	// --------------------------------------------------------------------------------------------------------------------------- //
	// --------------------------------------------------------------------------------------------------------------------------- //
	case SIMPLE_PHYSICS_ENVIRONMENT_RESUMESIMULATION:

#ifdef IN_DEBUG_MODE_LEVEL_2

		SimplePhysicsEnvironment::printMethodCallDetails("resumeSimulation()",SIMPLE_PHYSICS_ENVIRONMENT_RESUMESIMULATION);
		mexPrintf("------------------------------------------------------------\n");
		mexPrintf("Start of \"resumeSimulation()\" method call\n");

#endif

		environmentPointer->resumeSimulation();

#ifdef IN_DEBUG_MODE_LEVEL_2
	
	mexPrintf("\nEnd of \"resumeSimulation()\" method call\n");
	mexPrintf("------------------------------------------------------------\n");

#endif

		break;

	// --------------------------------------------------------------------------------------------------------------------------- //
	// --------------------------------------------------------------------------------------------------------------------------- //
	case SIMPLE_PHYSICS_ENVIRONMENT_PAUSESIMULATION:

#ifdef IN_DEBUG_MODE_LEVEL_2

		SimplePhysicsEnvironment::printMethodCallDetails("pauseSimulation()",SIMPLE_PHYSICS_ENVIRONMENT_PAUSESIMULATION);
		mexPrintf("------------------------------------------------------------\n");
		mexPrintf("Start of \"pauseSimulation()\" method call\n");

#endif

		environmentPointer->pauseSimulation();

#ifdef IN_DEBUG_MODE_LEVEL_2
	
		mexPrintf("\nEnd of \"pauseSimulation()\" method call\n");
		mexPrintf("------------------------------------------------------------\n");

#endif

		break;


	// --------------------------------------------------------------------------------------------------------------------------- //
	// --------------------------------------------------------------------------------------------------------------------------- //
	case SIMPLE_PHYSICS_ENVIRONMENT_REMOVEBODY:

#ifdef IN_DEBUG_MODE_LEVEL_2

		SimplePhysicsEnvironment::printMethodCallDetails("removeBody()",SIMPLE_PHYSICS_ENVIRONMENT_SETGROUNDOBJECT);
		mexPrintf("------------------------------------------------------------\n");
		mexPrintf("Start of \"removeBody()\" method call\n");

#endif

		environmentPointer->removeBody(inputs[START_OF_INPUT_DATA_INDEX]);

#ifdef IN_DEBUG_MODE_LEVEL_2
	
	mexPrintf("\nEnd of \"removeBody()\" method call\n");
	mexPrintf("------------------------------------------------------------\n");

#endif

		break;

	// --------------------------------------------------------------------------------------------------------------------------- //
	// --------------------------------------------------------------------------------------------------------------------------- //
	case SIMPLE_PHYSICS_ENVIRONMENT_DESTRUCTOR:

#ifdef IN_DEBUG_MODE_LEVEL_2
		SimplePhysicsEnvironment::printMethodCallDetails("Destructor",SIMPLE_PHYSICS_ENVIRONMENT_DESTRUCTOR);
		mexPrintf("------------------------------------------------------------\n");
		mexPrintf("Start of \"Destructor\" method call\n");
#endif

		// deletes the handle and the Simple Physics Environment object to which the handle is associated with
		SimplePhysicsEnvironment::destroy_handle(inputs[HANDLE_IDENTIFIER_INDEX]);

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






	



	