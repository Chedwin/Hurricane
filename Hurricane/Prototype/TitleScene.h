//*******************************//
//
// Name:			TitleScene.h
// Description:		The title scene
//
// Author:			Edwin Chen
// Created:			Mar 22, 2016
// Last updated:	Apr 05, 2016
//
//*******************************//

#ifndef _TitleScene_H
#define _TitleScene_H

#include <Scene.h>
#include <Window.h>
#include <Texture.h>


namespace GAME {

	class TitleScene : public Scene {
	public:
		explicit TitleScene(Window& windowRef, const std::string& name);
		virtual ~TitleScene();


		/// Get rid of these
		TitleScene(const TitleScene&) = delete;
		TitleScene(TitleScene &&) = delete;
		TitleScene& operator=(const TitleScene &) = delete;
		TitleScene& operator=(TitleScene &&) = delete;


		virtual bool OnCreate();
		virtual void OnDestroy();
		virtual void Update(const float deltaTime);
		virtual void Render() const;

	private:
		Texture* bckgrd;
	};
}

#endif