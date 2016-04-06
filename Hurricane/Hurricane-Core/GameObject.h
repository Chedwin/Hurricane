//*******************************//
//
// Name:			GameObject.h
// Description:		Abstract base class for all different types of game objects in a game.
//					Can be overridden by any type of game object.
//
// Author:			Edwin Chen
// Created:			Apr 5, 2016
// Last updated:	Apr 5, 2016
//
//*******************************//


#ifndef _GAMEOBJECT_H
#define _GAMEOBJECT_H

//#include <ode/ode.h>

#include "Macro.h"
#include "Vector.h"
#include "VMath.h"
#include "MMath.h"
#include "AABB.h"
#include "Texture.h"

using namespace MATH;

class GameObject {

public:
	virtual ~GameObject() {}

	virtual bool OnCreate() = 0;
	virtual void OnDestroy() = 0;
	virtual void FixedUpdate() = 0;
	virtual void Render(const Matrix4& projection) = 0;
public:
	Vec3 pos;
	Vec3 vel;
	Vec3 accel;
	float mass;

	inline void SetPos(const Vec3& _pos) {
		pos = _pos;
	}
	inline void SetVel(const Vec3& _vel) {
		vel = _vel;
	}

	inline Vec3 GetPos() const {
		return pos;
	}

	STRING name;

private:
	Texture* texture;
};

#endif