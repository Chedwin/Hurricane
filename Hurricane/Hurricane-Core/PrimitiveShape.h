//*******************************//
//
// Name:			PrimitiveShape.h
// Description:		Abstract base class for all different types of shapes in a game.
//					Can be overridden by any type of shape.
//
// Author:			Edwin Chen
// Created:			Apr 5, 2016
// Last updated:	Apr 17, 2016
//
//*******************************//

#pragma once

#include "GameObject.h"

class PrimitiveShape : public GameObject {
public:
	virtual ~PrimitiveShape() {}

	virtual bool OnCreate() = 0;
	virtual void OnDestroy() = 0;
	virtual void FixedUpdate(const float _deltaTime) = 0;
	virtual void Render(const Matrix4& projection) = 0;
};

class Box : public PrimitiveShape {
public:
	Box();
	~Box();
public:
	bool OnCreate(); 
	void OnDestroy();
	void FixedUpdate();
	void Render(const Matrix4& projection);

protected:
	int _width;
	int _height;
};

class Sphere : public PrimitiveShape {
public:
	Sphere();
	~Sphere();
public:
	bool OnCreate();
	void OnDestroy();
	void FixedUpdate();
	void Render(const Matrix4& projection);

protected:
	float radius;
};