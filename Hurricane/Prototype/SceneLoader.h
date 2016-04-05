//*******************************//
//
// Name:			SceneLoader.h
// Description:		Keeps a list of scenes or levels in the game.
//					Data structure are used to dynamically add in new scenes as they're developed.
//					This class directly associates with the GameSceneManager.
//
// Author:			Edwin Chen
// Created:			Apr 05, 2016
// Last updated:	Apr 05, 2016
//
//*******************************//

#pragma once 

#include <list>
#include "Scene.h"

class GameSceneManager;
namespace GAME {

	class SceneLoader {
	private:
		friend class GameSceneManager;
		static std::list<Scene*> sceneList;
	};

}