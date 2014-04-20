//#include "geometry.c"

typedef struct {
	vector3 position;
	rotation3 facing;
} camera;

vector2* render_point( vector3* point, camera* c );

line_seg2* render_line_seg( line_seg3* line_seg, camera* c );

ellipse2* render_circle( circle3* circle, camera* c ); // See http://chrisjones.id.au/Ellipses/ellipse.html

ellipse2* render_circle( circle3* circle, camera* c ) { // TODO Replace this silly stub.
	return NULL;
}
