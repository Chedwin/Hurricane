#include "Puck.h"

using namespace GAME;

Puck::Puck(Vec3& startPos) : puckBMP(nullptr) {
	OnCreate();
}
Puck::~Puck() {
	OnDestroy();
}



bool Puck::OnCreate() {
	SetWeaponType(WeaponType::PROJECTILE);

	if (!puckBMP->ImgLoad("res/puck.bmp")) {
		return false;
	}

	return true;
}
void Puck::OnDestroy() {
	puckBMP->Destroy();
	delete puckBMP;
	puckBMP = nullptr;
}
void Puck::FixedUpdate() {
	// Pucks will fire themselves with x amount of force

	/// In this update, the puck will destroy itself after x amount of seconds.
	//delete this;
}
void Puck::Render(const MATH::Matrix4& projection) {
	Vec3 screenCoords = projection * pos;
	puckBMP->Draw(int(screenCoords.x), int(screenCoords.y));
}