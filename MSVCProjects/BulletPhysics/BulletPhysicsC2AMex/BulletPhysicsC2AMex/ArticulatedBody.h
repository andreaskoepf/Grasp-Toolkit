

#ifndef ARTICULATED_BODY_H
#define ARTICULATED_BODY_H

#include "Solid.h"


enum ArticulatedBodyMethods{
	ARTICULATED_BODY_CONSTRUCTOR = 0,
	ARTICULATED_BODY_ADD_BODY,
	ARTICULATED_BODY_START_UPDATE,
	ARTICULATED_BODY_STOP_UPDATE,
	ARTICULATED_BODY_DESTRUCTOR=-1
};




class ArticulatedBody
{
public:

	// container for solid object pointers
	vector< Solid* > SolidObjects;

	// 
	int DOF;

	ArticulatedBody(const mxArray* inputs);

	~ArticulatedBody();

	void addBody(const mxArray* handle);
	bool isBodyAdded(Solid* solid);
	bool *IsUpdating;

	// updating methods
	// these methods are used to syncronize the animation of all the objects that belong to the articulated body
	void startUpdate(); 
	void stopUpdate();

	// internal methods (not accessible from Matlab)
	//void removeBody();



	
	// utility methods
	static void printMethodCallDetails(const string &methodName,int methodIndex);
	static void create_handle(int nargin,const mxArray *inputs[],mxArray **output);
	static void destroy_handle(const mxArray *input);
	static ArticulatedBody* get_object_pointer(const mxArray *input);
	static void method_selector(int nargin,const mxArray* intputs[], int nargout, mxArray* outputs[]);



};


// overriding motion state
// this customized will be used by articulated bodies whos components have been flagged as kinematic
struct CustomMotionState : public btDefaultMotionState
{
public:
	bool *IsUpdating;
	btTransform HoldTransform;

	void holdTransform()
	{
		getWorldTransform(HoldTransform);
	}
	
	CustomMotionState(btDefaultMotionState &motionState,const ArticulatedBody *referenceBody)
	{
	
	m_graphicsWorldTrans=btTransform(motionState.m_graphicsWorldTrans);
	m_centerOfMassOffset=btTransform(motionState.m_centerOfMassOffset);
	m_startWorldTrans=btTransform(motionState.m_startWorldTrans);
	m_userPointer=motionState.m_userPointer;

	IsUpdating = referenceBody->IsUpdating;
	}



	virtual void getWorldTransform(btTransform &worldTrans) const
	{
		if(*IsUpdating)
		{
			worldTrans=HoldTransform;
#ifdef IN_DEBUG_MODE_LEVEL_2
			mexPrintf("\nMotion State Object Not returning transform during update");
#endif
			return;
		}

		this->btDefaultMotionState::getWorldTransform(worldTrans);
	}

};

#endif



