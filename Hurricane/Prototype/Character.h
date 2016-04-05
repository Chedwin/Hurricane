//*******************************//
//
// Name:			Character.h
// Description:		Abstract base class for all different types of characters in the game.
//					These can include players, enemies, NPCs, etc.
//
// Author:			Edwin Chen
// Created:			Apr 5, 2016
// Last updated:	Apr 5, 2016
//
//*******************************//

#pragma once

#include "GameObject.h"

namespace GAME {
	
	class Character : public GameObject {
	public:
		virtual bool OnCreate() = 0;
		virtual void OnDestroy() = 0;
		virtual void FixedUpdate() = 0;
		virtual void Render() = 0;
	};
}