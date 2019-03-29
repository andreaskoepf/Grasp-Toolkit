
#ifndef CUSTOMINTERPMOTION_H
#define CUSTOMINTERPMOTION_H

#include "mexFunction.h"
#include "InterpMotion.h"
#include "TriDist.h"

class CInterpMotion_Slerp : public CInterpMotion
{
public:


	CInterpMotion_Slerp(const PQP_REAL R0[3][3],const PQP_REAL T0[3],const PQP_REAL R1[3][3],const PQP_REAL T1[3]);
	CInterpMotion_Slerp(const PQP_REAL q0[7], const PQP_REAL q1[7]);
	CInterpMotion_Slerp();

	virtual void velocity(void);
	virtual bool integrate(const double dt, PQP_REAL qua[7]);

	// SLERP methods
	void computeSlerpTranslation(const double dt,const Coord3D &pos_0,const Coord3D &pos_f,Coord3D &pos_t);
	void computeSlerpOrientation(const double dt,const Quaternion &q_0,const Quaternion &q_f,Quaternion &q_t);
	void computeLerpOrientation(const double dt,const Quaternion &q_0,const Quaternion &q_f,Quaternion &q_t);

	~CInterpMotion_Slerp();

	virtual double computeTOC(PQP_REAL d, PQP_REAL r1);



	//use the angular radius computed from the nearest points to compute TOC, more efficient than using C2A_BV's angular radius in computeTOC
	virtual double computeTOC(
		PQP_REAL d, 
		PQP_REAL r1,
		PQP_REAL S[3]);
	
	//compute the TOC using directional motion bound, //use the C2A_BV's angular radius to compute TOC, 
	virtual double computeTOC_MotionBound(
		PQP_REAL T[3],
		PQP_REAL d, 
		C2A_BV *V, 
		PQP_REAL N[3]);//using motion bound of RSS 


	virtual bool CAonRSS(
		PQP_REAL r1[3][3], 
		PQP_REAL tt1[3],	  
		PQP_REAL r2[3][3],
		PQP_REAL tt2[3], 	  
		PQP_REAL R[3][3],
		PQP_REAL T[3], 	  
		C2A_BV *b1, 
		C2A_BV *b2,
		PQP_REAL *mint,  
		PQP_REAL *distance);

	virtual bool  CAonNonAdjacentTriangles(
		PQP_REAL R[3][3], 
		PQP_REAL T[3],   
		PQP_REAL triA[3][3],
		PQP_REAL triB[3][3],  
		PQP_REAL *mint, 
		PQP_REAL *distance);
	


//protected:

};


#endif



