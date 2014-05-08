#ifndef __VECTOR3_H__
#define __VECTOR3_H__

#include "scalar.c"

typedef struct {
    scalar_t x;
    scalar_t y;
    scalar_t z;
} vector3;

scalar_t dot3( vector3 v, vector3 u ) {
	return v.x * u.x + v.y * u.y + v.z * u.z;
};

scalar_t len_sq_3( vector3 v ) {
	return dot3( v, v );
};

scalar_t len3( vector3 v ) {
	return sqrt( len_sq_3( v ) );
};

vector3 add_vector3( vector3 v, vector3 u ) {
	vector3 w;
	w.x = v.x + u.x;
	w.y = v.y + u.y;
	w.z = v.z + u.z;
	return w;
};

vector3 subtract_vector3( vector3 v, vector3 u ) {
	vector3 w;
	w.x = v.x - u.x;
	w.y = v.y - u.y;
	w.z = v.z - u.z;
	return w;
};

vector3 scale_vector3( scalar_t a, vector3 v ) {
	vector3 w;
	w.x = a * v.x;
	w.y = a * v.y;
	w.z = a * v.z;
	return w;
};

#endif
