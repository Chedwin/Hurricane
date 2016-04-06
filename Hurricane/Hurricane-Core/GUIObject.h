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

#ifndef  GUIOBJECT_H
#define GUIOBJECT_H

#include <SDL.h>
#include <string>
#include <vector>
#include "Vector.h"
#include "Window.h"
#include "Texture.h"
#include "GUIText.h"

using namespace MATH;

enum ActionListener
{
	MAIN_MENU,
	NEXT_SCENE,
	GAME_LOBBY_MENU,
	REGISTER_USER,
	LOGIN_USER,
	LOGOUT_USER,
	JOIN_GAME,
	CREATE_GAME,
	ACCEPT_OPTION,
	REJECT_OPTION,
	INVITE_PLAYER
};


template<typename T>
class ActionEvent {
	T action;
public:
	ActionEvent() {}
	ActionEvent(T _action) {
		action = _action;
	}
	T& operator = (T _action) {
		action = _action;
		return action;
	}
	T& operator ()() {
		return action;
	}
};

class ActionHandler {
public:
	static bool nextScene();

	static bool mainMenu();
	static bool gameLobbyMenu();

	static bool registerUser();
	static bool loginUser();
	static bool logoutUser();

	static bool joinGame();
	static bool createGame();
	static bool acceptOption();
	static bool rejectOption();
	static bool invitePlayer();
	static bool staticFunc();


	ActionHandler() = delete;
	ActionHandler(const ActionHandler&) = delete;
	ActionHandler(ActionHandler&&) = delete;
	ActionHandler& operator = (const ActionHandler) = delete;
	ActionHandler& operator = (ActionHandler&&) = delete;
	~ActionHandler();

};

class MouseEventListener;
enum ActionType {
	STATIC,
	BUTTONPRESSED,
	IDLE,
	MOVELEFT,
	MOVERIGHT,
	MOVEUP,
	MOVEDOWN,
	SHOOT,
	TOTAL
};
struct animationList {
	ActionType actionType;
	int startFrame;
	int endFrame;
	int totalFrames;
	SDL_RendererFlip Flip;
};
class guiObject
{
public:
	guiObject(std::string _id, SDL_Color _bColour, SDL_Color _fColour, SDL_Rect _box, Window* _window);
	virtual ~guiObject();
	std::string ID;

	virtual void Draw(float DeltaTime);
	guiObject* isInside(int _mouseX, int _mouseY);

	//Setters
	void SetScale(Vec3 _scale);
	void SetText(std::string _text);
	bool SetImage(std::string _fileName);
	void SetRotation(double _angle);
	void bindAnimation(ActionType _action, int _startFrame, int _endFrame, int _totalFrames, SDL_RendererFlip _flip);
	void setAnimation(ActionType _currentAction);
	void setTextProperties(int _size, SDL_Color _color);
	void setPosition(int _x, int _y);
	void setRelativePosition(int _x, int _y);
	//Getters
	virtual int getHeight();
	virtual int getWidth();
	Vec3 getPosition();
	ActionType getAnimation();

	Vec3 relativePosition;


	virtual void notifyMousePressed(int _x, int _y);
	virtual void notifyMouseRelease(int _x, int _y);
	virtual void notifyMouseMove(int _x, int _y);
	int zIndex;
	virtual guiObject* findWindowContainingPoint(int _x, int _y);
	std::vector<animationList*> guiAnimations;
	std::string getText();
	bool changeAnimation();
protected:
	double rotationAngle;
	SDL_Rect field;
	SDL_Color backgroundColour;
	SDL_Color forgroundColour;
	Vec3 scale;
	Window *window;
	std::string textString;
	Texture* image;
	GUIText *text;

	animationList* currentAnim;
	bool isArmed, isFocus; //mouse is over object

	//text stuff
	int textSize;
	SDL_Color textColor;


};


#endif