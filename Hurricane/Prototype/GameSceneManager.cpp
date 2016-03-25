#include "GameSceneManager.h"
#include "Scene0.h"
#include <SDL.h>
#include <iostream>
#include <cassert>
#include <Debug.h>
#include <Timer.h>

using namespace CORE;
using namespace GAME;

/// See the header file regarding unique_ptr
std::unique_ptr<GameSceneManager> GameSceneManager::instance(nullptr);

GameSceneManager* GameSceneManager::getInstance() {
	if (instance.get() == nullptr){
		/// I originally set the unique_ptr to be null in the constructor - 
		/// reset() sets the new address
		instance.reset(new GameSceneManager());
	}
	return instance.get();
}



GameSceneManager::GameSceneManager() : windowInstance(), isRunning(false), fps(10), sceneIndex(0) {
	// pre-initialized variables here
	// just to show off our intelligence haha
}



GameSceneManager::~GameSceneManager(){
	windowInstance.Destroy();
	isRunning = false;

	delete gController;
	gController = nullptr;

	delete currentScene;
	currentScene = nullptr;
}


bool GameSceneManager::Initialize(){

	windowInstance.SetWindowSize(980, 600);
	if (!windowInstance.Initialize()) {
		Debug::Log(EMessageType::FATAL_ERR, "GameSceneManager", "Initialize", __TIMESTAMP__, __FILE__, __LINE__, "Failed to initialize GUI window!");
		return false;
	}
	gController = new GameController();

	currentScene = new Scene0(windowInstance);

	return true;
}

// This RUN() function acts as the game loop
void GameSceneManager::Run(){
	isRunning = Initialize();
	Timer timer;
	timer.Start();

	while (isRunning) {
		timer.UpdateFrameTicks();
		Update(timer.GetDeltaTime());
		Render();
		SDL_Delay(timer.GetSleepTime(fps));
	}
}


void GameSceneManager::Update(const float deltaTime) {
	SDL_Event SDLEvent;

	while (SDL_PollEvent(&SDLEvent)) {
		if (SDLEvent.type == SDL_KEYDOWN) {
			switch (SDLEvent.key.keysym.sym) {
			case SDLK_1:
				// uses scene pointer to check if the current scene has been beaten or not
				//if (currentScene->BeatScene()) {
					//AdvanceSceneWindow();
				//}
				return;
			case SDLK_ESCAPE:
				// exit by pressing the "esc" key
				QuitWindowPrompt();
			}
		}

		switch (SDLEvent.type) {
		case SDL_EventType::SDL_QUIT:
			QuitWindowPrompt();
			break;
		}
	}

	if (currentScene) {
		currentScene->Update(deltaTime);
	}

}

void GameSceneManager::QuitWindowPrompt() {
	// Implement a command prompt window for quitting
	const SDL_MessageBoxButtonData buttons[] = {
		{ 0, 0, "Cancel" }, // (flags, buttonid, text)
		{ SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT, 1, "Yes" }
	};

	const SDL_MessageBoxData messageboxdata = {
		SDL_MESSAGEBOX_INFORMATION, // flags
		NULL, // window
		"Quit Game", // window title
		"Are you sure you want to quit?", // message
		SDL_arraysize(buttons), // num of buttons
		buttons // buttons
	};

	int buttonid;
	if (SDL_ShowMessageBox(&messageboxdata, &buttonid) < 0) {
		SDL_Log("error displaying message box");
	}
	if (buttonid == 1) {
		isRunning = false;
		return;
	}
	else {
		//SDL_Log("Selection was %s", buttons[buttonid].text);
	}
}

void GameSceneManager::Render() const {

	if (currentScene == nullptr){
		Debug::Log(EMessageType::ERR, "GameSceneManager", "Render", __TIMESTAMP__, __FILE__, __LINE__, "No scene selected as current scene");
		// if assert is passed a null object, the program immediately stops
		// these asserts ONLY work in debug mode, NOT release mode
		assert(currentScene);
	}

	currentScene->Render();
}
