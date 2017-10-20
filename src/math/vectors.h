#ifndef VECTORS_H
#define VECTORS_H

typedef struct {
	double x, y, z;
} Vec3;

#define VEC(x, y, z) (Vec3) { x, y, z }

#define VEC_ADD(v1, v2) (Vec3) { v1.x + v2.x, v1.y + v2.y, v1.z + v2.z }
#define VEC_SUB(v1, v2) (Vec3) { v1.x - v2.x, v1.y - v2.y, v1.z - v2.z }
#define VEC_DIV(v1, v2) (Vec3) { v1.x / v2.x, v1.y / v2.y, v1.z / v2.z }
#define VEC_MUL(v1, d) (Vec3) { v1.x * d, v1.y * d, v1.z * d }

#define VEC_SCALAR(v1, v2) (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z)

#define VEC_LENGTH(v1) sqrt(v1.x * v1.x + v1.y * v1.y + v1.z * v1.z)

__inline Vec3 vec_direction_vector(Vec3* v1);

#endif /* VECTORS_H */