typedef struct {
	vector3 position;
	rotation3 heading;
	scalar_t speed;
} spaceship;

// TODO: Include delta time stuff.
void update_spaceship( spaceship* s, rotation3 d_heading ) {

	s->heading = multiply_rotation3( s->heading, d_heading );

	vector3 velocity;
	velocity.x = s->speed;
	velocity.y = 0;
	velocity.z = 0;
	velocity = apply_rotation3( s->heading, velocity );

	s->position = add_vector3(
		s->position,
		velocity
	);
};

camera* get_view_from_spaceship( spaceship* viewer ) {
	camera* c = malloc(sizeof(camera));
	c->position = viewer->position;
	c->facing = viewer->heading;
	return c;
};
