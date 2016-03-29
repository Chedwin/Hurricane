#include "Scene0.h"
#include <MMath.h>
#include <Debug.h>
#include <Window.h>
#include <Graphics.h>

using namespace MATH;
using namespace GAME;


Scene0::Scene0(Window& windowRef) : Scene(windowRef), bckgrd(nullptr)
{
	OnCreate();
}

Scene0::~Scene0() {
	OnDestroy();
}


bool Scene0::OnCreate() {
	bckgrd = new Graphics(sceneWindowPtr->GetRenderer());
	if (!bckgrd->ImgLoad("res/hurricane.bmp")) {
		Debug::ConsoleError("Cannot load image!");
		Debug::Log(EMessageType::ERR, "Scene0", "OnCreate", __TIMESTAMP__, __FILE__, __LINE__, "Cannot load image!");
	}

	return true;
}

void Scene0::OnDestroy(){
	bckgrd->Destroy();
	delete bckgrd;
	bckgrd = nullptr;
}

void Scene0::Update(const float deltaTime) {

}


void Scene0::Render() const{
	sceneWindowPtr->ClearRenderer();

	/// External draw calls here
	bckgrd->Draw();

	SDL_RenderPresent(sceneWindowPtr->GetRenderer());
};