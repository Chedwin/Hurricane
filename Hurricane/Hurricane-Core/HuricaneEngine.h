//*******************************//
//
// Name:			HurricaneEngine.h
// Description:		Defines the actually game engine.
//					This is where the magic happens!
//					We want to make the engine a singleton b/c nobody else should be messing with it.
//
// Author:			Edwin Chen
// Created:			Feb 05, 2016
// Last updated:	Feb 05, 2016
//
//*******************************//

#ifndef _HURRICANEENGINE_H
#define _HURRICANEENGINE_H

#include "Window.h"
#include "memory.h"

namespace CORE {

	class HurricaneEngine {
	// Methods:
	private:
		HurricaneEngine();
		~HurricaneEngine();
	public:
		// Delete all the default copy and move constructors
		HurricaneEngine(const HurricaneEngine&) = delete;
		HurricaneEngine(HurricaneEngine&&) = delete;
		HurricaneEngine& operator=(const HurricaneEngine&) = delete;
		HurricaneEngine& operator=(HurricaneEngine&&) = delete;

		static HurricaneEngine* getInstance();
		void Run();
		bool Initialize();
		void Update(const float deltaTime);
		void Render() const;
		void HandleEvents();
	

	// Variables and members:
	private:
		/// NOTE: windowInstance is a stack variable here - see the 
		///		  HurricaneEngine constructor for the best way to initialize it 
		Window windowInstance;

		///std::unique_ptr is a smart pointer that destroys the object it point to when the unique_ptr goes out of scope.
		static std::unique_ptr<HurricaneEngine> hEngineInstance;

		/// NOTE: Since my destructor is private the template std::unique_ptr needs access so I made it a friend.
		///		  However, std::default_delete is the default destruction policy used by std::unique_ptr 
		///		  when no deleter is specified, therefore I'll make std::default_delete my friend as well. 
		friend std::default_delete<HurricaneEngine>;

		bool isRunning;
		unsigned int frameRate; // frames per second
	};

} // end namespace CORE

#endif