//*******************************//
//
// Name:			Player.h
// Description:		Class definition for the player character.
//
// Author:			Shaked Brosh
// Created:			Apr 5, 2016
// Last updated:	Apr 6, 2016
//
//*******************************//

#ifndef  _GUITEXT_H
#define _GUITEXT_H

#include <SDL.h>
#include <SDL_ttf.h>
#include "Window.h"
#include "Debug.h"

class GUIText
{
public:
	GUIText(Window *_windowRef);
	~GUIText();
	bool Load(const char *_text, int _r, int _g, int _b, SDL_Rect *_box, int _size);
	void Update(float deltaTime);
	SDL_Surface *textSurface;
	TTF_Font *font;
	SDL_Color fontColour;
	const char *text;
	SDL_Rect *box;
	Window *windowRef;
	void Destroy();
	int offset;
	int offsetPrev;
};

#endif