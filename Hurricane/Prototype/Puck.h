//*******************************//
//
// Name:			Puck.h
// Description:		A concrete class that is a type of projectile.
//					Power up pucks could inherit from this later 
//					but I don't feel like doing that now...
//
// Author:			Edwin Chen
// Created:			Apr 5, 2016
// Last updated:	Apr 5, 2016
//
//*******************************//

#ifndef _PUCK_H
#define _PUCK_H

#include <GameObject.h>
#include "Projectile.h"

namespace GAME {

	class Puck : public Projectile {
	public:
		bool OnCreate() final;
		void OnDestroy() final;
		void FixedUpdate() final;
		void Render() final;

	public:
		Puck();
		Puck(Vec3 startPos);
		~Puck();
	};
}

#endif