#include <Macro.h>
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
	STRING s = "res/bb_court.bmp";

	worldMap->ImgLoad(s);

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