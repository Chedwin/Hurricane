//*******************************//
//
// Name:			Puck.h
// Description:		A concrete class that is a type of projectile.
//					Power up pucks could inherit from this later 
//					but I don't feel like doing that now...
//
// Author:			Edwin Chen
// Created:			Apr 5, 2016
// Last updated:	Apr 17, 2016
//
//*******************************//

#ifndef _PUCK_H
#define _PUCK_H

#include <Texture.h>
#include "Weapon.h"

namespace GAME {

	class Puck : public Weapon {
	public:
		~Puck();
	protected:
		explicit Puck(class Window& w);

		bool OnCreate();
		void OnDestroy();
		void FixedUpdate(const float _deltaTime);
		void Render(const MATH::Matrix4& projection);
	protected:
		Texture* puckBMP;
		const float lifeSpan = 2.0f;
		float lifeTime = 0.0f;
	private:
		friend class PuckManager;
	};
}

#endif