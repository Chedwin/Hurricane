#include "RinkLevelMap.h"
using namespace GAME;

RinkLevelMap::RinkLevelMap(Window* w) : World(w)
{
	OnCreate();
}
RinkLevelMap::~RinkLevelMap() {
	OnDestroy();
}




bool RinkLevelMap::OnCreate() {
	//ode_world = dWorldCreate();
	worldMap = new Texture(windowPtr->GetRenderer());
	worldMap->ImgLoad("res/rink.bmp");

	if (!worldMap) {
		return false;
	}

	return true;
}
void RinkLevelMap::OnDestroy() {
	delete worldMap;
	worldMap = nullptr;
	//dWorldDestroy(ode_world);
}
void RinkLevelMap::Render(const Matrix4& projection) {
	worldMap->Draw();
}