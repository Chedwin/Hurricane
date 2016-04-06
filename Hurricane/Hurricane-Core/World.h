#pragma once

//#include <ode/ode.h>
#include "Matrix.h"

using namespace MATH;

class World {
public:
	virtual ~World() {}

	virtual bool OnCreate() = 0;
	virtual void OnDestroy() = 0;
	virtual void FixedUpdate() = 0;
	virtual void Render(const Matrix4& projection) = 0;
public:
	/*dWorldID ode_world;
	void dWorldDestroy(dWorldID _world);*/
};
