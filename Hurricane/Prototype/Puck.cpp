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
	vel = Vec3(1.0f, 0.0f, 0.0f);

	return true;
}
void Puck::OnDestroy() {
	puckBMP->Destroy();
	delete puckBMP;
	puckBMP = nullptr;
}

void Puck::SetStartPos(const Vec3& s){
	pos = s;
}


void Puck::PlayerDir(const SDL_RendererFlip& sf) {
	Vec3 start(1.0f, 0.0f, 0.0f);

	switch (sf) {
	case CharacterState::FACE_RIGHT:
		vel.x = start.x;
	case CharacterState::FACE_LEFT:
		vel.x = -start.x;
	}
}

void Puck::FixedUpdate(const float _deltaTime) {
	lifeTime += _deltaTime;
	//pos.print();
	pos.x += vel.x;
}
void Puck::Render(const MATH::Matrix4& projection) {
	Vec3 screenCoords = projection * pos;
	puckBMP->Draw(int(screenCoords.x), int(screenCoords.y));
}