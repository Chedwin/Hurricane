#pragma once

#include "Macro.h"
#include "Vector.h"
#include "GameObject.h"

using namespace MATH;

class SquareCollider;

class Collider {
protected:
public:
	std::vector<Collider> nestedColliders;
	Vec3 colliderCentre;

	static bool isColliding(Collider* c1, Collider* c2);

	//for N types of colliders need N^2 functions. This should clean up code and make future implementation better

	static bool isColliding(SquareCollider* sc1, SquareCollider* sc2);

	virtual void OnColliding(Collider* other){}

	Collider(GameObject* g);
	~Collider(){}
};

class SquareCollider : public Collider {
public:
	SquareCollider(GameObject* g) : Collider(g) {}

	float w, h;
};