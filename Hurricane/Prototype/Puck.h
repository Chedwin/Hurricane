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

#include "Weapon.h"
#include <Texture.h>

namespace GAME {

	class Puck : public Weapon {
	public:
		~Puck();
	protected:
		Puck() {}
		Puck(Vec3& startPos);

		bool OnCreate();
		void OnDestroy();
		void FixedUpdate();
		void Render(const MATH::Matrix4& projection);

	protected:
		Texture* puckBMP;
	private:
		friend class HockeyStick;
	};
}

#endif