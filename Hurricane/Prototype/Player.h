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

#include "Character.h"

namespace GAME {

	class Player : public Character {
	public:
		bool OnCreate() final;
		void OnDestroy() final;
		void FixedUpdate() final;
		void Render() final;

	public:
		void Move();
	};

}