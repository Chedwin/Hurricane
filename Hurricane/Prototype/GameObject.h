//*******************************//
//
// Name:			GameObject.h
// Description:		Establishes an abstract "Scene" class for all types of Scene to use
//					This includes our game loop
//
// Author:			Edwin Chen
// Created:			Mar 25, 2016
// Last updated:	Mar 25, 2016
//
//*******************************//

#ifndef _GAMEOBJECT_H
#define _GAMEOBJECT_H

#include <Vector.h>
using namespace MATH;

namespace GAME {
	class GameObject {
	public:
		Vec3 pos;
		Vec3 vel;
	};
}

#endif