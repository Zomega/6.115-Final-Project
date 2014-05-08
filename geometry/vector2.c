#ifndef __VECTOR2_H__
#define __VECTOR2_H__

#include "scalar.c"

typedef struct {
    scalar_t x;
    scalar_t y;
} vector2;

scalar_t dot2( vector2 v, vector2 u ) {
	return v.x * u.x + v.y * u.y;
};

scalar_t len_sq_2( vector2 v ) {
	return dot2( v, v );
};

scalar_t len2( vector2 v ) {
	return sqrt( len_sq_2( v ) );
};

vector2* scale_vector2( scalar_t a, vector2* v ) {
	vector2* w = malloc(sizeof(vector2));
	w->x = a * v->x;
	w->y = a * v->y;
	return w;
};

vector2* copy_vector2( vector2* v ) {
	vector2* w = malloc(sizeof(vector2));
	w->x = v->x;
	w->y = v->y;
	return w;
};

#endif
