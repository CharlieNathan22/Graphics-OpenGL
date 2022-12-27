#include "Turbine.h"

Turbine::Turbine(GLuint tBase) : _tBase(tBase) {
	size(_INIT_SIZE);
}

float velocity = 0;
const double PI = 3.141592654;

void Turbine::Display() {
	glPushMatrix();
	glPushAttrib(GL_ALL_ATTRIB_BITS);

	// move it to the side near skybox
	glScalef(250.0f, 250.0f, 250.0f);
	glTranslatef(-3.5f, 0.0f, 3.f);
	glRotatef(90.f, 0, 1, 0);
	DrawTurbine();
	// Add second Turbine
	glTranslatef(3.0f, 0.0f, 0.0f);
	DrawTurbine();
	// Add third Turbine
	glTranslatef(3.0f, 0.0f, 0.0f);
	DrawTurbine();
	glPopAttrib();
	glPopMatrix();
}

void Turbine::Update(const double &deltaTime) {
	// Spinning blades
	velocity += 70.0f * static_cast<float>(deltaTime);
}

void Turbine::DrawTurbine() {

	glPushMatrix();
	glColor3f(1.f, 1.f, 1.f);
	glBindTexture(GL_TEXTURE_2D, _tBase);
	// Draw Base and Pole
	glBegin(GL_POLYGON);
	glVertex2f(-0.1f, 0);
	glVertex2f(0.1f, 0);
	glVertex2f(0.1f, 3);
	glVertex2f(-0.1f, 3);
	glEnd();
	glTranslatef(0, 3, 0);
	// Draw base Circle for blades
	glBegin(GL_POLYGON);
	for (int d = 0; d < 32; d++) {
		double angle = 2 * PI / 32 * d;
		glVertex2d(0.1 * cos(angle), 0.1 * sin(angle));
	}
	glEnd();
	// Draw blades
	glRotated(velocity * (180.0 / 45), 0, 0, 1);
	glColor3f(0.7f, 0.4f, 0.2f);
	for (int i = 0; i < 3; i++) {
		glRotated(120, 0, 0, 1);
		glBegin(GL_POLYGON);
		glVertex2f(0, 0);
		glVertex2f(0.5f, 0.1f);
		glVertex2f(1.5f, 0);
		glVertex2f(0.5f, -0.1f);
		glEnd();
	}
	glPopMatrix();
}