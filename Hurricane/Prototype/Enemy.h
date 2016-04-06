//*******************************//
//
// Name:			Enemy.h
// Description:		Class definition for the enemy character(s).
//
// Author:			Edwin Chen
// Created:			Apr 5, 2016
// Last updated:	Apr 5, 2016
//
//*******************************//

#pragma once

#include <Macro.h>
#include "Character.h"
#include "Player.h"

namespace GAME {

	class Enemy : public Character {
	public:
		bool OnCreate();
		void OnDestroy();
		void FixedUpdate();
		void Render(const MATH::Matrix4& projection);

	public:
		void FindPlayer(Player& p);
		void AttackPlayer();
	};

}