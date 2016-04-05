//*******************************//
//
// Name:			WhiteBox.h
// Description:		Class definition for a white box prop in the game.
//					The player is able to shoot pucks at them and knock them around.
//
// Author:			Edwin Chen
// Created:			Apr 5, 2016
// Last updated:	Apr 5, 2016
//
//*******************************//

#pragma once

#include "StaticGameObject.h"

namespace GAME {

	class WhiteBox : public StaticGameObject {
	public:
		bool OnCreate() final;
		void OnDestroy() final;
		void FixedUpdate() final;
		void Render() final;
	};

}