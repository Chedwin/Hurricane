#include "TitleScene.h"
#include <MMath.h>
#include <Debug.h>
#include <Window.h>
#include <Texture.h>

using namespace MATH;
using namespace GAME;


TitleScene::TitleScene(Window& windowRef) : Scene(windowRef), bckgrd(nullptr)
{
	OnCreate();
}

TitleScene::~TitleScene() {
	OnDestroy();
}


bool TitleScene::OnCreate() {
	bckgrd = new Texture(sceneWindowPtr->GetRenderer());
	if (!bckgrd->ImgLoad("res/hurricane.bmp")) {
		Debug::ConsoleError("Cannot load image!");
		Debug::Log(EMessageType::ERR, "TitleScene", "OnCreate", __TIMESTAMP__, __FILE__, __LINE__, "Cannot load image!");
	}

	return true;
}

void TitleScene::OnDestroy(){
	bckgrd->Destroy();
	delete bckgrd;
	bckgrd = nullptr;
}

void TitleScene::Update(const float deltaTime) {

}


void TitleScene::Render() const{
	sceneWindowPtr->ClearRenderer();

	/// External draw calls here
	bckgrd->Draw();

	SDL_RenderPresent(sceneWindowPtr->GetRenderer());
};