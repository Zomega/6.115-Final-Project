typedef float scalar_t;

typedef struct {
    scalar_t x;
    scalar_t y;
} vector2;

typedef struct {
    scalar_t x;
    scalar_t y;
    scalar_t z;
} vector3;

scalar_t dot2( vector2 a, vector2 b ) {
	return a.x * b.x + a.y * b.y;
};

scalar_t dot3( vector3 a, vector3 b ) {
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

