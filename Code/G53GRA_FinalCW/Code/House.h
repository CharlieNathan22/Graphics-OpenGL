#pragma once

#include "DisplayableObject.h"
#include "Animation.h"
#include "../Framework/Interface/Input.h"

class House :
	public DisplayableObject,
	public Animation,
	public Input

{
public:

	House(GLuint tBase, GLuint tRoof, GLuint tDoor, GLuint tWood, GLuint tBlade);

	//void Update(const double &deltaTime);
	void Display();
	void Update(const double & deltaTime);
	void DrawHouse();
	void DrawCube();
	void DrawRoof();
	void DrawWindows();
	void DrawWindow();
	void DrawEntrance();

private:
	GLuint _tBase, _tRoof, _tDoor, _tWood, _tBlade;
	int uKey, yKey;
	float RotateTravelled = 0;
	float RotateSin = 0;



};
