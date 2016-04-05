#ifndef _WEAPON_H
#define _WEAPON_H

#include <GameObject.h>

namespace GAME {

	class Weapon : public GameObject {
	public:
		virtual bool OnCreate() = 0;
		virtual void OnDestroy() = 0;
		virtual void FixedUpdate() = 0;
		virtual void Render() = 0;
	};

}

#endif