#pragma once 

//#include <ode/ode.h>
#include <World.h>

namespace GAME {
	class RinkLevelMap : public World {
	public:
		RinkLevelMap();
		~RinkLevelMap();

		bool OnCreate();
		void OnDestroy();
		void FixedUpdate();
		void Render(const Matrix4& projection);
	};
}