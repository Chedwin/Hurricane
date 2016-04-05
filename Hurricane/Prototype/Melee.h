//*******************************//
//
// Name:			Melee.h
// Description:		Abstract base class for a melee type of game object.
//					This includes hockey sticks.
//
// Author:			Edwin Chen
// Created:			Apr 5, 2016
// Last updated:	Apr 5, 2016
//
//*******************************//

#ifndef _MELEE_H
#define _MELEE_H

#include "Weapon.h"
namespace GAME {

	class Melee : public Weapon {
	public:
		virtual bool OnCreate() = 0;
		virtual void OnDestroy() = 0;
		virtual void FixedUpdate() = 0;
		virtual void Render() = 0;

	public:
	};

}
#endif