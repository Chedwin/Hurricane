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

//#include <Macro.h>
#include "Vector.h"
#include "AABB.h"
#include "Texture.h"

using namespace MATH;

class GameObject {

public:
	virtual bool OnCreate() = 0;
	virtual void OnDestroy() = 0;
	virtual void FixedUpdate() = 0;
	virtual void Render() = 0;
public:
	Vec2 pos;
	Vec2 vel;
	Vec2 accel;
	float mass;
	AABB gameObjectAABB;

	//STRING name;

private:
	Texture* texture;
};

#endif