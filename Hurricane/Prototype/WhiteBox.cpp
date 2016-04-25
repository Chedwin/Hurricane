#include <Debug.h>
#include "WhiteBox.h"


WhiteBox::WhiteBox(class Window& w) : 
	GameObject(w),
	boxTexture(nullptr)
{
	OnCreate();
}


WhiteBox::~WhiteBox()
{
	OnDestroy();
}

bool WhiteBox::OnCreate() {
	boxTexture = new Texture(windowPtr->GetRenderer());
	boxTexture->ImgLoad("res/whiteBox.bmp");
	if (!boxTexture) {
		return false;
	}

	return true;
}
void WhiteBox::OnDestroy() {
	boxTexture->Destroy();
	delete boxTexture;
	boxTexture = nullptr;
}
void WhiteBox::FixedUpdate(const float _deltaTime) {
}
void WhiteBox::Render(const MATH::Matrix4& projection) {
	Vec3 screenCoords = projection * pos;
	boxTexture->Draw(int(screenCoords.x), int(screenCoords.y));
}

bool WhiteBox::CheckBoxCollision(GameObject* a) {
	//Sides of the rects
	float leftA, leftB,
		rightA, rightB,
		topA, topB,
		bottomA, bottomB;

	//Calculate the sides of rect a
	leftA = pos.x;
	rightA = pos.x + 0.9f;
	topA = pos.y;
	bottomA = pos.y + 0.9f;


	//calculate the sides of rect b
	leftB = a->pos.x;
	rightB = a->pos.x + 0.1f;
	topB = a->pos.y;
	bottomB = a->pos.y + 0.1f;


	if (rightA < leftB || leftA > rightB) {
		return false;
	}
	if (topA < bottomB || bottomA > topB) {
		return false;
	}

	Debug::ConsoleLog("YES collision!");
	return true;
}

//// Exit with no intersection if found separated along an axis
//if (a.max.x < b.min.x or a.min.x > b.max.x) return false
//if (a.max.y < b.min.y or a.min.y > b.max.y) return false
