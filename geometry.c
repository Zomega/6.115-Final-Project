#ifndef __GEOMETRY_H__
#define __GEOMETRY_H__

#include <math.h> // TODO proper include structure.
#include "geometry/scalar.c"

#include "geometry/vector2.c"
#include "geometry/vector3.c"

#include "geometry/matrix3.c"

#include "geometry/rotation3.c"

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

#endif
