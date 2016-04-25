#pragma once

#include <GameObject.h>

class WhiteBox : public GameObject
{
public:
	WhiteBox(class Window& w);
	virtual ~WhiteBox();

	bool OnCreate();
	void OnDestroy();
	void FixedUpdate(const float _deltaTime);
	void Render(const MATH::Matrix4& projection);
	bool CheckBoxCollision(GameObject* a);

private:
	Texture* boxTexture;
};

