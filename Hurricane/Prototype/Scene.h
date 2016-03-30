//*******************************//
//
// Name:			Scene.h
// Description:		Establishes an abstract "Scene" class for all types of Scene to use
//					This includes our game loop
//
// Author:			Edwin Chen
// Created:			Mar 22, 2016
// Last updated:	Mar 22, 2016
//
//*******************************//

#ifndef SCENE_H
#define SCENE_H

#include <MMath.h>
#include <Window.h>
#include <Timer.h>
#include <Debug.h>


namespace GAME {

	class Scene {
	public:
		// explicit means that the complier will not try to typecast the argument for the constructor
		// these two subroutines are "concrete" or real
		explicit Scene(Window& WindowRef) : sceneWindowPtr(&WindowRef) {}

		// Having this virtual destructor means that any Scene* ptr will point its appropriate destructor
		// and not this abstract one
		virtual ~Scene() {}

		Scene(const Scene&) = delete;
		Scene(Scene&&) = delete;
		Scene& operator=(const Scene&&) = delete;
		Scene& operator=(Scene&&) = delete;

		// Scene is considered an "absrtact" class
		// You cannot create an object of type Scene
		virtual bool OnCreate() = 0;
		virtual void OnDestroy() = 0;
		virtual void Update(const float DeltaTime) = 0;
		virtual void Render() const = 0;
	protected:
		Window* sceneWindowPtr;

		MATH::Matrix4 projection;
	};

}
#endif