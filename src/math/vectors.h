#ifndef VECTORS_H
#define VECTORS_H

typedef struct {
	double x, y;
} Vec2;

typedef struct {
	double x, y, z;
} Vec3;

#define VEC2(x, y) (Vec2) { x, y }

#define VEC2_ADD(v1, v2) (Vec2) { v1.x + v2.x, v1.y + v2.y}
#define VEC2_SUB(v1, v2) (Vec2) { v1.x - v2.x, v1.y - v2.y}
#define VEC2_DIV(v1, v2) (Vec2) { v1.x / v2.x, v1.y / v2.y}
#define VEC2_MUL(v1, d) (Vec2) { v1.x * d, v1.y * d}

#define VEC2_SCALAR(v1, v2) (v1.x * v2.x + v1.y * v2.y)

#define VEC2_LENGTH(v1) sqrt(v1.x * v1.x + v1.y * v1.y)

#define VEC3(x, y, z) (Vec3) { x, y, z }

#define VEC3_ADD(v1, v2) (Vec3) { v1.x + v2.x, v1.y + v2.y, v1.z + v2.z }
#define VEC3_SUB(v1, v2) (Vec3) { v1.x - v2.x, v1.y - v2.y, v1.z - v2.z }
#define VEC3_DIV(v1, v2) (Vec3) { v1.x / v2.x, v1.y / v2.y, v1.z / v2.z }
#define VEC3_MUL(v1, d) (Vec3) { v1.x * d, v1.y * d, v1.z * d }

#define VEC3_SCALAR(v1, v2) (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z)

#define VEC3_LENGTH(v1) sqrt(v1.x * v1.x + v1.y * v1.y + v1.z * v1.z)

__inline Vec2 vec2_direction_vector(Vec2* v1);
__inline Vec3 vec3_direction_vector(Vec3* v1);


#endif /* VECTORS_H */