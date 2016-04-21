#include "GameObject.h"

bool GameObject::addComponent(Component* c) {
	componentLIST.push_back(c);
	return true;
}

void GameObject::removeComponent(Component* c) {
	//for (auto it = componentLIST.begin(); it != componentLIST.end(); it++)
	//{
	//	if (*it._Ptr == c)
	//	{
	//		componentLIST.erase(it);

	//		switch (c->type)
	//		{
	//		case Component::ComponentType::RIGIDBODY:
	//			delete (RIGIDBODY*)c;
	//			break;
	//		default:
	//			delete _c;
	//			break;
	//		}

	//		break;
	//	}
	//}
}

void GameObject::addTag(STRING _tag)
{
	tags.push_back(_tag);
}