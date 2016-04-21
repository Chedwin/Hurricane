#include <SDL.h>

#include "Player.h"
#include <Debug.h>
using namespace GAME;


Player::Player(class Window& w) 
	: playerTexture(nullptr), 
	playerStick(nullptr),
	Character(w)
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
	
	//playerStick = new HockeyStick(windowPtr);
	puckManager = new PuckManager(*windowPtr);
	controller = new Controller();

	return true;
}
void Player::OnDestroy() {

	/*delete playerStick;
	playerStick = nullptr;*/

	delete puckManager;
	puckManager = nullptr;

	delete playerTexture;
	playerTexture = nullptr;

	delete controller;
	controller = nullptr;

	// Now need to delete a window pointer that hasn't created anything.
	//windowPtr = nullptr;
}

void Player::FixedUpdate(const float _deltaTime) {
	puckManager->pmPos = pos;

	controller->ControllerUpdate(_deltaTime);
	
	if (controller->triggerSpace) {
		ShootPuck();
	}

	puckManager->UpdatePuckManager(_deltaTime);
	puckManager->Puck_Window_Collision();

	Player_Window_Collision();
	switch (controller->controllerReturn) {
	case UP:
		MoveUP();
		return;
	case DOWN:
		MoveDOWN();
		return;
	case LEFT:
		MoveLEFT();
		return;
	case RIGHT:
		MoveRIGHT();
		return;
	default:
		return;
	}

}

void Player::MoveUP() {
	pos.y += 0.2f;
}
void Player::MoveDOWN() {
	pos.y -= 0.2f;
}
void Player::MoveLEFT() {
	pos.x -= 0.2f;
	cState = FACE_LEFT;
	playerFaceDir = SDL_RendererFlip::SDL_FLIP_HORIZONTAL;
}
void Player::MoveRIGHT() {
	pos.x += 0.2f;
	cState = FACE_RIGHT;
	playerFaceDir = SDL_RendererFlip::SDL_FLIP_NONE;
}

void Player::ShootPuck() {
	puckManager->ForcePuck(playerFaceDir);
}

void Player::Player_Window_Collision() {
	if (pos.x <= 0.0f) {
		pos.x = 0.01f;
	}
	if (pos.x >= 23.5f) {
		pos.x = 23.5f;
	}

	if (pos.y <= 1.3f) {
		pos.y = 1.31f;
	}
	if (pos.y >= 9.9f) {
		pos.y = 9.9f;
	}
}

void Player::Render(const MATH::Matrix4& projection) {

	Vec3 screenCoords = projection * pos;

	switch (cState) {
	case CharacterState::FACE_RIGHT:
		playerTexture->Draw(int(screenCoords.x), int(screenCoords.y), 1.0f, nullptr, 0.0f, nullptr, playerFaceDir);
		return;
	case CharacterState::FACE_LEFT:
		playerTexture->Draw(int(screenCoords.x), int(screenCoords.y), 1.0f, nullptr, 0.0f, nullptr, playerFaceDir);
		return;
	default:
		playerTexture->Draw(int(screenCoords.x), int(screenCoords.y), 1.0f, nullptr, 0.0f, nullptr, playerFaceDir);
		return;
	}

	
}