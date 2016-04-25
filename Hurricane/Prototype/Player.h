//*******************************//
//
// Name:			Player.h
// Description:		Class definition for the player character.
//
// Author:			Edwin Chen
// Created:			Apr 5, 2016
// Last updated:	Apr 17, 2016
//
//*******************************//

#pragma once 
#include <SDL.h>
#include <Window.h>
#include <Debug.h>
#include <Texture.h>
#include <Controller.h>
#include "Character.h"
#include "HockeyStick.h"
#include "PuckManager.h"

namespace GAME {

	class Player : public Character {
	public:
		explicit Player(class Window& w);
		~Player();

		bool OnCreate();
		void OnDestroy();
		void FixedUpdate(const float _deltaTime);
		void Render(const MATH::Matrix4& projection);
		void Player_Window_Collision();

		bool CheckPlayerCollision(GameObject* a, GameObject* b);

		Player* GetPlayerInstance() {
			return this;
		}

		PuckManager* puckManager;
	private:
		void MoveUP();
		void MoveDOWN();
		void MoveLEFT();
		void MoveRIGHT();
		void ShootPuck();

		Texture* playerTexture;
		Weapon* playerStick; // player HAS-A hockey stick
		Controller* controller;
	};

}