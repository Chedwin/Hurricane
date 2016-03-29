//*******************************//
//
// Name:			Window.h
// Description:		Creates and handles the window.
//					SDL is used to create an initial window
//					An OpenGL context will then draw to said SDL window
//
// Author:			Edwin Chen
// Created:			Feb 04, 2016
// Last updated:	Mar 22, 2016
//
//*******************************//

#ifndef _WINDOW_H
#define _WINDOW_H

////// Since SDL is a 3rd party SDK, it should NOT be macro-defined in our project
#include <SDL.h>
///////



	class Window {
	public:
			Window();
			~Window();

			/// C11 precautions delete these non-needed default constructors and operators
			Window(const Window&) = delete;
			Window(Window&&) = delete;
			Window& operator = (const Window&) = delete;
			Window& operator = (Window&&) = delete;

			bool Initialize();
			void Destroy();

			void SetWindowSize(const int Width_, const int Height_);
			void ClearRenderer() const;

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
			return SDLWindow;
		}
		void ToggleFullScreen();
		SDL_Renderer* GetRenderer() const;
	private:
		SDL_GLContext glContext;

		SDL_Window* SDLWindow;
		SDL_Renderer* SDLRenderer;
		SDL_Surface* SDLSurface;

		SDL_Rect winRect;
	}; // end Window class


#endif