#include <math.h>

#include "math/vectors.h"

__inline Vec3 vec3_direction_vector(Vec3* v1) {
	double length = VEC3_LENGTH((*v1));
	return (Vec3) { v1->x / length, v1->y / length, v1->z / length };
}

__inline Vec2 vec2_direction_vector(Vec2* v1) {
	double length = VEC2_LENGTH((*v1));
	return (Vec2) { v1->x / length, v1->y / length };
}
