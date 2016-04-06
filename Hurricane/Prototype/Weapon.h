//*******************************//
//
// Name:			Weapon.h
// Description:		Abstract class of a weapon.
//					An enum is used to add a component to the class to determine the type of weapon.
//
// Author:			Edwin Chen
// Created:			Apr 5, 2016
// Last updated:	Apr 5, 2016
//
//*******************************//


#ifndef _WEAPON_H
#define _WEAPON_H

#include <GameObject.h>

namespace GAME {

	class Weapon : public GameObject {
	public:
		enum WeaponType {
			PROJECTILE = 0,
			MELEE
		};

		virtual ~Weapon() {}

		virtual bool OnCreate() = 0;
		virtual void OnDestroy() = 0;
		virtual void FixedUpdate() = 0;
		virtual void Render(const MATH::Matrix4& projection) = 0;

		WeaponType GetWeaponType() const {
			return weaponType;
		}


	protected:
		void SetWeaponType(WeaponType _w) {
			weaponType = _w;
		}

		WeaponType weaponType;
	};

}

#endif