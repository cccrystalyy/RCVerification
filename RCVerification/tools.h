#include "stdafx.h"
#include "sheval.h"
#include <time.h>  

inline REAL Dabs(REAL a){
	if(a > 0.0)
		return 1.0;
	else if(a < 0.0)
		return -1.0;
	else if(a = 0.0)
		return 0.0;
}

inline REAL Compute_fr(Vector w1, Vector w2);

inline REAL Compute_GradX_fr(Vector w1, Vector w2, REAL length);

REAL Compute_GradX_fr_2(Vector cache_pos, Vector sample_pos);

inline REAL GeoTerm(Vector v);

inline REAL GradX_GeoTerm(Vector v);

void SHEvaluate(const Vector &w, int lmax, float *out);

void Sample_contribution(Vector cache_pos, Vector sample_pos, REAL* out);

void Sample_contribution_GradX(Vector cache_pos, Vector sample_pos, REAL* out);

void Grad_contribution(Vector base_cache_pos, Vector sample_pos, REAL* out);

class UniformSurfaceSampler: public Sampler<Vector>{
public:
	REAL rpdf;
	REAL next(Vector * out);
	REAL counterX, counterY;


	UniformSurfaceSampler(REAL* lower_in, REAL* upper_in):Sampler(lower_in, upper_in, 2){
		srand (time(NULL));
		rpdf = gap[0]*gap[1];
		counterX = gap[0]-0.5;
		counterY = gap[1]-0.5;
	}
};


class ConstantIntegrand: public Integrand<Vector>{
public:
	REAL constant;


	ConstantIntegrand(){
		constant = 1.00;
	}

	REAL operator()(Vector sample){
		return constant;
	}

};



class ContributionIntegrand: public Integrand<Vector>{
public:
	Vector cache_pos;
	int l, m;


	ContributionIntegrand(Vector cache_pos_in, int l_in, int m_in):cache_pos(cache_pos_in),l(l_in),m(m_in){
	}

	REAL operator()(Vector sample){
		REAL *out = new REAL[max_SH_order*max_SH_order];
		Sample_contribution(cache_pos, sample, out);
		REAL ret= out[l*l + l +m];
		delete[] out;
		return ret;
	}

};



class GradXContributionIntegrand: public Integrand<Vector>{
public:
	Vector cache_pos;
	int l, m;
	int sh_index;

	GradXContributionIntegrand(Vector cache_pos_in, int l_in, int m_in):cache_pos(cache_pos_in),l(l_in),m(m_in){
		sh_index = l*l + l +m;
	}

	REAL operator()(Vector sample){
		REAL *out = new REAL[max_SH_order*max_SH_order];
		Sample_contribution_GradX(cache_pos, sample, out);
		REAL ret= out[sh_index];
		delete[] out;
		return ret;
	}

};