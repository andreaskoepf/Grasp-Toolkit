#ifndef SIMULATIONMANAGER_H
#define SIMULATIONMANAGER_H

#include "DemoApplication.h"
#include "boost/thread.hpp"

class btBroadphaseInterface;
class btCollisionShape;
class btOverlappingPairCache;
class btCollisionDispatcher;
class btConstraintSolver;
struct btCollisionAlgorithmCreateFunc;
class btDefaultCollisionConfiguration;


class SimulationManager: public DemoApplication
{
public:
	

	btBroadphaseInterface*	m_broadphase;

	btCollisionDispatcher*	m_dispatcher;

	btConstraintSolver*	m_solver;

	btDefaultCollisionConfiguration* m_collisionConfiguration;

	boost::thread SimulationThread;

	SimulationManager();

	SimulationManager(btDynamicsWorld *dynamicsWorld,btBroadphaseInterface* broadphase,
		btCollisionDispatcher* dispatcher,btDefaultCollisionConfiguration* collisionConfiguration,
		btConstraintSolver* solver);

	~SimulationManager();



	void startSimulation();
	void pauseSimulation();
	void resumeSimulation();
	void stepSimulation();
	void resetSimulation();
	void join(); // executes the join method on the internal thread
	void stopSimulation();
	

	//deprecated methods
	//void initializePhysics();
	//void closePhysics();

	// deprecated attributes
	//btAlignedObjectArray<btCollisionShape*>	m_collisionShapes;
	

	void specialKeyboard(int key, int x, int y);

	virtual void	swapBuffers();

	virtual	void	updateModifierKeys();

	virtual void clientMoveAndDisplay();

	virtual void displayCallback();


	// the following virtual method needs to be overriden
	static SimulationManager* Create()
	{
		SimulationManager* demo = new SimulationManager;
		demo->myinit();
		//demo->initPhysics();
		return demo;
	}



protected:
	void callGlutMain();
};

#endif
