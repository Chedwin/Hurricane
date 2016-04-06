#include "RinkLevelMap.h"
using namespace GAME;

RinkLevelMap::RinkLevelMap(){
	OnCreate();
}
RinkLevelMap::~RinkLevelMap() {
	OnDestroy();
}




bool RinkLevelMap::OnCreate() {
	//ode_world = dWorldCreate();
	return true;
}
void RinkLevelMap::OnDestroy() {
	//dWorldDestroy(ode_world);
}
void RinkLevelMap::FixedUpdate() {

}
void RinkLevelMap::Render(const Matrix4& projection) {

}