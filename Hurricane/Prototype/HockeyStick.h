//*******************************//
//
// Name:			HockeyStick.h
// Description:		Concrete hockey stick class
//
// Author:			Edwin Chen
// Created:			Apr 5, 2016
// Last updated:	Apr 5, 2016
//
//*******************************//

#ifndef _HOCKEYSTICK_H
#define _HOCKEYSTICK_H

#include <Macro.h>
#include "Melee.h"
#include "Puck.h"

namespace GAME {

	class HockeyStick : public Melee {
	public:
		bool OnCreate() final;
		void OnDestroy() final;
		void FixedUpdate() final;
		void Render() final;
	public:
		void Slash();
		void Shoot();

		LIST(Puck) pucks;
	};

}
#endif