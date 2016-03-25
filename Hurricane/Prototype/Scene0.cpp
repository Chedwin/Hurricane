#include "Scene0.h"
#include <Debug.h>
#include <Window.h>

using namespace CORE;
using namespace GAME;

Scene0::Scene0(GameWindow& windowRef) : Scene(windowRef)
{
	OnCreate();
}

Scene0::~Scene0() {
	OnDestroy();
}


bool Scene0::OnCreate() {
	Debug::ConsoleLog("Scene0 was created!");
	return true;
}

void Scene0::OnDestroy(){

}

void Scene0::Update(const float deltaTime) {

}


void Scene0::Render() const{
	sceneWindowPtr->ClearRenderer();

	SDL_RenderPresent(sceneWindowPtr->GetRenderer());
};