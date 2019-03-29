// this is a simple class that encapsulates all of the details required to implement the basic functionality of a physics environment

#ifndef SIMPLE_PHYSICS_ENVIRONMENT_H
#define SIMPLE_PHYSICS_ENVIRONMENT_H


#include "mexFunction.h"
#include "btBulletDynamicsCommon.h"
#include "Solid.h"
#include "SimulationManager.h"




enum SimplePhysicsEnvironmentMethods
{
	SIMPLE_PHYSICS_ENVIRONMENT_CONSTRUCTOR=0,
	SIMPLE_PHYSICS_ENVIRONMENT_ADDBODY,
	SIMPLE_PHYSICS_ENVIRONMENT_PRINT_SOLID_OBJECTS,
	SIMPLE_PHYSICS_ENVIRONMENT_PRINT_HANDLE_VALUES,
	SIMPLE_PHYSICS_ENVIRONMENT_SETGROUNDOBJECT,
	SIMPLE_PHYSICS_ENVIRONMENT_REMOVEBODY,
	SIMPLE_PHYSICS_ENVIRONMENT_STARTSIMULATION,
	SIMPLE_PHYSICS_ENVIRONMENT_RESUMESIMULATION,
	SIMPLE_PHYSICS_ENVIRONMENT_PAUSESIMULATION,
	SIMPLE_PHYSICS_ENVIRONMENT_STOPSIMULATION,
	SIMPLE_PHYSICS_ENVIRONMENT_STEPSIMULATION,
	SIMPLE_PHYSICS_ENVIRONMENT_RESETSIMULATION,
	SIMPLE_PHYSICS_ENVIRONMENT_INITIALIZESIMULATION,
	SIMPLE_PHYSICS_ENVIRONMENT_DESTRUCTOR=-1
};



class SimplePhysicsEnvironment
{
	public:

		btDefaultCollisionConfiguration* CollisionConfiguration;
		btCollisionDispatcher* Dispatcher;
		btBroadphaseInterface* Broadphase;	
		btSequentialImpulseConstraintSolver* Solver;
		btDiscreteDynamicsWorld* DynamicsWorld;

		// simulator
		SimulationManager *Simulator;
		
		// gravity 
		btVector3 GravityVector;


		//btCollisionShape* GroundShape; // this will be an static entity which can not be influenced by the environment
		Solid* GroundObject;


		// containers --------------------------------------------------------------------------------------------

		// container to hold the handle values to all registered solid object
		vector< const mxArray* > SolidHandles;
		
		// container to hold pointes to all registered solid objects
		vector< Solid* > SolidContainer;


		// -------------------------------------------------------------------------------------------------------

		//
		SimplePhysicsEnvironment(const mxArray* inputs[]);

		//
		~SimplePhysicsEnvironment();

		// physics simulation methods
		void addBody(const mxArray* handle);

		void removeBody(const mxArray* handle);

		void setGroundObject(const mxArray* handle);
		

		
			

		// these methods call on the Simulator methods
		void initializeSimulation();
		void startSimulation();
		void resumeSimulation();
		void pauseSimulation();
		void stopSimulation();
		void stepSimulation(); 
		void resetSimulation();

		// debbugging methods
		void printSolidObjects();
		
		void printHandleValues();


		// internal methods (not accessible from matlab)

		void releaseData();

		static void printMethodCallDetails(const string &methodName,int methodIndex);
		
		// handle manipulation methods
		static void create_handle(int nargin,const mxArray* input[],mxArray **output);
		static void destroy_handle(const mxArray *handle); //handle=prhs[2]
		static SimplePhysicsEnvironment* get_object_pointer(const mxArray *handle); //typically handle=prhs[2]
		static void method_selector(int nargin,const mxArray* input[],int nargout,mxArray* outputs[]);

		// deprecated
		//void stepSimulationAndUpdate();
};

#endif
