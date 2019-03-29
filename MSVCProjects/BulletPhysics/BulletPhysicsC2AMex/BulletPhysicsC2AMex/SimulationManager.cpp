#include "mexFunction.h"
#include <iostream>
#include "SimulationManager.h"

#include "GlutStuff.h"
#include "GLDebugFont.h"

#include "btBulletDynamicsCommon.h"
#include <stdio.h> //printf debugging
#include "BulletDynamics/Dynamics/btDiscreteDynamicsWorld.h"
#include "BulletDynamics/Dynamics/btRigidBody.h"

//maximum number of objects (and allow user to shoot additional boxes)
#define MAX_PROXIES (ARRAY_SIZE_X*ARRAY_SIZE_Y*ARRAY_SIZE_Z + 1024)

//scaling of the objects (0.1 = 20 centimeter boxes )
#define SCALING 1.

extern bool isFontDataInitialized;  // this is an external variable declared in GLDebugFont.cpp

// -------------------------------------------------------------------------------------------- //
// -------------------------------------------------------------------------------------------- //
SimulationManager::SimulationManager()
{
#ifdef IN_DEBUG_MODE_LEVEL_1
	mexPrintf("\nSimulation Manager Constructor Called with no arguments\n");
#endif

}

// -------------------------------------------------------------------------------------------- //
// -------------------------------------------------------------------------------------------- //
SimulationManager::SimulationManager(btDynamicsWorld *dynamicsWorld,btBroadphaseInterface* broadphase,
		btCollisionDispatcher* dispatcher,btDefaultCollisionConfiguration* collisionConfiguration,
		btConstraintSolver* solver)
{

	setTexturing(true);
	setShadows(true);

	// changing the default values so that the z axis is defined as the up - down direction
	setAzi(52.2); // setting azimuth
	m_sundirection = btVector3(1,1,-2)*1000;

	setCameraDistance(btScalar(40.));
	setCameraForwardAxis(1);
	setCameraUp(btVector3(0,0,1));


	m_collisionConfiguration = collisionConfiguration;
	m_dispatcher = dispatcher;
	m_broadphase = broadphase;
	m_solver = solver;
	m_dynamicsWorld = dynamicsWorld;

	isSimulationRunning = false;

	//clientResetScene();

#ifdef IN_DEBUG_MODE_LEVEL_1
	mexPrintf("\nSimulation Manager Constructor Called\n");
#endif


}

// -------------------------------------------------------------------------------------------- //
// -------------------------------------------------------------------------------------------- //
SimulationManager::~SimulationManager()
{
	stopSimulation();

#ifdef IN_DEBUG_MODE_LEVEL_1
	mexPrintf("\nSimulation Manager Destructor Called\n");
#endif
	
}

// -------------------------------------------------------------------------------------------- //
// -------------------------------------------------------------------------------------------- //
void SimulationManager::startSimulation()
{
	if(!isSimulationRunning)
	{
#ifdef IN_DEBUG_MODE_LEVEL_1
		mexPrintf("\nSimulation Started on Separate Thread\n");
#endif
	
		SimulationThread = boost::thread(&SimulationManager::callGlutMain,this);

		isSimulationRunning = true;
		resumeSimulation();
	}
	else
	{
		mexPrintf("\nSimulation is already running\n");
	}
}

// -------------------------------------------------------------------------------------------- //
// -------------------------------------------------------------------------------------------- //
void SimulationManager::pauseSimulation()
{
	if(isSimulationRunning)
	{
		m_idle=true;
	}
	else
	{
		mexPrintf("\nSimulationManager Method: This call is only valid when simulation is running\n");
	}
}

// -------------------------------------------------------------------------------------------- //
// -------------------------------------------------------------------------------------------- //
void SimulationManager::stepSimulation()
{
	if(isSimulationRunning)
	{
		pauseSimulation();
		clientMoveAndDisplay();
	}
	else
	{
		mexPrintf("\nSimulationManager Method: This call is only valid when simulation is running\n");
	}
}


// -------------------------------------------------------------------------------------------- //
// -------------------------------------------------------------------------------------------- //
void SimulationManager::resumeSimulation()
{
	if(isSimulationRunning)
	{
		m_idle=false;
	}
	else
	{
		mexPrintf("\nSimulationManager Method: This call is only valid when simulation is running\n");
	}
}


// -------------------------------------------------------------------------------------------- //
// -------------------------------------------------------------------------------------------- //
void SimulationManager::resetSimulation()
{
	if(isSimulationRunning)
	{
		clientResetScene();
	}
	else
	{
		mexPrintf("\nSimulationManager Method: This call is only valid when simulation is running\n");
	}
}

// -------------------------------------------------------------------------------------------- //
// -------------------------------------------------------------------------------------------- //
void SimulationManager::join()
{
	if(isSimulationRunning)
	{
		SimulationThread.join();
	}
}

// -------------------------------------------------------------------------------------------- //
// -------------------------------------------------------------------------------------------- //
void SimulationManager::stopSimulation()
{
	if(isSimulationRunning)
	{
		
		pauseSimulation();
		glutLeaveMainLoop();
		//glutDestroyWindow(WindowHandle);
		isSimulationRunning=false;
	}
}

// -------------------------------------------------------------------------------------------- //
// -------------------------------------------------------------------------------------------- //
void SimulationManager::callGlutMain()
{

	// creating arguments for glutInit
	int argc=1;
	char *argv[1];
	argv[0]=strdup("AppName");


	isFontDataInitialized=false; // global variable in GLDebugFont.cpp file.  Needs to be initialized to false
								// so that certain glut commands are called

#ifdef IN_DEBUG_MODE_LEVEL_1
	mexPrintf("\nSimulation Started\n");
#endif

	glutmain(argc,argv,600,600,"Bullet Physics Mex",this);


#ifdef IN_DEBUG_MODE_LEVEL_1
	mexPrintf("\nreturned from glutMain()\n");
#endif

	// setting back to default 
	isFontDataInitialized=false;
	m_shapeDrawer->set_m_textureinitialized(false);
	m_shapeDrawer->enableTexture (true);

	isSimulationRunning=false;
}

// -------------------------------------------------------------------------------------------- //
// -------------------------------------------------------------------------------------------- //
void	SimulationManager::updateModifierKeys()
{
	m_modifierKeys = 0;
	if (glutGetModifiers() & GLUT_ACTIVE_ALT)
		m_modifierKeys |= BT_ACTIVE_ALT;

	if (glutGetModifiers() & GLUT_ACTIVE_CTRL)
		m_modifierKeys |= BT_ACTIVE_CTRL;
	
	if (glutGetModifiers() & GLUT_ACTIVE_SHIFT)
		m_modifierKeys |= BT_ACTIVE_SHIFT;
}

// -------------------------------------------------------------------------------------------- //
// -------------------------------------------------------------------------------------------- //
void SimulationManager::specialKeyboard(int key, int x, int y)	
{
	(void)x;
	(void)y;

	switch (key) 
	{
	case GLUT_KEY_F1:
		{

			break;
		}

	case GLUT_KEY_F2:
		{

			break;
		}


	case GLUT_KEY_END:
		{
			int numObj = getDynamicsWorld()->getNumCollisionObjects();
			if (numObj)
			{
				btCollisionObject* obj = getDynamicsWorld()->getCollisionObjectArray()[numObj-1];

				getDynamicsWorld()->removeCollisionObject(obj);
				btRigidBody* body = btRigidBody::upcast(obj);
				if (body && body->getMotionState())
				{
					delete body->getMotionState();					
				}
				delete obj;


			}
			break;
		}
	case GLUT_KEY_LEFT : stepLeft(); break;
	case GLUT_KEY_RIGHT : stepRight(); break;
	case GLUT_KEY_UP : stepFront(); break;
	case GLUT_KEY_DOWN : stepBack(); break;
	case GLUT_KEY_PAGE_UP : zoomIn(); break;
	case GLUT_KEY_PAGE_DOWN : zoomOut(); break;
	case GLUT_KEY_HOME : toggleIdle(); break;
	default:
		//        std::cout << "unused (special) key : " << key << std::endl;
		break;
	}

	glutPostRedisplay();

}

// -------------------------------------------------------------------------------------------- //
// -------------------------------------------------------------------------------------------- //
void SimulationManager::swapBuffers()
{
	glutSwapBuffers();

}

// -------------------------------------------------------------------------------------------- //
// -------------------------------------------------------------------------------------------- //
void SimulationManager::displayCallback(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
	
	renderme();

	//optional but useful: debug drawing to detect problems
	if (m_dynamicsWorld)
		m_dynamicsWorld->debugDrawWorld();

	glFlush();
	glutSwapBuffers();
}

// -------------------------------------------------------------------------------------------- //
// -------------------------------------------------------------------------------------------- //
void SimulationManager::clientMoveAndDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 

	//simple dynamics world doesn't handle fixed-time-stepping
	btScalar ms = getDeltaTimeMicroseconds();
	
	///step the simulation
	if (m_dynamicsWorld)
	{
		m_dynamicsWorld->stepSimulation(ms / 1000000.f);
		//optional but useful: debug drawing
		m_dynamicsWorld->debugDrawWorld();
	}
		
	renderme(); 

	glFlush();

	glutSwapBuffers();

}

