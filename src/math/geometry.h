#ifndef GEOMETRY_H
#define GEOMETRY_H

#include "vectors.h"

typedef struct {
	//TODO
} Circle;

typedef struct {
	//TODO
} Polygon;

int circle_inside(Circle* circle, Vec3* point);

int polygon_inside(Polygon* polygon, Vec3* point);


#endif /* GEOMETRY_H */