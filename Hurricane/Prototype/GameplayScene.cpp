#include <stdlib.h>
#include "GameplayScene.h"
#include <MMath.h>
#include <Debug.h>
#include <Window.h>
#include <Texture.h>
#include <Vector.h>
#include <GameObject.h>
#include "Player.h"


using namespace GAME;


GameplayScene::GameplayScene(Window& windowRef, const std::string& name) 
	: Scene(windowRef, name), rinkMap(nullptr)
{
	//windowRef.SetWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	OnCreate();

	playerCharacter = new Player(windowRef);
	playerCharacter->SetPos(MATH::Vec3(12.0f, 6.0f, 0.0f));
	playerCharacter->puckManager->pmPos = playerCharacter->pos;
	//playerCharacter->puckManager->pmPos.print();

	for (int i = 0; i < 5; i++) {
		boxList.push_back(new WhiteBox(windowRef));
	}

	for (WhiteBox* w : boxList) {
		int rndm = rand() % 25;
		int rndm2 = rand() % 10;
		w->SetPos(MATH::Vec3((float)rndm, (float)rndm2, 0.0));
	}
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

	rinkMap = new RinkLevelMap(sceneWindowPtr);
	if (!rinkMap) {
		Debug::ConsoleError("Cannot load game level!");
		Debug::Log(EMessageType::ERR, "GameplayScene", "OnCreate", __TIMESTAMP__, __FILE__, __LINE__, "Cannot load game level!");
	}

	


	return true;
}

void GameplayScene::OnDestroy(){
	delete rinkMap;
	rinkMap = nullptr;

	delete playerCharacter;
	playerCharacter = nullptr;

	while (!boxList.empty()) {
		delete boxList.front();
		boxList.pop_front();
	}
	boxList.clear();
}

void GameplayScene::Update(const float deltaTime) {

	playerCharacter->FixedUpdate(deltaTime);

	for (WhiteBox* w : boxList) {
		for (Puck* p : playerCharacter->puckManager->puckList) {
			w->CheckBoxCollision(p);
		}
	}
}


void GameplayScene::Render() const{
	sceneWindowPtr->ClearRenderer();

	/// External draw calls here
	rinkMap->Render(projection);


	playerCharacter->Render(projection);
	playerCharacter->puckManager->RenderPucks(projection); // I know. It's weird that puckManager is public.....

	for (WhiteBox* w : boxList) {
		w->Render(projection);
	}


	SDL_RenderPresent(sceneWindowPtr->GetRenderer());
};