// Some basic definitions and includes
#ifndef CORE_H
#define CORE_H

/////////////////////////////////////////////////////
#define USE_FLOAT
#ifdef USE_FLOAT
#define REAL float
#endif

#ifdef USE_DOUBLE
#define REAL double
#endif

#ifdef USE_LONG
#define REAL long double
#endif

//#define REAL double
//#define REAL long double
#define PI 3.141592653589793
/////////////////////////////////////////////////////

#include <iostream>
using namespace std;

#define isnan _isnan
#define isinf(f) (!_finite((f)))
#ifdef NDEBUG
#define Assert(expr) ((void)0)
#else
#define Assert(expr) \
    ((expr) ? (void)0 : cout<<"Fatal Error" << endl)
#endif // NDEBUG

////////////////////  Define Vector   ////////////////////////

/*
 Here vector is just a general class for all 3 dimenstion stuffs

 Adapted from pbrt
*/



class Vector {
public:
    // Vector Public Methods
    Vector() { x = y = z = 0.f; }
    Vector(REAL xx, REAL yy, REAL zz)
        : x(xx), y(yy), z(zz) {
        Assert(!HasNaNs());
    }
    bool HasNaNs() const { return isnan(x) || isnan(y) || isnan(z); }
    //explicit Vector(const Point &p);
#ifndef NDEBUG
    // The default versions of these are fine for release builds; for debug
    // we define them so that we can add the Assert checks.
    Vector(const Vector &v) {
        Assert(!v.HasNaNs());
        x = v.x; y = v.y; z = v.z;
    }
    
    Vector &operator=(const Vector &v) {
        Assert(!v.HasNaNs());
        x = v.x; y = v.y; z = v.z;
        return *this;
    }
#endif // !NDEBUG
    Vector operator+(const Vector &v) const {
        Assert(!v.HasNaNs());
        return Vector(x + v.x, y + v.y, z + v.z);
    }
    
    Vector& operator+=(const Vector &v) {
        Assert(!v.HasNaNs());
        x += v.x; y += v.y; z += v.z;
        return *this;
    }
    Vector operator-(const Vector &v) const {
        Assert(!v.HasNaNs());
        return Vector(x - v.x, y - v.y, z - v.z);
    }
    
    Vector& operator-=(const Vector &v) {
        Assert(!v.HasNaNs());
        x -= v.x; y -= v.y; z -= v.z;
        return *this;
    }
    Vector operator*(REAL f) const { return Vector(f*x, f*y, f*z); }
    
    Vector &operator*=(REAL f) {
        Assert(!isnan(f));
        x *= f; y *= f; z *= f;
        return *this;
    }
    Vector operator/(REAL f) const {
        Assert(f != 0);
        REAL inv = 1.f / f;
        return Vector(x * inv, y * inv, z * inv);
    }
    
    Vector &operator/=(REAL f) {
        Assert(f != 0);
        REAL inv = 1.f / f;
        x *= inv; y *= inv; z *= inv;
        return *this;
    }
    Vector operator-() const { return Vector(-x, -y, -z); }
    REAL operator[](int i) const {
        Assert(i >= 0 && i <= 2);
        return (&x)[i];
    }
    
    REAL &operator[](int i) {
        Assert(i >= 0 && i <= 2);
        return (&x)[i];
    }
    REAL LengthSquared() const { return x*x + y*y + z*z; }
    REAL Length() const { return sqrtf(LengthSquared()); }
    //explicit Vector(const Normal &n);

    bool operator==(const Vector &v) const {
        return x == v.x && y == v.y && z == v.z;
    }
    bool operator!=(const Vector &v) const {
        return x != v.x || y != v.y || z != v.z;
    }

    // Vector Public Data
    REAL x, y, z;
};

inline REAL Dot(const Vector &v1, const Vector &v2) {
    Assert(!v1.HasNaNs() && !v2.HasNaNs());
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}


inline REAL AbsDot(const Vector &v1, const Vector &v2) {
    Assert(!v1.HasNaNs() && !v2.HasNaNs());
    return fabsf(Dot(v1, v2));
}


inline Vector Cross(const Vector &v1, const Vector &v2) {
    Assert(!v1.HasNaNs() && !v2.HasNaNs());
    REAL v1x = v1.x, v1y = v1.y, v1z = v1.z;
    REAL v2x = v2.x, v2y = v2.y, v2z = v2.z;
    return Vector((v1y * v2z) - (v1z * v2y),
                  (v1z * v2x) - (v1x * v2z),
                  (v1x * v2y) - (v1y * v2x));
}

inline Vector Normalize(const Vector &v) { return v / v.Length(); }


inline REAL Random_Real(){
	return static_cast <REAL> (rand()) / static_cast <REAL> (RAND_MAX);
}


//////////////////////////// Global Parameters ////////////////////////


static REAL delta = 0.001;
static int max_SH_order = 10;

// BRDF Parameters
static int default_roughness = 10;
static REAL default_roughness_f = 10.0;
static REAL default_roh = 1.0;

// Light Position
static Vector light_pos = Vector(50.0, 50.0, 150.0);

// Cache Point Normal  
static Vector noraml_cache = Vector(0.0, 1.0, 0.0);


////////////////////////////////////////////////////////////////////////////


//////////////////////////// MC Integration ////////////////////////////////
//A generalized MC Integration

template <class T>
class Integrand{
public:
	//int dimension;
	virtual REAL operator()(T sample) = 0;
	/*Integrand(int dim)
        : dimension(dim) {
    }*/
};

template <class T>
class Sampler{
public:
	int dimension;
	REAL* lower;
	REAL* upper; 
	REAL* gap; 
	//return the rpdf
	virtual REAL next(T* out) =0;
	/*virtual REAL next(T* out){
		return 0.0;
	}*/

	Sampler(REAL* lower_in, REAL* upper_in, int dim)
        : dimension(dim) {
			lower = new REAL[dimension];
			upper = new REAL[dimension];
			gap = new REAL[dimension];
			for(int i_dim = 0; i_dim < dimension; i_dim++){
				lower[i_dim] = lower_in[i_dim];
				upper[i_dim] = upper_in[i_dim];
				gap[i_dim] = upper_in[i_dim]-lower_in[i_dim];
			}
    }

	~Sampler() {
		delete[] lower;
		delete[] upper;
		delete[] gap;
	}
};

template <class T>
class Integration_MC{
public:
	Sampler<T> *sampler;
	Integrand<T> *integrand;
	int N;
	REAL rN;

	Integration_MC(Sampler<T> *sampler_in, Integrand<T> *integrand_in, int N_in):sampler(sampler_in),integrand(integrand_in),N(N_in){
		rN = 1.0/ (REAL)N;
	}

	Integration_MC(int N_in):N(N_in){
		rN = 1.0/ (REAL)N;
	}

	void SetSampler(Sampler<T> *sampler_in){
		sampler = sampler_in;
	}


	REAL Run(){
		REAL sum = 0.0;
		T sample;
		for(int i = 0 ; i < N; i++){
			REAL rpdf = sampler->next(&sample);
			sum +=  rpdf *  (*integrand)(sample);
		}
		return sum*this->rN;
	}
};



/////////////////////////////////////////////////////////////////////////////

#endif //CORE_H