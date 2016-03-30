//*******************************//
//
// Name:			SDL_Adapter.h
// Description:		Wrapper class for SDL
//					This makes for cross-platform API implentation much easier
//
// Author:			Edwin Chen
// Created:			Mar 22, 2016
// Last updated:	Mar 22, 2016
//
//*******************************//

#ifndef _SDL_ADAPTER_H
#define _SDL_ADAPTER_H

#include <SDL.h>
#include <SDL_mixer.h>


	class SDL_Adapter {
	public:
		static Uint32 ReturnTicks() {
			return SDL_GetTicks();
		}


	};


#endif