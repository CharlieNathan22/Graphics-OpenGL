#pragma once

#include "DisplayableObject.h"
#include "Animation.h"
#include "Input.h"
#define _INIT_SIZE 50.0f

class Tunnel :
	public DisplayableObject,
	public Animation,
	public Input
{
public:
	Tunnel();
	~Tunnel() {};

	Tunnel(GLuint tBase, GLuint tRoad);

	void Display();
	void Update(const double& deltaTime);

	void DrawTunnel();

	void DrawRoad();


protected:
	float _velocity;

private:
	GLuint _tBase, _tRoad;
};

