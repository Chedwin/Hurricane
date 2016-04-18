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
// Last updated:	Apr 17, 2016
//
//*******************************//

#ifndef _HOCKEYSTICK_H
#define _HOCKEYSTICK_H

#include <Macro.h>
#include "Weapon.h"

namespace GAME {

	class HockeyStick : public Weapon {
	public:
		explicit HockeyStick(class Window& w);
		~HockeyStick();

		bool OnCreate();
		void OnDestroy();
		void FixedUpdate(const float _deltaTime);
		void Render(const MATH::Matrix4& projection);

		//LIST(Puck) pucks;
	};

}
#endif