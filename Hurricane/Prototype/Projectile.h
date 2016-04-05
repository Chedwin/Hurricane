//*******************************//
//
// Name:			Projectile.h
// Description:		Abstract base class for a projectile game object.
//
// Author:			Edwin Chen
// Created:			Apr 5, 2016
// Last updated:	Apr 5, 2016
//
//*******************************//

#ifndef _PROJECTILE_H
#define _PROJECTILE_H

#include "Weapon.h"

namespace GAME {

	class Projectile : public Weapon {
	public:
		virtual bool OnCreate() = 0;
		virtual void OnDestroy() = 0;
		virtual void FixedUpdate() = 0;
		virtual void Render() = 0;

	public:

	};

}

#endif