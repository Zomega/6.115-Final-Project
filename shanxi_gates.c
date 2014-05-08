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


/******************************************************************************
*
* BEGIN Generated Code
*
* This code is generated from star_gen.py
* The unit vectors involved here have the property that no more than 6 are in
* any frame at a time.
*
* Therefore DO NOT EDIT THESE BY HAND. Regenerate them until a desired property
* is achived.
*
******************************************************************************/
#define NUM_STARS 7
vector3 stars[ NUM_STARS ] = {
	0.861333047357, 0.47083519562, -0.190839199581,
	0.822868493002, -0.523455109983, 0.221093172799,
	-0.900596228706, -0.298527877024, -0.315923312655,
	-0.0235562239282, -0.879295873662, -0.475693042701,
	0.579002403227, 0.692105083741, -0.430983491699,
	0.849317844461, -0.0369396140616, -0.526587755263,
	0.478818654653, -0.63562308656, -0.605570795026,
};
/******************************************************************************
*
* END Generated code.
*
******************************************************************************/

void update_state( spaceship* s, circle3* loop, float d_time ) {

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

