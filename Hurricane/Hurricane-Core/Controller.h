//*******************************//
//
// Name:			Contoller.h
// Description:		Creates game controller
//
// Author:			Edwin Chen
// Created:			Mar 25, 2016
// Last updated:	Mar 25, 2016
//
//*******************************//

#ifndef _CONTROLLER_H
#define _CONTROLLER_H

#include <SDL.h>

class Controller {
public:
	Controller();
	~Controller();

	void InitController();
	void ShutdownContoller();
public:
	SDL_GameController* controller;
};

#endif