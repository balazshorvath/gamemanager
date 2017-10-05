#ifndef WORLD_H
#define WORLD_H

#include "math/vectors.h"

typedef struct Entity_ Entity;
typedef struct Area_ Area;
typedef struct World_ World;
typedef struct WorldConfig_ WorldConfig;

typedef struct Entity_ {
	int id;
	int state;
	char session[32];
	Vec3 position, speed, acceleration;
};

typedef struct Area_ {
	Vec3* edges;
	int edgeCount;
	/** 
	* Every Area gets it's edges and the memory
	* locations where the entities might be stored.
	* Index range in the World.entities.
	*/
	int fromIndex, toIndex;
	World* world;
};

typedef struct World_ {
	Entity* entities;
	Area* areas;
	
	int maxEntities;
	int areaSize;
	
	double* heightMap;
	int mapWidth;
};

typedef struct WorldConfig_ {
	int maxEntityCount;
	int maxAreaCount;
	
};

// World lifecycle events

int world_init(World** world, WorldConfig* config);
int world_tick(World* world);

#endif