#ifndef _COMPONENT_H
#define _COMPONENT_H

class GameObject;

class Component {
public:
	enum ComponentType {
		RENDERABLE,
		COLLISION,
		RIGIDBODY
	};

	Component(GameObject& g);
	~Component();

	GameObject* rootObject;

	void SetEnabled(bool b) { 
		isEnabled = b;
	}
	bool GetEnabled() const {
		return isEnabled;
	}

private:
	bool isEnabled;
};

#endif