#include "Car.h"
#include <math.h>
#include <iostream>

// Initialise the Robot and its properties
Car::Car() {
	size(_INIT_SIZE);
}
// Lights set up
GLfloat lit1_spc[] = { 0.20, 0.20,  0.15, 1.00 },
lit1_dfs[] = { 0.70, 0.70,  0.65, 1.00 },
lit1_amb[] = { 0.25, 0.25,  0.20, 1.00 },
lit1_pos[] = { 0.20, 2.50,  5.20, 1.00 };

GLfloat lit2_spc[] = { 0.00,  0.00,  0.00, 1.00 },
lit2_dfs[] = { 0.30,  0.30,  0.35, 1.00 },
lit2_amb[] = { 0.20,  0.20,  0.25, 1.00 },
lit2_pos[] = { 1.50, -2.00, -4.00, 0.01 };

float r = 0.4;
float g = 0.4;
float b = 0.4;
int colorState = 1;

void Car::Display()
{
	Lighting();
	// Rotate object to new position
	glPushMatrix();
	glTranslatef(pos[0], pos[1], pos[2]);
	glRotatef(rotation[0], 1.0f, 0.0f, 0.0f);
	glRotatef(rotation[1], 0.0f, 1.0f, 0.0f);
	glRotatef(rotation[2], 0.0f, 0.0f, 1.0f);

	// set object initialisation
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glScalef(3.0f, 3.0f, 3.0f);
	glTranslatef(-200.0f, 20.0f, -200.0f);
	glRotatef(90, 0.0f, 1.0f, 0.0f);
	glDisable(GL_LIGHTING);
	glDisable(GL_CULL_FACE);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _tBase);
	glBegin(GL_QUADS);
	DrawCar(); 
}

void Car::DrawCar() {
	// draw a car
	glColor3f(r - 0.1, g - 0.1, b - 0.1);
	// Left
	glVertex3s(-40, 0, 15); glVertex3s(40, 0, 15); glVertex3s(40, -15, 15); glVertex3s(-40, -15, 15);
	// Right
	glVertex3s(-40, 0, -15); glVertex3s(40, 0, -15); glVertex3s(40, -15, -15); glVertex3s(-40, -15, -15);
	glColor3f(r + 0.1, g + 0.1, b + 0.1);
	// Back
	glVertex3s(40, 0, -15); glVertex3s(40, 0, 15); glVertex3s(40, -15, 15); glVertex3s(40, -15, -15);
	// Front
	glVertex3s(-40, 0, -15); glVertex3s(-40, 0, 15); glVertex3s(-40, -15, 15); glVertex3s(-40, -15, -15);
	glColor3f(r + 0.1, g + 0.1, b + 0.1);
	// Trunks
	glVertex3s(-40, 0, 15); glVertex3s(-40, 0, -15); glVertex3s(40, 0, -15); glVertex3s(40, 0, 15);
	// Roof
	glVertex3s(-10, 10, 15); glVertex3s(-10, 10, -15); glVertex3s(20, 10, -15); glVertex3s(20, 10, 15);
	glColor3f(0.7, 0.7, 0.5);
	// Windows
	glVertex3s(-25, 0, 15); glVertex3s(-10, 10, 15); glVertex3s(20, 10, 15); glVertex3s(25, 0, 15);
	glVertex3s(-25, 0, -15); glVertex3s(-10, 10, -15); glVertex3s(20, 10, -15); glVertex3s(25, 0, -15);
	glColor3f(0.7, 0.6, 0.5);
	// Windshield
	glVertex3s(-10, 10, 15); glVertex3s(-25, 0, 15); glVertex3s(-25, 0, -15); glVertex3s(-10, 10, -15);
	glVertex3s(20, 10, 15); glVertex3s(20, 10, -15); glVertex3s(25, 0, -15); glVertex3s(25, 0, 15);
	glColor3f(0.4, 0.5, 0.5);
	// Bottom
	glVertex3s(-40, -15, 15); glVertex3s(-40, -15, -15); glVertex3s(40, -15, -15); glVertex3s(40, -15, 15);
	glEnd();
	glEnable(GL_LIGHTING);

	// Draw wheels
	glColor3f(0.5, 0.5, 0.5);
	RenderWheel(-20, -13, 15);
	RenderWheel(20, -13, 15);
	RenderWheel(-20, -13, -15);
	RenderWheel(20, -13, -15);
	glPopAttrib();
	glPopMatrix();
}

void Car::Lighting(void) {
	//Add diffuse and ambient lighting to car model
	glLightfv(GL_LIGHT1, GL_SPECULAR, lit1_spc);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, lit1_dfs);
	glLightfv(GL_LIGHT1, GL_AMBIENT, lit1_amb);
	glLightfv(GL_LIGHT1, GL_POSITION, lit1_pos);
	glLightfv(GL_LIGHT2, GL_SPECULAR, lit2_spc);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, lit2_dfs);
	glLightfv(GL_LIGHT2, GL_AMBIENT, lit2_amb);
	glLightfv(GL_LIGHT2, GL_POSITION, lit2_pos);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);
	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_BLEND);
}

void Car::RenderWheel(int x, int y, int z) {
	glPushMatrix();
	glTranslatef(x, y, z);
	// Create a wheel shape in the form of a GlutTorus
	glutSolidTorus(2, 5, 12, 40);
	glPopMatrix();
}


void Car::Update(const double& deltaTime)
{
	// Make the car move down the road
	float velocity = 700.0f * static_cast<float>(deltaTime);
	pos[2] += velocity;
	// if a car is in the tunnel, redraw at first tunnel
	if (pos[2] > 1900) {
		pos[2] = -250;
		// generate random colours for the car
		r = ((double)rand() / (RAND_MAX));
		g = ((double)rand() / (RAND_MAX));
		b = ((double)rand() / (RAND_MAX));

	}
}