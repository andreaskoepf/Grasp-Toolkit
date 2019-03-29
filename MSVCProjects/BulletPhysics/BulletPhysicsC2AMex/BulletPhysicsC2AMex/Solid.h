
#ifndef SOLID_H
#define SOLID_H

#include "mexFunction.h"
#include "MexUtilities.h"
#include "btBulletDynamicsCommon.h"
#include "BulletCollision/Gimpact/btGImpactShape.h"
#include "BulletCollision/Gimpact/btGImpactCollisionAlgorithm.h"

enum SolidMethods{
	SOLID_CONSTRUCTOR = 0,
	SOLID_GET_ROTATION,
	SOLID_GET_POSITION,
	SOLID_UPDATE_TRANSFORM,
	SOLID_PRINT_PROPERTIES,
	SOLID_PRINT_TRIMESH,
	SOLID_SET_TRANSFORM,
	SOLID_GET_TRANSFORM,
	SOLID_ADD_CONSTRAINT,
	SOLID_COLLISION_PAIR_TEST,
	SOLID_DESTRUCTOR=-1
};

enum GeometryID{
	PLANE=0,
	BOX,
	SPHERE,
	TRIMESH,
	STATICTRIMESH

};


enum JointTypes{
	REVOLUTE=0,
	UNIVERSAL,
	SPHERICAL
};

// defining the contact callback

struct	CustomContactResultCallback : public btDynamicsWorld::ContactResultCallback // inherits from dynamics world ContactResultCallback
{

	// attributes
	vector< btManifoldPoint* > ContactPoints; // used to hold pointers to the btManifoldPoints

	int NumberOfContactPoints;

	bool Collided; // true if a collision between the input pair has occured

	CustomContactResultCallback();

	virtual ~CustomContactResultCallback();

	// overriden
	virtual btScalar CustomContactResultCallback::addSingleResult(btManifoldPoint& cp,	
		const btCollisionObject* colObj0,int partId0,int index0,const btCollisionObject* colObj1,int partId1,int index1);
	
};



	
class Solid
{
	public:
		btCollisionShape* CollisionShape;
		btDefaultMotionState* MotionState;
		btRigidBody *RigidBody;

		// pointer to the dynamics world where the rigid body is contained
		btDynamicsWorld *DynamicWorld;

		// constraint container
		vector< btTypedConstraint* > Constraints;

		
		// descriptive Properties
		string GeometryType;
		int GeometryId;


		// fixed properties
		btScalar Mass;
		btVector3 Inertia;
		btScalar Dimensions[3];
		btVector3 COG;
		btTransform COGTransform;

		// Triangulation attributes
		btTriangleIndexVertexArray *TrimeshData;
		btScalar *Vertices;
		int *Faces;
		int NumVertices;
		int NumFaces;

		// changing properties
		btTransform *Transform;
		btScalar Quaternion[4];
		btScalar Position[3];
		

		int IsDynamic;

		//
		Solid(const mxArray* input);

		//
		~Solid();

		// access methods
		void getRotation(mxArray *output[]);

		void getPosition(mxArray *output[]);

		void getTransform(mxArray *output[]);


		// set methods

		void setTransform(const mxArray* input); // only when object is kinematic

		void setDynamic(int isDynamic);

		void addConstraint(const mxArray* handle,const mxArray* inputs[]);


		// update methods

		void updateTransform();

		// collision methods
		void collisionPairTest(const mxArray* solidHandle,mxArray *output[],int nargout);

		// debugging methods

		void printProperties();

		void printTrimesh();

		static void printMethodCallDetails(const string &methodName,int methodIndex);


		// handle accessing methods

		static void create_handle(int nargin,const mxArray *inputs[],mxArray **output);
		static void destroy_handle(const mxArray *input);
		static Solid* get_object_pointer(const mxArray *input);
		static void method_selector(int nargin,const mxArray* intputs[], int nargout, mxArray* outputs[]);


				
	protected:

		// helper attributes

		mwSize ArraySize[2];


		// constructor helpers

		void constructBox(const mxArray* input);
		void constructSphere(const mxArray* input);
		void constructTrimesh(const mxArray* input);
		void constructStaticPlane(const mxArray* input);
		void constructStaticTrimesh(const mxArray* input);

		// this method is needed to store the triangulation data that will be used to build the PQP
		// models to perform the Continous Collision Detection tests
		void populateTriangulationAttributes(const mxArray* input);
};

#endif

