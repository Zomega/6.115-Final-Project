// Shanxi Gates Code

// Display allocations (while playing)
//
// 0 ship line
// 1 ship line
// 2 ship line
// 3 ship line
// 4 ship line
// 5 ship line
// 6 ship ellipse
// 7 ship ellipse
// 8 ship ellipse*
// 9 loop ellipse
// A star point*	The order of stars is the same as the order in the table.
// B star point*        Therefore the stars won't change addresses unless 
// C star point*
// D star point*
// E star point*
// F star point*
//
// Clearly more slots could be good.

#define NUM_STARS 20
vector3 stars[ NUM_STARS ]; // TODO: Generate the table of these. Need to have the property that no more than 6 are in any frame at a time.

void gameloop( spaceship* s, circle3* loop ) {

	float pitch = 0; // Ranges from +1 to -1
	float roll = 0; //  Ranges from +1 to -1

	// Update the game.
	//update_spaceship( s, d_heading );

	// TODO Check if we're passing through the loop.
	// If so, create a new loop.

	// Render the frame out to the 8051
	camera* c = get_view_from_spaceship( s );

	// TODO Render the spaceship

	// Render the loop
	ellipse2* projected_loop = render_circle( loop, c );
	if( projected_loop ) {
		disp_register_ellipse( projected_loop, 9 );
	} else {
		disp_clear( 9 );
	};

	int star_index = 0;
	int i = 0;
	// TODO Render the stars
	for(; i < NUM_STARS; i++ ) {
		if( /*star likely in view*/0 ) {
			disp_register_point( /*calculate without the camera*/0, 10 + star_index );
			star_index ++;
		}
	}
	// Pad out the rest without stars.
	while( star_index < 6 ) {
		disp_clear( 10 + star_index );
	}
};

