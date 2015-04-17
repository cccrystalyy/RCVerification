#include "tools.h"


////////////////////  Define BRDF Function   //////////////////////////////////////////

inline REAL Compute_fr(Vector w1, Vector w2){
	Vector wr = Vector(-w1.x, -w1.y, w1.z);
	return pow( Dot(wr,w2), default_roughness) * (default_roughness_f + 1.0) / (2.0 * PI);
}


inline REAL Compute_GradX_fr(Vector wo, Vector wr, REAL length){
	REAL aux = (default_roughness_f + 1.0) * default_roughness_f / (2.0 * PI * length);
	REAL aux2 = wr.x - wo.x * (wo.x * wr.x + wo.y * wr.y + wo.z * wr.z);
	return pow(wo.x*wr.x + wo.y * wr.y + wo.z * wr.z, default_roughness_f - 1.0) * aux * aux2;
}

REAL Compute_GradX_fr_2(Vector cache_pos, Vector sample_pos){
	Vector wo, wr;
	wo = cache_pos - sample_pos;
	REAL length = wo.Length();
	wo = Normalize(wo);
	wr = Normalize(light_pos - sample_pos);
	wr = Vector(-wr.x, -wr.y, wr.z);
	return Compute_GradX_fr(wo, wr, length);
}

////////////////////////////////////////////////////////////////////////////////////


////////////////////  Light   //////////////////////////////////////////
//inline Vector Sample_light(Vector pos_x){
//	return Normalize(light_pos - pos_x);
//}

////////////////////////////////////////////////////////////////////////////////////




////////////////////  GeoTerm   //////////////////////////////////////////
// v= sample_pos - cache pos = sampleX- cacheX, sampleY, -cacheZ
inline REAL GeoTerm(Vector v){
	return - (Normalize(v).z / v.LengthSquared());
}



inline REAL GradX_GeoTerm(Vector v){
	REAL aux =  - 3.0 * v.z * abs(v.x) * Dabs(v.x);
	return aux/pow(v.Length(), 5);
}


////////////////////////////////////////////////////////////////////////////////////


////////////////////  SH Eval   //////////////////////////////////////////
void SHEvaluate(const Vector &w, int lmax, float *out) {
   float fX = w.x;
   float fY = w.y;
   float fZ = w.z;

   int tmp_order;

   if(lmax > 9)
      tmp_order = 10;
   else 
      tmp_order = lmax+1;


   switch(tmp_order){
      case 3: SHEval3( fX, fY, fZ, out);
               break;
      case 4: SHEval4( fX, fY, fZ, out);
               break;
      case 5: SHEval5( fX, fY, fZ, out);
               break;
      case 6: SHEval6( fX, fY, fZ, out);
               break;
      case 7: SHEval7( fX, fY, fZ, out);
               break;
      case 8: SHEval8( fX, fY, fZ, out);
               break;
      case 9: SHEval9( fX, fY, fZ, out);
               break;
      case 10: SHEval10( fX, fY, fZ, out);
               break;
      default: SHEval3( fX, fY, fZ, out);
               break;
   }
}
////////////////////////////////////////////////////////////////////////////////////





//////////////////////////  Sample Contribution   ///////////////////////////////////
void Sample_contribution(Vector cache_pos, Vector sample_pos, REAL* out){
	REAL geo_term = GeoTerm(sample_pos - cache_pos);
	REAL fr_term = Compute_fr(Normalize(cache_pos - sample_pos),  Normalize(light_pos - sample_pos));
	float *ylm = new float[max_SH_order * max_SH_order];
	SHEvaluate(Normalize(sample_pos - cache_pos), max_SH_order-1, ylm);
	for (int k =0; k < max_SH_order * max_SH_order ; k++){
		out[k] = ylm[k] * geo_term * fr_term;
	}
	delete[] ylm;

}


void Sample_contribution_GradX(Vector cache_pos, Vector sample_pos, REAL* out){
	REAL geo_term = GeoTerm(sample_pos - cache_pos);
	REAL grad_geo_term = GradX_GeoTerm(sample_pos - cache_pos);
	REAL fr_term = Compute_fr(Normalize(cache_pos - sample_pos),  Normalize(light_pos - sample_pos));
	REAL grad_fr_term = Compute_GradX_fr_2(cache_pos, sample_pos);
	float *ylm = new float[max_SH_order * max_SH_order];
	float *ylmdx = new float[max_SH_order * max_SH_order];
	SHEvaluate(Normalize(sample_pos - cache_pos), max_SH_order-1, ylm);
	ShbaisGrad(ylmdx, sample_pos - cache_pos, max_SH_order);


	for (int k =0; k < max_SH_order * max_SH_order ; k++){
		out[k] = ylmdx[k] * geo_term * fr_term + ylm[k] * grad_geo_term * fr_term + ylm[k] * geo_term * grad_fr_term;
	}

	delete[] ylm;
	delete[] ylmdx;
}

////////////////////////////////////////////////////////////////////////////////////


//
//
//REAL UniformSurfaceSampler::next(Vector * out){
//	out->x = Random_Real()*gap[0] + lower[0];
//	out->y = Random_Real()*gap[1] + lower[1];
//	out->z = 0.0;
//
//	return rpdf;
//}






REAL UniformSurfaceSampler::next(Vector * out){
	out->x = counterX - Random_Real() + 0.5;
	out->y = counterY - Random_Real() + 0.5;
	counterX = counterX - 1.0;
	if(counterX <= lower[0]){
		counterX = upper[0]-0.5;
		counterY = counterY - 1.0;
	}

	if(counterY <= lower[1]){
		counterY = upper[1]-0.5;
	}

	return rpdf;
}