//*******************************//
//
// Name:			StaticGameObject.h
// Description:		Abstract base class for all different types of "static" game objects in a game.
//					This type is synonmyous to "Actors" in Unreal Engine 4.
//
// Author:			Edwin Chen
// Created:			Apr 5, 2016
// Last updated:	Apr 5, 2016
//
//*******************************//
#pragma once

#include <GameObject.h>

namespace GAME {

	class StaticGameObject : public GameObject {
	public:
		virtual bool OnCreate() = 0;
		virtual void OnDestroy() = 0;
		virtual void FixedUpdate() = 0;
		virtual void Render() = 0;
	};
}