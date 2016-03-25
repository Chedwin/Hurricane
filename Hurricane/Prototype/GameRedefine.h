//*******************************//
//
// Name:			GameRedefine.h
// Description:		Refines imported classes from Hurricane to avoid namespace conflicts and ambiguity
//					An extremely ugly way of "solving" the problem but for time-issues, this will do...........
//
// Author:			Edwin Chen
// Created:			Mar 25, 2016
// Last updated:	Mar 25, 2016
//
//*******************************//

#ifndef _GAME_REDEFINE_H
#define _GAME_REDEFINE_H

#include <Window.h>
#include <Graphics.h>

namespace GAME {
	class GameWindow   : public CORE::Window {};
	class GameGraphics : public CORE::Graphics {};
}

#endif