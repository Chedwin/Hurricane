#include "Controller.h"
#include "Debug.h"



Controller::Controller()  {
	controller = nullptr;
	InitController();
}
Controller::~Controller() {
	ShutdownContoller();
}

void Controller::InitController() {
	for (int i = 0; i < SDL_NumJoysticks(); i++) {
		if (SDL_IsGameController(i)) {
			controller = SDL_GameControllerOpen(i);
			std::cout << SDL_GameControllerMapping(controller) << std::endl;
			break;
		}
	}
	Debug::ConsoleLog("Controller has been initialized!");
} // end InitController()

void Controller::ShutdownContoller() {
	if (controller) {
		SDL_GameControllerClose(controller);
		controller = nullptr;
	}
}