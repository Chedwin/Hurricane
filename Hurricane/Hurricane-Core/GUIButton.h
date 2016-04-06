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

#ifndef _GUIBUTTON_H
#define _GUIBUTTON_H

#include "GUIObject.h"
#include <map>


class guiButton : public guiObject
{
public:
	guiButton(std::string _id, SDL_Color _bColour, SDL_Color _fColour, SDL_Rect _box, Window* _window);
	virtual ~guiButton();

	void addAction(ActionListener _action);
	ActionEvent<bool(*)()> action;
	virtual void notifyMousePressed(int _x, int _y);
	virtual void notifyMouseRelease(int _x, int _y);
	virtual void notifyMouseMove(int _x, int _y);
	bool actionEvent();
	bool changeAnim;

};

#endif