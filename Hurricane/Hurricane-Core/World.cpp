#include "World.h"

//void World::InitODE() {
//	odeWorld = dWorldCreate();
//	odeSpace = dSimpleSpaceCreate(0);
//	odeContactgroup = dJointGroupCreate(0);
//
//	// Create a ground plane in our collision space by passing Space as the first argument to dCreatePlane.
//	// The next four parameters are the planes normal (a, b, c) and distance (d) according to the plane
//	// equation a*x+b*y+c*z=d and must have length 1
//	dCreatePlane(odeSpace, 0, 1, 0, 0);
//
//	// Now we set the gravity vector for our world by passing World as the first argument to dWorldSetGravity.
//	// Earth's gravity vector would be (0, -9.81, 0) assuming that +Y is up. I found that a lighter gravity looked
//	// more realistic in this case.	
//	//dWorldSetGravity(world, 0, -1.0, 0);
//
//
//	// These next two functions control how much error correcting and constraint force mixing occurs in the world.
//	// Don't worry about these for now as they are set to the default values and we could happily delete them from
//	// this example. Different values, however, can drastically change the behaviour of the objects colliding, so
//	// I suggest you look up the full info on them in the ODE docs.
//
//	dWorldSetERP(odeWorld, 0.2);
//	dWorldSetCFM(odeWorld, 1e-5);
//
//	// This function sets the velocity that interpenetrating objects will separate at. The default value is infinity.
//	dWorldSetContactMaxCorrectingVel(odeWorld, 0.9);
//
//	// This function sets the depth of the surface layer around the world objects. Contacts are allowed to sink into
//	// each other up to this depth. Setting it to a small value reduces the amount of jittering between contacting
//	// objects, the default value is 0. 	
//	dWorldSetContactSurfaceLayer(odeWorld, 0.001);
//
//
//	// To save some CPU time we set the auto disable flag to 1. This means that objects that have come to rest (based
//	// on their current linear and angular velocity) will no longer participate in the simulation, unless acted upon
//	// by a moving object. If you do not want to use this feature then set the flag to 0. You can also manually enable
//	// or disable objects using dBodyEnable and dBodyDisable, see the docs for more info on this.
//	dWorldSetAutoDisableFlag(odeWorld, 1);
//}
//
//void World::CloseODE() {
//	// Destroy all joints in our joint group
//	dJointGroupDestroy(odeContactgroup);
//	// Destroy the collision space. When a space is destroyed, and its cleanup mode is 1 (the default) 
//	// then all the geoms in that space are automatically destroyed as well.
//	dSpaceDestroy(odeSpace);
//	// Destroy the world and everything in it. This includes all bodies and all joints that are not part of a joint group.
//	dWorldDestroy(odeWorld);
//}