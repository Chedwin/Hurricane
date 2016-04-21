#pragma once
#include "Collider.h"

class Rigidbody :
	public Component
{
private:
	void Init();
public:
	Rigidbody(GameObject*);
	Rigidbody(GameObject* _parent, Collider* _collider);
	~Rigidbody();

	float mass;
	Vec3 centreOfMass;
	bool isKinematic;
	Matrix3 inertiaTensor;

	//Note--Move this, should be at the collider level and not the rigidbody level.
	float CollisionRadius;

	Vec3 velocity;
	Vec3 accel;
	Collider* col;

	//Functions
	void AddForce(Vec3);
};