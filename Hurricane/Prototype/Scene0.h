//*******************************//
//
// Name:			Scene0.h
// Description:		The main scene
//					This is where our game happens
//
// Author:			Edwin Chen
// Created:			Mar 22, 2016
// Last updated:	Mar 22, 2016
//
//*******************************//

#ifndef _SCENE0_H
#define _SCENE0_H

#include "Scene.h"
#include <Window.h>
#include <Graphics.h>


namespace GAME {

	class Scene0 : public Scene {
	public:
		explicit Scene0(Window& windowRef);
		virtual ~Scene0();


		/// Get rid of these
		Scene0(const Scene0&) = delete;
		Scene0(Scene0 &&) = delete;
		Scene0& operator=(const Scene0 &) = delete;
		Scene0& operator=(Scene0 &&) = delete;


		virtual bool OnCreate();
		virtual void OnDestroy();
		virtual void Update(const float deltaTime);
		virtual void Render() const;

	private:
		Graphics* bckgrd;
	};
}

#endif