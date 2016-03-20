//*******************************//
//
// Name:			Window.h
// Description:		Creates and handles the window.
//					We'll use SDL for now.
//					OpenGL and DirectX will be implemented later....
//
// Author:			Edwin Chen
// Created:			Feb 04, 2016
// Last updated:	Mar 16, 2016
//
//*******************************//

#ifndef _WINDOW_H
#define _WINDOW_H

////// Since SDL is a 3rd party SDK, it should NOT be macro-defined in our project
#include <SDL.h>
///////

namespace CORE {

	class Window {
	public:
		Window();
		~Window();

		/// C11 precautions delete these non-needed default constructors and operators
		Window(const Window&) = delete;
		Window(Window&&) = delete;
		Window& operator = (const Window&) = delete;
		Window& operator = (Window&&) = delete;

		bool OnCreate();
		void OnDestroy();

		void SetWindowSize(const int Width_, const int Height_);

		int GetWidth() const;
		int GetHeight() const;
	protected:
		void GetInstalledOpenGLInfo();
	private:
		bool isInitialized;
		bool isFullScreen;


	// Our 3rd party graphics API calls
	// From here, we can easily change which API can be implemented
	// We'll start with SDL for now.....
	public:
		inline SDL_Window* getSDLWindow() const {
			return windowPtr;
		}
		void ToggleFullScreen();
	private:
		SDL_Window* windowPtr;
		SDL_GLContext glContext;
		SDL_Rect winRect;
	}; // end Window class

} // end namespace CORE

#endif