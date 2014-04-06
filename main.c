#include<stdio.h>
#include<stdlib.h>

#include "geometry.c"

#include "camera.c"

#include "spaceship.c"

#include "display.c"

#include "shanxi_gates.c"

int main() {
	vector3 *p = malloc(sizeof(vector3));

	p->x = 3;
	p->y = 4;
	p->z = 0;

	printf( "%f\n", p->x );
	printf( "%f\n", len3(*p) );
	printf("\nHello World,\nWelcome to my first C program in Ubuntu Linux\n\n");
	return(0);
};
