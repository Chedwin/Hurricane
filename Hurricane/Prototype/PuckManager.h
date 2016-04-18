//*******************************//
//
// Name:			PuckManager.h
// Description:		A container and manager for all the hockey being created in the scene.
//					The manager will destroy the pucks after 2 seconds being fired.
//
// Author:			Edwin Chen
// Created:			Apr 5, 2016
// Last updated:	Apr 17, 2016
//
//*******************************//

#ifndef _PUCKMANAGER
#define _PUCKMANAGER

#include <Macro.h>
#include <MMath.h>
#include "Puck.h"

namespace GAME {

	class PuckManager {
	public:
		PuckManager(Window& wRef) : wRef(wRef) {}
		~PuckManager();
		

		void UpdatePuckManager(const float _deltaTime);
		void RenderPucks(const MATH::Matrix4& _proj);
		void ForcePuck();
	public:
		LIST(Puck*) puckList;
		Window& wRef;
	};
}

#endif