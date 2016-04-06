#pragma once 

//#include <ode/ode.h>
#include <Window.h>
#include <World.h>

namespace GAME {
	class RinkLevelMap : public World {
	public:
		RinkLevelMap(Window* w);
		~RinkLevelMap();

		bool OnCreate();
		void OnDestroy();
		void FixedUpdate() {
			/// doesn't really need updating for now...
		}
		void Render(const Matrix4& projection);
	};
}