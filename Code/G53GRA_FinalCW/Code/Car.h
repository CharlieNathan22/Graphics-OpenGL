#pragma once

#include "DisplayableObject.h"
#include "Animation.h"
#include "Input.h"
#define _INIT_SIZE 50.0f

class Car :
	public DisplayableObject,
	public Animation,
	public Input
{
public:
	~Car() {};

	Car();

	// Override Display from DisplayableObject
	void Display();
	void DrawCylinder();
	void DrawCar();
	void Lighting();
	void RenderWheel(int x, int y, int z);
	void Update(const double& deltaTime);

protected:
	float _velocity;
private:
	GLuint _tBase;

};

