#ifndef __ROTATION3_H__
#define __ROTATION3_H__

typedef matrix3 rotation3;

rotation3 get_rotation_roll( scalar_t roll ) {
	matrix3 result;

	result.row1.x = 1;
	result.row1.y = 0;
	result.row1.z = 0;

	result.row2.x = 0;
	result.row2.y = cos( roll );
	result.row2.z = -1 * sin( roll );

	result.row3.x = 0;
	result.row3.y = sin( roll );
	result.row3.z = cos( roll );

	return result;
};

rotation3 get_rotation_pitch( scalar_t pitch ) {
	matrix3 result;

	result.row1.x = cos( pitch );
	result.row1.y = 0;
	result.row1.z = sin( pitch );

	result.row2.x = 0;
	result.row2.y = 1;
	result.row2.z = 0;

	result.row3.x = -1 * sin( pitch );
	result.row3.y = 0;
	result.row3.z = cos( pitch );

	return result;
};

rotation3 get_rotation_yaw( scalar_t yaw ) {
	matrix3 result;

	result.row1.x = cos( yaw );
	result.row1.y = -1 * sin( yaw );
	result.row1.z = 0;

	result.row2.x = sin( yaw );
	result.row2.y = cos( yaw );
	result.row2.z = 0;

	result.row3.x = 0;
	result.row3.y = 0;
	result.row3.z = 1;

	return result;
};

rotation3 multiply_rotation3( rotation3 R1, rotation3 R2 ) {
	return multiply_matrix3( R1, R2 );
};

vector3 apply_rotation3( rotation3 R, vector3 v ) {
	return apply_matrix( R, v );
};

rotation3 get_rotation( scalar_t yaw, scalar_t pitch, scalar_t roll ) {
	rotation3 result = get_rotation_yaw( yaw );
	result = multiply_rotation3( get_rotation_pitch( pitch ), result );
	result = multiply_rotation3( get_rotation_roll( roll ), result );
	return result;
};

#endif
