//*******************************//
//
// Name:			Contoller.h
// Description:		Creates game controller
//
// Author:			Edwin Chen
// Created:			Mar 25, 2016
// Last updated:	Apr 17, 2016
//
//*******************************//

#ifndef _CONTROLLER_H
#define _CONTROLLER_H

#include <SDL.h>

enum CONTROLLER_RETURN {
	NEUTRAL=0,
	UP,
	DOWN,
	LEFT,
	RIGHT,
	SPACE
};

class Controller {
public:



	Controller();
	~Controller();

	void InitController();
	void ShutdownContoller();

	void ControllerUpdate(const float _deltaTime);
public:
	SDL_GameController* controller;
	CONTROLLER_RETURN controllerReturn;

	bool triggerSpace;
};

#endif