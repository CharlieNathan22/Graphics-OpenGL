#pragma once

#include "DisplayableObject.h"
#include "Animation.h"
#include "Input.h"
#define _INIT_SIZE 50.0f

class Turbine :
	public DisplayableObject,
	public Animation,
	public Input
{
public:
	Turbine();
	~Turbine() {};

	Turbine(GLuint tBase);

	void Display();
	void Update(const double& deltaTime);
	void DrawTurbine();

protected:
	float _velocity;

private:
	GLuint _tBase, _tRoof;
};

