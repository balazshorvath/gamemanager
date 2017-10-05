#include <math.h>

#include "math/vectors.h"


int world_init(World** world, WorldConfig* config) {
	
}

int world_tick(World* world) {
	// Step 0: Add spawned entities
	
	// Step 1.a: Set entity property changes (influence messages)
	// Step 1.b: Calculate entity movements
	// Step 1.c: Apply calculated changes (change current speed according to the acceleration for example)
	
	// Step 2.a: Move entities to proper indexes, based on the new locations (area changed)
	// Step 2.b: Might need to extend the index range belonging to the areas
	
	// Step 3: Statistics:
	// Step 3.a: 
	
}

