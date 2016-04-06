//*******************************//
//
// Name:			Player.h
// Description:		Class definition for the player character.
//
// Author:			Edwin Chen
// Created:			Apr 5, 2016
// Last updated:	Apr 5, 2016
//
//*******************************//

#pragma once 
#include <SDL.h>
#include <Window.h>
#include <Texture.h>
#include <Controller.h>
#include "Character.h"
#include "HockeyStick.h"

namespace GAME {

	class Player : public Character {
	public:
		Player(Window* w);
		Player() {}
		~Player();

		bool OnCreate();
		void OnDestroy();
		void FixedUpdate();
		void Render(const MATH::Matrix4& projection);

	public:
		void Move();

	protected:
		Texture* playerTexture;
		HockeyStick* playerStick; // player HAS-A hockey stick
		Window* windowPtr;
	};

}