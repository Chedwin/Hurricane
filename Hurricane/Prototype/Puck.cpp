#include <Debug.h>
#include "Player.h"
#include "Puck.h"

using namespace GAME;

Puck::Puck(class Window& w) : puckBMP(nullptr), Weapon(w) {
	OnCreate();
}
Puck::~Puck() {
	OnDestroy();
}

bool Puck::OnCreate() {
	SetWeaponType(WeaponType::PROJECTILE);
	puckBMP = new Texture(windowPtr->GetRenderer());
	if (!puckBMP->ImgLoad("res/puck.bmp")) {
		return false;
	}

	//Player* player = nullptr;
	////player->GetPlayerInstance();	
	//
	//Vec3 v = player->GetPlayerInstance()->GetPos();
	pos = Vec3(0.0f, 6.0f, 0.0f);
	return true;
}
void Puck::OnDestroy() {
	puckBMP->Destroy();
	delete puckBMP;
	puckBMP = nullptr;
}




void Puck::FixedUpdate(const float _deltaTime) {
	lifeTime += _deltaTime;
	pos.x += 1.0f;
}
void Puck::Render(const MATH::Matrix4& projection) {
	Vec3 screenCoords = projection * pos;
	puckBMP->Draw(int(screenCoords.x), int(screenCoords.y));
}