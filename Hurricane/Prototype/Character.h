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

#include <Macro.h>
#include <Matrix.h>
#include "GameObject.h"
#include "Weapon.h"


namespace GAME {
	
	enum CharacterState : unsigned int {
		IDLE=0,
		FACE_LEFT,
		FACE_RIGHT
	};

	class Character : public GameObject {
	public:
		explicit Character(class Window& w) : GameObject(w) {}
		virtual ~Character() {}

		virtual bool OnCreate() = 0;
		virtual void OnDestroy() = 0;
		virtual void FixedUpdate(const float _deltaTime) = 0;
		virtual void Render(const MATH::Matrix4& projection) = 0;

		inline bool isWeaponListEmpty() const {
			return weaponList.size() == 0;
		}

		inline void AddWeapon(Weapon* _w) {
			weaponList.push_front(_w);
		}
	protected:
		LIST(Weapon*) weaponList;
		LIST(Weapon*)::iterator weaponIT;

		CharacterState cState;
		SDL_RendererFlip playerFaceDir;
	};
}