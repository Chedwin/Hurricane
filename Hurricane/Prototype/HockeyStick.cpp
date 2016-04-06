#include "HockeyStick.h"
#include "Debug.h"

using namespace GAME;

HockeyStick::HockeyStick() {
	OnCreate();
}
HockeyStick::~HockeyStick() {

}



///////// Standard functions ///////////////
bool HockeyStick::OnCreate() {
	SetWeaponType(WeaponType::MELEE);
	Debug::ConsoleLog("Hockey stick made!");
	return true;
}
void HockeyStick::OnDestroy() {

}
void HockeyStick::FixedUpdate() {
	//// For the current prototype, the player texture already has-a hockey stick
}
void HockeyStick::Render(const MATH::Matrix4& projection) {
	//// For the current prototype, the hockey stick does not need to be drawn.
}



///////// Character functions //////////////
void HockeyStick::ShootPuck() {
	Debug::ConsoleLog("Puck shot!");

	/// Pucks WILL destroy "themselves".
	/// Class HockeyStick doesn't need to keep track of pucks after being shot.
	//Puck* p = new Puck();
}
void HockeyStick::Slash() {
	Debug::ConsoleLog("Slash!!");
}