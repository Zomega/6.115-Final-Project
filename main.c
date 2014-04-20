#include<stdio.h>
// Compile on Linux x86 with `gcc main.c -lm -o main.o'
#include<stdlib.h>
#include <conio.h>

#include "geometry.c"

#include "camera.c"

#include "spaceship.c"

#include "display.c"

#include "shanxi_gates.c"

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

int main() {
	spaceship* s = malloc(sizeof(spaceship));
	s->speed = 1;
	set_identity( &(s->heading) );

	rotation3 d_heading;
	
	int i = 0;
	for(; i < 10; i++) {
		//if(kbhit()){ // TODO: Linux alternative. Does not have to be PSoC compatible.
		// TODO: see kbhit.c!
		//	char c = getch();
		//	printf("%c\n", c);
		//}
		print_spaceship( s );
		update_spaceship( s, d_heading );
		//gameloop( s, (circle3*)s );
	}

	vector3* p = malloc(sizeof(vector3));

	p->x = 3;
	p->y = 4;
	p->z = 0;

	printf( "%f\n", p->x );
	printf( "%f\n", len3(*p) );
	printf("\nHello World,\nWelcome to my first C program in Ubuntu Linux\n\n");
	return(0);
};
