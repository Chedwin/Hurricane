//*******************************//
//
// Name:			Player.h
// Description:		Class definition for the player character.
//
// Author:			Shaked Brosh
// Created:			Apr 6, 2016
// Last updated:	Apr 6, 2016
//
//*******************************//

#ifndef _GUI_EVENTLISTENER_H
#define _GUI_EVENTLISTENER_H
#include <string>
#include <map>
#include <SDL.h>


class EventListener
{
public:
	static void Update();

	EventListener() = delete;
	EventListener(const EventListener&) = delete;
	EventListener(EventListener&&) = delete;
	EventListener& operator = (const EventListener) = delete;
	EventListener& operator = (EventListener&&) = delete;
	~EventListener();
};

#endif