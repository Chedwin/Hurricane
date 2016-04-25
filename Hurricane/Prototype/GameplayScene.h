//*******************************//
//
// Name:			GameplayScene.h
// Description:		The gameplay scene
//					This is where our game happens
//
// Author:			Edwin Chen
// Created:			Apr 05, 2016
// Last updated:	Apr 05, 2016
//
//*******************************//

#pragma once

#include <Scene.h>
#include "RinkLevelMap.h"
#include "Player.h"
#include "WhiteBox.h"

namespace GAME { 

	class GameplayScene : public Scene {
	public:
		explicit GameplayScene(Window& windowRef, const std::string& name);
		virtual ~GameplayScene();


		/// Get rid of these
		GameplayScene(const GameplayScene&) = delete;
		GameplayScene(GameplayScene &&) = delete;
		GameplayScene& operator=(const GameplayScene &) = delete;
		GameplayScene& operator=(GameplayScene &&) = delete;

#define WINDOW_WIDTH 1260
#define WINDOW_HEIGHT 670

		virtual bool OnCreate();
		virtual void OnDestroy();
		virtual void Update(const float deltaTime);
		virtual void Render() const;

	private:
		RinkLevelMap* rinkMap;
		Player* playerCharacter;
		LIST(WhiteBox*) boxList;
	};

}