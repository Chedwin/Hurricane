#ifndef GAMESCENEMANAGER_H
#define GAMESCENEMANAGER_H

#include <memory>
#include <thread>
#include <list>
#include "Scene.h"
#include "Controller.h"

namespace GAME {

	class GameSceneManager {
	private:
		// Constructor and destructor are both private
		// We're creating a singleton to ensure that no other classes mess with our GSM
		GameSceneManager();
		~GameSceneManager();

		// Notice that windowInstance is a stack variable here
		// GameSceneManager constructor for the best way to initialize
		Window windowInstance;
		Scene* currentScene;
		Controller* gController;
		/// std::unique_ptr is a smart pointer that destroys the object it points to when the unique_ptr goes out of scope.
		/// instance is a unique pointer
		static std::unique_ptr<GameSceneManager> instance;

		/// Since the destructor is private, the template std::unique_ptr needs access so I made it a friend.
		/// However, std::default_delete is the default destruction policy used by std::unique_ptr. 
		/// When no deleter is specified, therefore I'll make std::default_delete my friend as well. 
		/// Friend functions can see each other's "private" parts haha.
		friend std::default_delete < GameSceneManager >;

	private:
		bool isRunning;
		unsigned int fps; // frames per seconds

		std::list<Scene*> sceneList;

		unsigned int sceneIndex;

	public:
		static GameSceneManager* getInstance();

		void Run();

		bool Initialize();
		void Update(const float deltaTime);
		void Render() const;
		void QuitWindowPrompt();
		void AdvanceSceneWindow();

		void SceneChanger(const unsigned int _levelIndex);
	};

}

#endif