#include "stdafx.h"
#include "sheval.h"

inline REAL Compute_fr(Vector w1, Vector w2);

inline REAL GeoTerm(Vector v);

void SHEvaluate(const Vector &w, int lmax, REAL *out);

void Sample_contribution(Vector cache_pos, Vector sample_pos, REAL* out);

class UniformSurfaceSampler: Sampler<Vector>{
	REAL rpdf;
	REAL next(Vector * out);


	UniformSurfaceSampler(REAL* lower_in, REAL* upper_in):Sampler(lower_in, upper_in, 2){
		rpdf = gap[0]*gap[1];
	}
};