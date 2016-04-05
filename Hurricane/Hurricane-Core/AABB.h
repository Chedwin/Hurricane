//*******************************//
//
// Name:			AABB.h
// Description:		Defines a class for an Axis Aligning Bounding Box
//
// Author:			Edwin Chen
// Created:			Apr 5, 2016
// Last updated:	Apr 5, 2016
//
//*******************************//

#ifndef _AABB_H
#define _AABB_H

#include "Vector.h"

using namespace MATH;

struct AABB
{
	Vec3 min;
	Vec3 max;

	bool AABBCollision(AABB a, AABB b);
};



#endif