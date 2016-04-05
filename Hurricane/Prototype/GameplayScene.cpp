#include "GameplayScene.h"

#include "GameplayScene.h"
#include <MMath.h>
#include <Debug.h>
#include <Window.h>
#include <Texture.h>

using namespace MATH;
using namespace GAME;


GameplayScene::GameplayScene(Window& windowRef) : Scene(windowRef), map(nullptr)
{
	//windowRef.SetWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	OnCreate();
}

GameplayScene::~GameplayScene() {
	OnDestroy();
}


bool GameplayScene::OnCreate() {
	

	map = new Texture(sceneWindowPtr->GetRenderer());
	if (!map->ImgLoad("res/rink.bmp")) {
		Debug::ConsoleError("Cannot load image!");
		Debug::Log(EMessageType::ERR, "GameplayScene", "OnCreate", __TIMESTAMP__, __FILE__, __LINE__, "Cannot load image!");
	}

	return true;
}

void GameplayScene::OnDestroy(){
	map->Destroy();
	delete map;
	map = nullptr;
}

void GameplayScene::Update(const float deltaTime) {

}


void GameplayScene::Render() const{
	sceneWindowPtr->ClearRenderer();

	/// External draw calls here
	map->Draw();

	SDL_RenderPresent(sceneWindowPtr->GetRenderer());
};