#include "GameplayScene.h"
#include <MMath.h>
#include <Debug.h>
#include <Window.h>
#include <Texture.h>
#include <Vector.h>
#include "Player.h"

using namespace GAME;


GameplayScene::GameplayScene(Window& windowRef, const std::string& name) 
	: Scene(windowRef, name), map(nullptr)
{
	//windowRef.SetWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	OnCreate();
}

GameplayScene::~GameplayScene() {
	OnDestroy();
}


bool GameplayScene::OnCreate() {
	/// Initialize the viewport ndc for the scene to draw to the window
	int _w = sceneWindowPtr->GetWidth();
	int _h = sceneWindowPtr->GetHeight();

	MATH::Matrix4 ndc = MMath::viewportNDC(_w, _h);
	projection = 
		MMath::orthographic(0.0f, 25.0f,
							0.0f, 10.0f,
							0.0f, 10.0f) * ndc;

	map = new Texture(sceneWindowPtr->GetRenderer());
	if (!map->ImgLoad("res/rink.bmp")) {
		Debug::ConsoleError("Cannot load image!");
		Debug::Log(EMessageType::ERR, "GameplayScene", "OnCreate", __TIMESTAMP__, __FILE__, __LINE__, "Cannot load image!");
	}

	playerCharacter = new Player(sceneWindowPtr);
	playerCharacter->SetPos(MATH::Vec3(12.0f, 6.0f, 0.0f));
	return true;
}

void GameplayScene::OnDestroy(){
	map->Destroy();
	delete map;
	map = nullptr;

	delete playerCharacter;
	playerCharacter = nullptr;
}

void GameplayScene::Update(const float deltaTime) {

}


void GameplayScene::Render() const{
	sceneWindowPtr->ClearRenderer();

	/// External draw calls here
	map->Draw();
	playerCharacter->Render(projection);

	SDL_RenderPresent(sceneWindowPtr->GetRenderer());
};