#include <math.h>

#include "math/vectors.h"

__inline Vec3 vec_direction_vector(Vec3* v1) {
	double length = VEC_LENGTH((*v1));
	return (Vec3) { v1->x / length, v1->y / length, v1->z / length };
}
