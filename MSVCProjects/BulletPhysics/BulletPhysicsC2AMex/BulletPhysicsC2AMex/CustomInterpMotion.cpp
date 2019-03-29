
#include "CustomInterpMotion.h"

CInterpMotion_Slerp::CInterpMotion_Slerp(const PQP_REAL R0[3][3],const PQP_REAL T0[3],const PQP_REAL R1[3][3],const PQP_REAL T1[3]):CInterpMotion(GMP_IM_SLERP, R0, T0, R1, T1)
{
	velocity();
}

CInterpMotion_Slerp::CInterpMotion_Slerp(const PQP_REAL q0[], const PQP_REAL q1[]):CInterpMotion(GMP_IM_SLERP, q0, q1)
{
	velocity();
}

CInterpMotion_Slerp::CInterpMotion_Slerp()
{

}

void CInterpMotion_Slerp::velocity()
{
	cv = (transform_t.Translation() - transform_s.Translation());
	LinearAngularVelocity(m_axis, m_angVel);
}

bool CInterpMotion_Slerp::integrate(const double dt_input, PQP_REAL qua[])
{
	
#ifdef IN_DEBUG_MODE_LEVEL_1

	mexPrintf("\nEntered CInterpMotion_Slerp::integrate()\n");

#endif
	
	double dt = dt_input;

	if(dt>1)
	{

		dt = 1.f;

	}

	// computing slerp translation
	Coord3D pos_t(0,0,0);

#ifdef IN_DEBUG_MODE_LEVEL_2

	mexPrintf("\nCalling CInterpMotion_Slerp::computeSlerpTranslation()\n");

#endif

	computeSlerpTranslation(dt,transform_s.Translation(),transform_t.Translation(),pos_t);

	transform.Set_Translation(pos_t);

	// compute linear quaternion interpolation
	Quaternion q_t(0,0,0,1);

#ifdef IN_DEBUG_MODE_LEVEL_2

	mexPrintf("\nCalling CInterpMotion_Slerp::computeLerpOrientation()\n");

#endif
	computeLerpOrientation(dt,transform_s.Quaternion_(),transform_t.Quaternion_(),q_t);

	transform.Set_Rotation(q_t);

	// populating input argument
	
	// quaternion
	qua[0] = transform.Quaternion_().W();
	qua[1] = transform.Quaternion_().X();
	qua[2] = transform.Quaternion_().Y();
	qua[3] = transform.Quaternion_().Z();

	// position
	qua[4] = transform.Translation().X();
	qua[5] = transform.Translation().Y();
	qua[6] = transform.Translation().Z();

#ifdef IN_DEBUG_MODE_LEVEL_2

	mexPrintf("\nExiting CInterpMotion_Slerp::integrate()\n");

#endif

	return true;

}

void CInterpMotion_Slerp::computeSlerpTranslation(const double dt,const Coord3D &pos_0,const Coord3D &pos_f,Coord3D &pos_t)
{
	double sin_theta = sin(m_angVel);
	double sin_thetaxt = sin(m_angVel*dt);
	double sin_thetax1_t = sin(m_angVel*(1.f-dt));

	Coord3D  p_t = (sin_thetax1_t*pos_0 + sin_thetaxt*pos_f)/sin_theta;

	p_t.Normalize();

	pos_t.Set_X(p_t.X());
	pos_t.Set_Y(p_t.Y());
	pos_t.Set_Z(p_t.Z());

}

void CInterpMotion_Slerp::computeSlerpOrientation(const double dt, const Quaternion &q_0, const Quaternion &q_f, Quaternion &q_t)
{
	double sin_theta = sin(m_angVel);
	double sin_thetaxt = sin(m_angVel*dt);
	double sin_thetax1_t = sin(m_angVel*(1.f-dt));

	Quaternion qua_t = (sin_thetax1_t*q_0 + sin_thetaxt*q_f)/sin_theta;

	qua_t.Normalize();

	q_t.Set_W(qua_t.W());
	q_t.Set_X(qua_t.X());
	q_t.Set_Y(qua_t.Y());
	q_t.Set_Z(qua_t.Z());

}

void CInterpMotion_Slerp::computeLerpOrientation(const double dt, const Quaternion &q_0, const Quaternion &q_f, Quaternion &q_t)
{
	Quaternion qua_t = (1.f - dt)*q_0 + (dt)*q_f;

	qua_t.Normalize();

	q_t.Set_W(qua_t.W());
	q_t.Set_X(qua_t.X());
	q_t.Set_Y(qua_t.Y());
	q_t.Set_Z(qua_t.Z());

}


//compute TOC without motion bound
double CInterpMotion_Slerp::computeTOC(PQP_REAL d, PQP_REAL r1)
{
#ifdef IN_DEBUG_MODE_LEVEL_1

	mexPrintf("\nEntered CInterpMotion_Slerp::computTOC1()\n");

#endif
	
	PQP_REAL time;

	PQP_REAL w_max =  r1 * fabs(m_angVel); //m_angVel;  the angular velocity around that axis: counter clockwise
					                       // it might be negative, which means the clockwise rotation
    Coord3D v3;
#ifdef SCREW_MOTION
	v3=cv_screw;
#else
	v3=cv;
#endif

	PQP_REAL v_max = v3.Length();
	PQP_REAL path_max= w_max + v_max;

	time = ConservD(d) / path_max;// ConservD = d - security_distance_ratio * m_toc_delta 

	return time;
}


double CInterpMotion_Slerp::computeTOC(PQP_REAL d, PQP_REAL r1, PQP_REAL S[3])
{
	
#ifdef IN_DEBUG_MODE_LEVEL_1

	mexPrintf("\nEntered CInterpMotion_Slerp::computeTOC2()\n");

#endif

	PQP_REAL cwc[3], cross[3];
    PQP_REAL v_max,w_max;

	Vnormalize(S);


	if (m_angVel==0)
	{
		w_max=0;
		PQP_REAL cvc[3];

#ifdef SCREW_MOTION

		PQP_REAL cc[3],temp1[3],temp2[3],temp;
		VxS(cc,m_screw.S,m_screw.d);
		Coord3D temp4=transform_s.Translation();
		temp4.Get_Value(temp1);
		VmV(temp1,temp1,m_screw.p);
		VcrossV(temp2,temp1,m_screw.S);
		v_max = (VdotV(cc, S));
		temp=r1+Vlength(temp2);
		w_max = temp * Vlength(cross);

#else
		cv.Get_Value(cvc);
#endif	

		v_max= VdotV(cvc, S);
		if (v_max<0)
		{
			v_max=0;
		}
	}
	else
	{
		m_axis.Get_Value(cwc);
		cwc[0] *= m_angVel;
		cwc[1] *= m_angVel;
		cwc[2] *= m_angVel;
		VcrossV(cross, cwc, S);

		//compute the angular motion
		w_max =  r1 * Vlength(cross);	

		//compute the translation motion
		PQP_REAL cvc[3];

#ifdef SCREW_MOTION
		PQP_REAL cc[3],temp1[3],temp2[3],temp;
		VxS(cc,m_screw.S,m_screw.d);
		Coord3D temp4=transform_s.Translation();
		temp4.Get_Value(temp1);
		VmV(temp1,temp1,m_screw.p); 
		VcrossV(temp2,temp1,m_screw.S);
		v_max = (VdotV(cc, S));
		temp=r1+Vlength(temp2);
		w_max = temp * Vlength(cross);
#else
		cv.Get_Value(cvc);
		v_max= VdotV(cvc, S);
#endif	
		
		if (v_max<0)
		{
			v_max=0;
		}

		//angular motion + translation motion


	}
	PQP_REAL path_max= w_max + v_max;

	if(path_max==0)
	{
		path_max=1e-30;
	}

	return path_max;
}


double CInterpMotion_Slerp::computeTOC_MotionBound(PQP_REAL T[3], PQP_REAL d, C2A_BV *V, PQP_REAL N[3])
{	
	
#ifdef IN_DEBUG_MODE_LEVEL_1

	mexPrintf("\nEntered CInterpMotion_Slerp::computeTOC_MotionBound()\n");

#endif
	
	PQP_REAL  cwc[3], cross[3], w_max, C1[3],C2[3],C3[3],C4[3],a1,a2,a3,a4,a;

	//set the direction
	Vnormalize(N);
	m_axis.Get_Value(cwc);
	VcrossV(cross, cwc, N);
	VcrossV(C1,V->Corner[0],T);
	VcrossV(C2,V->Corner[1],T);
	VcrossV(C3,V->Corner[2],T);
	VcrossV(C4,V->Corner[3],T);	
		
	a1=Vlength(C1);
	a2=Vlength(C2);
	a3=Vlength(C3);
	a4=Vlength(C4);
		
	a= a1;
	if (a2 > a) a = a2;
	if (a3 > a) a = a3;
	if (a4 > a) a = a4;   
	


	PQP_REAL temp=V->r+a;
	if (temp>V->angularRadius)
	{
		temp=V->angularRadius;		

	}

    w_max = (temp)* Vlength(cross)*m_angVel;
  
	PQP_REAL cvc[3], v_max;

#ifdef SCREW_MOTION

	PQP_REAL cc[3],temp1[3],temp2[3],temp5;
	VxS(cc,m_screw.S,m_screw.d);
	Coord3D temp4=transform_s.Translation();
	temp4.Get_Value(temp1);
	VmV(temp1,temp1,m_screw.p);
	VcrossV(temp2,temp1,m_screw.S);
	v_max = VdotV(cc, N);
	temp5 = V->angularRadius + Vlength(temp2);
	w_max = temp5 * Vlength(cross);

#else
	cv.Get_Value(cvc);
	v_max = VdotV(cvc, N);
#endif	

	
	if (v_max<0)
	{
		v_max=0;
	}
	
	//angular motion + translation motion
	PQP_REAL path_max= v_max+w_max;
	if (path_max<=0)
	{
		path_max=1e-30;
	}
	
	return path_max;

}

bool  CInterpMotion_Slerp::CAonRSS(PQP_REAL r1[3][3], PQP_REAL tt1[3],
									PQP_REAL r2[3][3],PQP_REAL tt2[3], 
									PQP_REAL R[3][3],PQP_REAL T[3], 
									C2A_BV *b1, C2A_BV *b2, 
									PQP_REAL *mint,  PQP_REAL *distance)
{

#ifdef IN_DEBUG_MODE_LEVEL_1

	mexPrintf("\nEntered CInterpMotion_Slerp::CAonRSS()\n");

#endif

	PQP_REAL c1_clo[3], c2_clo[3], temp1[3], result1[3], result2[3], temp2[3];

	bool bValid_C_clo;
	PQP_REAL S[3];

	double d = C2A_BV_Distance(R, T, b1, b2, c1_clo, c2_clo, bValid_C_clo,S);

	MxV(temp1, b1->R_loc, S);
	MxV(S, r1, temp1);
	 
	PQP_REAL cvc[3], Vel[3];
	cv.Get_Value(cvc);

	MTxV(temp1, r1, cvc);
	MTxV(Vel, b1->R_loc, temp1);

	PQP_REAL tocf = computeTOC(d, b1->angularRadius,S);

	PQP_REAL  total_toc=tocf;
	int nIters=1;

	while ((d>=m_toc_delta)&&(total_toc<=mint[0])&&(nIters<50))
	{
		VpVxS(temp2,T,Vel,-total_toc);			

		d=C2A_BV_Distance(R, temp2, b1, b2, c1_clo, c2_clo, bValid_C_clo,S);
		if (d==0)
		{
			break;
		}

		if(!bValid_C_clo)
		{
			//compute the normal  
	    	MxV(temp1, r1, b1->com);
			VpV(temp2, temp1, tt1);
			VpVxS(result1, temp2, cvc,total_toc);

			MxV(temp2, r2, b2->com);
			VpV(result2, temp2, tt2);  

			VmV(S,result2,result1);



		}
		else
		{
			MxV(temp1, b1->R_loc, S);
			MxV(S, r1, temp1);
		} 

		tocf = computeTOC(d, b1->angularRadius,S);

		nIters++;

		if(tocf<m_toc_delta) 
			break;

		total_toc+=tocf;

	}

	if (total_toc<1.0)
	{
		mint[0]=total_toc;
		distance[0]=(total_toc-m_toc_delta)*Vlength(cvc);
		if (distance[0]<0)
		{
           distance[0]=0;

		}
		return true;

	}

	return false;


}

bool  CInterpMotion_Slerp::CAonNonAdjacentTriangles(PQP_REAL R[3][3], PQP_REAL T[3], 
													 PQP_REAL triA[3][3],PQP_REAL triB[3][3],
													 PQP_REAL *mint, PQP_REAL *distance)
{

#ifdef IN_DEBUG_MODE_LEVEL_1

	mexPrintf("\nEntered CInterpMotion_Slerp::CAonNonAdjacentTriangles()\n");

#endif

	PQP_REAL p[3],q[3],triA_t[3][3];

	PQP_REAL Vel[3];
	PQP_REAL cvc[3];
	cv.Get_Value(cvc);
	MTxV(Vel, R,cvc);

	PQP_REAL d=TriDist(p,q,triA,triB);

	PQP_REAL n[3],total_toc;
	VmV(n,q,p);
	Vnormalize(n);		

	PQP_REAL u= (VdotV(Vel, n));

	if (u<=0)
	{
		u=1e-30;
	}
		
	if (d==0)//&& u>SMALL_NUM
	{
		mint[0]=0.0;
		distance[0]=0.0;
		return true;
	}

		PQP_REAL dt=ConservD(d)/u;//
		int nIters=1;

		if (dt>=mint[0])
		{
			
			return false;

		}
		total_toc=dt;
	

		while ((d>m_toc_delta)&&(total_toc<=mint[0])&&(nIters<50))
		{
			for(int i=0;i<3;i++)
			{
				VpVxS(triA_t[i],triA[i],Vel,total_toc);
				
			}				

			d=TriDist(p,q,triA_t,triB);
			if (d==0.0)
			{
				break;
			}

		
			VmV(n,q,p);

			Vnormalize(n);
			u=(VdotV(Vel, n));
			if (u<=0)
			{
				u=1e-30;
			}
			PQP_REAL tofc=ConservD(d)/u;//
			nIters++;
            
			if(tofc<m_toc_delta) 
				break;
            total_toc+=tofc;
			

		}

		if (total_toc<=mint[0]&&total_toc>=0.0)//
		{
			mint[0]=total_toc;
			distance[0]=(total_toc)*Vlength(cvc)+m_toc_delta;
			return true;

		}

		return false;

}

CInterpMotion_Slerp::~CInterpMotion_Slerp()
{

}







	






