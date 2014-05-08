#ifndef __MATRIX3_H__
#define __MATRIX3_H__

typedef struct {
	vector3 row1; // TODO: Arrays?
	vector3 row2;
	vector3 row3;
} matrix3;

vector3 col( matrix3 A, int col_num ) {
	vector3 result;
	switch ( col_num ) {
		case 1:
			result.x = A.row1.x;
			result.y = A.row2.x;
			result.z = A.row3.x;
			break;
		case 2:
			result.x = A.row1.y;
			result.y = A.row2.y;
			result.z = A.row3.y;
			break;
		case 3:
		default:
			result.x = A.row1.z;
			result.y = A.row2.z;
			result.z = A.row3.z;
			break;
	}
	return result;
};

vector3 row( matrix3 A, int row_num ) {
	switch ( row_num ) {
		case 1:
			return A.row1;
		case 2:
			return A.row2;
		case 3:
		default:
			return A.row3;
	}
};

matrix3 multiply_matrix3( matrix3 A, matrix3 B ) {
	matrix3 result;

	result.row1.x = dot3( row( A, 1 ), col( B, 1 ) );
	result.row1.y = dot3( row( A, 1 ), col( B, 2 ) );
	result.row1.z = dot3( row( A, 1 ), col( B, 3 ) );

	result.row2.x = dot3( row( A, 2 ), col( B, 1 ) );
	result.row2.y = dot3( row( A, 2 ), col( B, 2 ) );
	result.row2.z = dot3( row( A, 2 ), col( B, 3 ) );

	result.row3.x = dot3( row( A, 3 ), col( B, 1 ) );
	result.row3.y = dot3( row( A, 3 ), col( B, 2 ) );
	result.row3.z = dot3( row( A, 3 ), col( B, 3 ) );

	return result;
};

vector3 apply_matrix( matrix3 A, vector3 v ) {
	vector3 result;
	result.x = dot3( A.row1, v );
	result.y = dot3( A.row2, v );
	result.z = dot3( A.row3, v );
	return result;
};

#endif
