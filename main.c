// Compile on Linux x86 with `gcc main.c -lm -o main.o'
#include<stdio.h>
#include<stdlib.h>
typedef enum { false, true } bool;

#include "geometry.c"

#include "camera.c"

#include "spaceship.c"

#include "display.c"

#include "shanxi_gates.c"

// Linux Specific includes...
#include "kbhit.c"

void print_vector( vector3* v ) {
	printf( "%f \t%f \t%f\n", v->x, v->y, v->z );
}

void print_matrix( matrix3* m ) {
	print_vector( &( m->row1 ) );
	print_vector( &( m->row2 ) );
	print_vector( &( m->row3 ) );
}

void print_spaceship( spaceship* s ) {
	printf( "Spaceship:\n" );

	printf( "\tPosition:\n\t" );
	print_vector( &(s->position) );

	printf( "\n\tHeading:\n" );
	print_matrix( &(s->heading) );

	printf( "\n\tSpeed:\t%f\n", s->speed );

	vector3 velocity;
	velocity.x = s->speed;
	velocity.y = 0;
	velocity.z = 0;
	velocity = apply_rotation3( s->heading, velocity );

	printf( "\n\tVelocity:\n\t" );
	print_vector( &velocity );
	return;
}

void set_identity( rotation3* rot ) {
	rot->row1.x = 1;
	rot->row2.y = 1;
	rot->row3.z = 1;

	print_matrix( rot );
}


void update_controls() {
	if(kbhit()){ // TODO: Linux alternative. Does not have to be PSoC compatible.
		// TODO: see kbhit.c!
		char c = getchar();
		printf("%c\n", c);
	}
}
int main() {
	spaceship* s = malloc(sizeof(spaceship));
	s->speed = 1;
	set_identity( &(s->heading) );
	
	int i = 0;
	for(; i < 10; i++) {
		print_spaceship( s );

		float yaw = 0.0;
		float pitch = 0.0;
		float roll = 0.2;

		rotation3 d_heading = get_rotation( yaw, pitch, roll );
		update_spaceship( s, d_heading );
		printf("\n");
		//gameloop( s, (circle3*)s );
	}

	vector2 v;
	v.x = 1;
	v.y = 10;
	vector2* w = clip_to_screen( &v, 6, 4 );
	printf( "%f \t%f\n", w->x, w->y );

	return;
};
