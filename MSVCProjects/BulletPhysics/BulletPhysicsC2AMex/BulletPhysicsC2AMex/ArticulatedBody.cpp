#include "ArticulatedBody.h"
#include "ObjectHandle.h"

ArticulatedBody::ArticulatedBody(const mxArray *input)
{
	

#ifdef IN_DEBUG_MODE_LEVEL_1
	mexPrintf("\n\n------------------------------------------------------------");
	mexPrintf("\n------------Articulated Body Object Construction------------");
	mexPrintf("\n------------------------------------------------------------\n");
#endif

	//DOF = Solid::extract_int(input,mwIndex(0),"DOF");
	IsUpdating=new bool;
	*IsUpdating=false;

#ifdef IN_DEBUG_MODE_LEVEL_1
	mexPrintf("\n\n------------------------------------------------------------");
	mexPrintf("\n--------End Of Articulated Body Object Construction---------");
	mexPrintf("\n------------------------------------------------------------\n");
#endif

}


// -------------------------------------------------------------------------------------------- //
// -------------------------------------------------------------------------------------------- //
ArticulatedBody::~ArticulatedBody()
{
	
	// restoring original motion state
	for(vector< Solid* >::iterator i=SolidObjects.begin();i!=SolidObjects.end();i++)
	{
		Solid *solid=*i;

		// retrieving custom motion state structure
		CustomMotionState *motionState= (CustomMotionState*)solid->RigidBody->getMotionState();

		// restoring defalut motion state
		solid->RigidBody->setMotionState(solid->MotionState);

		// destroying custom motion state
		delete motionState;

	}
	
	delete IsUpdating;

	mexPrintf("\nDestroyed Articulated Body");


}


// -------------------------------------------------------------------------------------------- //
// -------------------------------------------------------------------------------------------- //
void ArticulatedBody::addBody(const mxArray *handle)
{
	Solid* solid = Solid::get_object_pointer(handle);

	// store current transform
	btTransform currentTransform;
	solid ->RigidBody->getMotionState()->getWorldTransform(currentTransform);
	
	// creating new CustomWorldTransform
	CustomMotionState *motionState = new CustomMotionState(*(solid->MotionState),this);

	// placing new motion state in rigid body
	solid ->RigidBody->setMotionState(motionState);

	if(!isBodyAdded(solid))
	{
		SolidObjects.push_back(solid);

#ifdef IN_DEBUG_MODE_LEVEL_1
		mexPrintf("Solid Object Added to articulated body object\n");
#endif

	}
#ifdef IN_DEBUG_MODE_LEVEL_1
	else
	{

		mexPrintf("Solid Object had already been added\n");

	}
#endif
}



// -------------------------------------------------------------------------------------------- //
// -------------------------------------------------------------------------------------------- //
bool ArticulatedBody::isBodyAdded(Solid* solid)
{
	bool isObject=false;
	for(vector< Solid* >::iterator i=SolidObjects.begin();i<SolidObjects.end();i++)
	{
		if(*i==solid)
		{
			isObject=true;
			return isObject;
		}
	}

	return isObject;
}


// -------------------------------------------------------------------------------------------- //
// -------------------------------------------------------------------------------------------- //
void ArticulatedBody::startUpdate()
{

#ifdef IN_DEBUG_MODE_LEVEL_2
		mexPrintf("\nstartUpdate Called\n");
#endif
	// holding last transform
		for(vector< Solid* >::iterator i=SolidObjects.begin();i<SolidObjects.end();i++)
		{
			Solid *solid= *i;
			CustomMotionState *motionState = (CustomMotionState*)solid->RigidBody->getMotionState();
			motionState->holdTransform();
		}

	*IsUpdating=true;	

#ifdef IN_DEBUG_MODE_LEVEL_2
		mexPrintf("exited startUpdate Call\n");
#endif
	
}


// -------------------------------------------------------------------------------------------- //
// -------------------------------------------------------------------------------------------- //
void ArticulatedBody::stopUpdate()
{
#ifdef IN_DEBUG_MODE_LEVEL_2
		mexPrintf("\nstopUpdate Called\n");
#endif


	*IsUpdating=false;

}


// -------------------------------------------------------------------------------------------- //
// -------------------------------------------------------------------------------------------- //

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Handle manipulation functions
void ArticulatedBody::create_handle(int nargin,const mxArray *inputs[],mxArray **output)
{
	
	
	
	ArticulatedBody *artcBody= new ArticulatedBody(inputs[CONSTRUCTION_DATA_INDEX]);
	//mexPrintf("Created pointer to Solid Object, pointer value= %#x, \n",solid);
	ObjectHandle<ArticulatedBody> *handle = new ObjectHandle<ArticulatedBody>(artcBody);
	
	*output=handle->to_mex_handle();

#ifdef IN_DEBUG_MODE_LEVEL_1
	/*mexPrintf("------------------------------------------------------------\n");
	mexPrintf("Created handle to pointer to Solid Object, new pointer value= %#x, \n",solid);
	*/
#endif

}

// -------------------------------------------------------------------------------------------- //
// -------------------------------------------------------------------------------------------- //
ArticulatedBody* ArticulatedBody::get_object_pointer(const mxArray *handle)
{
	ArticulatedBody &artcBody=get_object<ArticulatedBody>(handle);
	return &artcBody;
}


// -------------------------------------------------------------------------------------------- //
// -------------------------------------------------------------------------------------------- //
void ArticulatedBody::destroy_handle(const mxArray *handle) // handle=prhs[2]
{
	destroy_object<ArticulatedBody>(handle);
}


// -------------------------------------------------------------------------------------------- //
void ArticulatedBody::method_selector(int nargin,const mxArray *inputs[],int nargout,mxArray *outputs[])
{
		
	// declaring SimplePhysicsEnvironment Pointer
	static ArticulatedBody *artcBodyPointer;
	
	
	
	// checking that the method identifier index is of an integer data type
	if(!mxIsInt8(inputs[METHOD_IDENTIFIER_INDEX])&&!mxIsInt16(inputs[METHOD_IDENTIFIER_INDEX])&&!mxIsInt32(inputs[METHOD_IDENTIFIER_INDEX])&&!mxIsInt64(inputs[METHOD_IDENTIFIER_INDEX]))
	{
		mexErrMsgTxt("must pass a integer data type for the method identifier index\n");
		return;
	}

	// getting an int pointer to the method identifier index
	int *function_index=(int *)mxGetData(inputs[METHOD_IDENTIFIER_INDEX]);

	// obtaining the pointer to the SimplePhysicsEnvironment object
	if(*function_index!=ARTICULATED_BODY_CONSTRUCTOR)
	{
			artcBodyPointer=ArticulatedBody::get_object_pointer(inputs[HANDLE_IDENTIFIER_INDEX]);
			
	}


	// selecting method
	switch (*function_index)
	{
	case ARTICULATED_BODY_CONSTRUCTOR:


#ifdef IN_DEBUG_MODE_LEVEL_2

		ArticulatedBody::printMethodCallDetails("Constructor",ARTICULATED_BODY_CONSTRUCTOR);		
		mexPrintf("------------------------------------------------------------\n");    	
		mexPrintf("Start of \"Constructor\" method call\n\n");
#endif		
		//
		ArticulatedBody::create_handle(nargin,inputs,&outputs[0]);


#ifdef IN_DEBUG_MODE_LEVEL_2
		mexPrintf("\nEnd of \"Constructor\" method call\n");
		mexPrintf("------------------------------------------------------------\n");   
#endif

		
		break;


	case ARTICULATED_BODY_ADD_BODY:

#ifdef IN_DEBUG_MODE_LEVEL_2
		
		ArticulatedBody::printMethodCallDetails("addBody()",ARTICULATED_BODY_ADD_BODY);

#endif

		artcBodyPointer->addBody(inputs[START_OF_INPUT_DATA_INDEX]);


		break;


	case ARTICULATED_BODY_START_UPDATE:

#ifdef IN_DEBUG_MODE_LEVEL_2
		
		ArticulatedBody::printMethodCallDetails("startUpdate()",ARTICULATED_BODY_START_UPDATE);

#endif
		
		
		artcBodyPointer->startUpdate();
		

		break;

	case ARTICULATED_BODY_STOP_UPDATE:

#ifdef IN_DEBUG_MODE_LEVEL_2
		
		ArticulatedBody::printMethodCallDetails("stopUpdate()",ARTICULATED_BODY_STOP_UPDATE);

#endif
		
		
		artcBodyPointer->stopUpdate();
		

		break;

	case ARTICULATED_BODY_DESTRUCTOR:

#ifdef IN_DEBUG_MODE_LEVEL_2
		
		Solid::printMethodCallDetails("Destructor",ARTICULATED_BODY_DESTRUCTOR);
		mexPrintf("------------------------------------------------------------\n");    	
		mexPrintf("Start of \"Destructor\" method call\n\n");
#endif

		// deletes the handle and the solid object to which the handle is associated with
		ArticulatedBody::destroy_handle(inputs[HANDLE_IDENTIFIER_INDEX]);

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
void ArticulatedBody::printMethodCallDetails(const string &methodName,int methodIndex)
{

	mexPrintf("Class\t\t\t:\t%s\n","Solid");
	mexPrintf("Method Call\t\t:\t%s\n",methodName.c_str());
	mexPrintf("Method Index\t\t:\t%i\n",methodIndex);
}

