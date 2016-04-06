#include <SDL.h>

#include "Player.h"
using namespace GAME;

Player::Player(Window* w) 
	: playerTexture(nullptr), 
	playerStick(nullptr),
	windowPtr(w)
{
	OnCreate();
}
Player::~Player() {
	OnDestroy();
}





bool Player::OnCreate() {
	playerTexture = new Texture(windowPtr->GetRenderer());
	playerTexture->ImgLoad("res/hockey_player2.bmp");
	if (!playerTexture) {
		return false;
	}

	playerStick = new HockeyStick();
	return true;
}
void Player::OnDestroy() {
	delete playerStick;
	playerStick = nullptr;

	delete playerTexture;
	playerTexture = nullptr;

	// Now need to delete a window pointer that hasn't created anything.
	windowPtr = nullptr;
}
void Player::FixedUpdate() {

}
void Player::Render(const MATH::Matrix4& projection) {
	Vec3 screenCoords = projection * pos;
	playerTexture->Draw(int(screenCoords.x), int(screenCoords.y));
}