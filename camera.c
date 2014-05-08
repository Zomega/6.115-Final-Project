#include "geometry.c"

typedef struct {
	vector3 position;
	rotation3 facing;
} camera;

bool is_on_screen( vector2* v, float width, float height ) {
	if( 2 * fabs( v->x ) > width ) return false;
	if( 2 * fabs( v->y ) > height ) return false;
	return true;
};

vector2* clip_to_screen( vector2* v, float width, float height ) {
	if( is_on_screen( v, width, height ) ) return copy_vector2( v );
	float screen_aspect = width / height;
	float v_aspect = fabs( v->x / v->y );

	float scale_factor;
	if( v_aspect > screen_aspect ) {
		scale_factor = width / fabs( 2 * v->x );
	} else {
		scale_factor = height / fabs( 2 * v->y );
	}

	return scale_vector2( scale_factor, v );
};

vector2* render_point( vector3* point, camera* c ) {
	return NULL;
};

line_seg2* render_line_seg( line_seg3* line_seg, camera* c ) {
	return NULL;
};

ellipse2* render_circle( circle3* circle, camera* c ) { // See http://chrisjones.id.au/Ellipses/ellipse.html
	return NULL;
}
