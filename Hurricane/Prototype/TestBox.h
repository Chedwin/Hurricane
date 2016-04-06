//*******************************//
//
// Name:			TestBox.h
// Description:		Class definition for a white box prop in the game.
//					The player is able to shoot pucks at them and knock them around.
//
// Author:			Edwin Chen
// Created:			Apr 5, 2016
// Last updated:	Apr 5, 2016
//
//*******************************//

#pragma once

#include <PrimitiveShape.h>

namespace GAME {

	class TestBox{
	public:
		bool OnCreate();
		void OnDestroy();
		void FixedUpdate();
		void Render(const MATH::Matrix4& projection);
	public:
		Box textBox;
	};

}