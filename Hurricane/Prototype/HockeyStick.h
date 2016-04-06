//*******************************//
//
// Name:			HockeyStick.h
// Description:		Concrete hockey stick class.
//					The player HAS-A hockey stick.
//					A hockey stick is needed to shoot a puck.
//					THe player can never really "lose" the stick but this class is responsible for shooting pucks.
//
// Author:			Edwin Chen
// Created:			Apr 5, 2016
// Last updated:	Apr 5, 2016
//
//*******************************//

#ifndef _HOCKEYSTICK_H
#define _HOCKEYSTICK_H

#include <Macro.h>
#include "Weapon.h"
#include "Puck.h"

namespace GAME {

	class HockeyStick : public Weapon {
	public:
		HockeyStick();
		~HockeyStick();

		bool OnCreate();
		void OnDestroy();
		void FixedUpdate();
		void Render(const MATH::Matrix4& projection);
	public:
		void Slash();
		void ShootPuck();

		//LIST(Puck) pucks;
	};

}
#endif