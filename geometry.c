#include <math.h>

typedef float scalar_t;

typedef struct {
    scalar_t x; // TODO: Ensure array addressible.
    scalar_t y;
} vector2;

typedef struct {
    scalar_t x;
    scalar_t y;
    scalar_t z;
} vector3;

scalar_t dot2( vector2 v, vector2 u ) {
	return v.x * u.x + v.y * u.y;
};

scalar_t dot3( vector3 v, vector3 u ) {
	return v.x * u.x + v.y * u.y + v.z * u.z;
};

scalar_t len_sq_2( vector2 v ) {
	return dot2( v, v );
};

scalar_t len_sq_3( vector3 v ) {
	return dot3( v, v );
};

scalar_t len2( vector2 v ) {
	return sqrt( len_sq_2( v ) );
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

typedef struct {
	vector3 row1; // TODO: Arrays?
	vector3 row2;
	vector3 row3;
} matrix3;

typedef matrix3 rotation3; // Other properties enforced by software. TODO: Check these / write them down.

typedef struct {
	vector2 start;
	vector2 finish;
} line_seg2;

typedef struct {
	vector3 start;
	vector3 finish;
} line_seg3;

typedef struct {
	vector3 center;
	vector3 normal;
	scalar_t radius;
} circle3;

typedef struct {
	vector2 center;
	vector2 axis1;
	vector2 axis2;
} ellipse2;

matrix3 multiply_matrix3( matrix3 A, matrix3 B ) {
	matrix3 result;

	// TODO: These are wrong...
	result.row1.x = A.row1.x * B.row1.x + A.row1.y * B.row2.x + A.row1.z * B.row3.x;
	result.row1.y = A.row1.x * B.row1.y + A.row1.y * B.row2.y + A.row1.z * B.row3.y;
	result.row1.z = A.row1.x * B.row1.y + A.row1.y * B.row2.y + A.row1.z * B.row3.y;

	result.row2.x = A.row1.x * B.row1.x + A.row1.y * B.row2.x + A.row1.z * B.row3.x;
	result.row2.y = A.row1.x * B.row1.x + A.row1.y * B.row2.x + A.row1.z * B.row3.x;
	result.row2.z = A.row1.x * B.row1.x + A.row1.y * B.row2.x + A.row1.z * B.row3.x;

	result.row3.x = A.row1.x * B.row1.x + A.row1.y * B.row2.x + A.row1.z * B.row3.x;
	result.row3.y = A.row1.x * B.row1.x + A.row1.y * B.row2.x + A.row1.z * B.row3.x;
	result.row3.z = A.row1.x * B.row1.x + A.row1.y * B.row2.x + A.row1.z * B.row3.x;

	return result; //TODO Write this
};

vector3 apply_matrix( matrix3 A, vector3 v ) {
	vector3 result;
	result.x = dot3( A.row1, v );
	result.y = dot3( A.row2, v );
	result.z = dot3( A.row3, v );
	return result;
};

rotation3 multiply_rotation3( rotation3 R1, rotation3 R2 ) {
	return multiply_matrix3( R1, R2 );
};

vector3 apply_rotation3( rotation3 R, vector3 v ) {
	return apply_matrix( R, v );
};
