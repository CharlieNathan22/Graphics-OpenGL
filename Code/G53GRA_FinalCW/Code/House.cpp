#include "House.h"


House::House(GLuint tBase, GLuint tRoof, GLuint tDoor, GLuint tWood, GLuint tBlade) : _tBase(tBase), _tRoof(tRoof), _tDoor(tDoor), _tWood(tWood), _tBlade(tBlade), uKey(0), yKey(0) {
	


}

void House::Display() {
	// Draw four houses on the side of the road
	glTranslatef(200.0f, 0.0f, -500.0f);
	DrawHouse();
	glTranslatef(0.0f, 0.0f, 500.0f);
	DrawHouse();
	glTranslatef(0.0f, 0.0f, 500.0f);
	DrawHouse();
	glTranslatef(0.0f, 0.0f, 500.0f);
	DrawHouse();
}

void House::Update(const double &deltaTime) {
}

void House::DrawHouse() {
	glPushMatrix();
	glScalef(150.5f, 200.5f, 300.5f);
	glColor3f(0.3, 0.3, 0.3);
	// Add windows
	glEnable(GL_TEXTURE_2D);
	DrawWindows();
	// Add base of house
	glBindTexture(GL_TEXTURE_2D, _tBase);
	glDisable(GL_CULL_FACE);
	DrawCube();
	glPushMatrix();
	// Add roof of house
	glBindTexture(GL_TEXTURE_2D, _tRoof);
	glScalef(1, 0.5f, 1);
	glTranslatef(0, 1.f, 0.);
	DrawRoof();
	glPopMatrix();
	glPushMatrix();
	glColor3f(1, 1, 1);
	glPopMatrix();
	glPushMatrix();
	// Add door and stairs
	DrawEntrance();
	glPopMatrix();
	glPopMatrix();
}

void House::DrawCube() {
	glBegin(GL_QUADS);
	{
		//front body
		glNormal3f(0.f, 0.f, 1.f);
		glTexCoord2f(0.f, 0.f); glVertex3f(0.f, 0.f, 0.f);
		glTexCoord2f(1.f, 0.f); glVertex3f(3.f, 0.f, 0.f);
		glTexCoord2f(1.f, 1.f); glVertex3f(3.f, 1.f, 0.f);
		glTexCoord2f(0.f, 1.f); glVertex3f(0.f, 1.f, 0.f);
		//back body
		glNormal3f(0.f, 0.f, -1.f);
		glTexCoord2f(0.f, 0.f); glVertex3f(3.f, 0.f, -1.f);
		glTexCoord2f(1.f, 0.f); glVertex3f(0.f, 0.f, -1.f);
		glTexCoord2f(1.f, 1.f); glVertex3f(0.f, 1.f, -1.f);
		glTexCoord2f(0.f, 1.f); glVertex3f(3.f, 1.f, -1.f);
		//right body
		glNormal3f(1.f, 0.f, 0.f);
		glTexCoord2f(0.f, 0.f); glVertex3f(3.f, 0.f, 0.f);
		glTexCoord2f(1.f, 0.f); glVertex3f(3.f, 0.f, -1.f);
		glTexCoord2f(1.f, 1.f); glVertex3f(3.f, 1.f, -1.f);
		glTexCoord2f(0.f, 1.f); glVertex3f(3.f, 1.f, 0.f);
		//left body
		glNormal3f(-1.f, 0.f, 0.f);
		glTexCoord2f(0.f, 0.f); glVertex3f(0.f, 0.f, -1.f);
		glTexCoord2f(1.f, 0.f); glVertex3f(0.f, 0.f, 0.f);
		glTexCoord2f(1.f, 1.f); glVertex3f(0.f, 1.f, 0.f);
		glTexCoord2f(0.f, 1.f); glVertex3f(0.f, 1.f, -1.f);
		// bottom
		glNormal3f(0.f, -1.f, 0.f);
		glTexCoord2f(0.f, 0.f); glVertex3f(0.f, 0.01f, 0.f);
		glTexCoord2f(1.f, 0.f); glVertex3f(0.f, 0.01f, -1.f);
		glTexCoord2f(1.f, 1.f); glVertex3f(3.f, 0.01f, -1.f);
		glTexCoord2f(0.f, 1.f); glVertex3f(3.f, 0.01f, 0.f);
	}
	glEnd();
}


void House::DrawRoof() {
	glBegin(GL_QUADS);
	{
		//top face
		glTexCoord2f(0.f, 0.f); glVertex3f(3.1f, 1.f, 0.1f);
		glTexCoord2f(3.f, 0.f); glVertex3f(1.5f, 2.5f, 0.1f);
		glTexCoord2f(3.f, 3.f); glVertex3f(1.5f, 2.5f, -1.1f);
		glTexCoord2f(0.f, 3.f); glVertex3f(3.1f, 1.f, -1.1f);
		//left side
		glTexCoord2f(0.f, 0.f); glVertex3f(-0.1f, 1.f, 0.1f);
		glTexCoord2f(3.f, 0.f); glVertex3f(1.5f, 2.5f, 0.1f);
		glTexCoord2f(3.f, 3.f); glVertex3f(1.5f, 2.5f, -1.1f);
		glTexCoord2f(0.f, 3.f); glVertex3f(-0.1f, 1.f, -1.1f);
		// right side
		glTexCoord2f(0.f, 0.f); glVertex3f(-0.1f, 1.f, 0.1f);
		glTexCoord2f(3.f, 0.f); glVertex3f(-0.1f, 1.f, 0.1f);
		glTexCoord2f(3.f, 3.f); glVertex3f(1.5f, 2.5f, 0.1f);
		glTexCoord2f(0.f, 3.f); glVertex3f(3.1f, 1.f, 0.1f);
		//bottom side
		glTexCoord2f(0.f, 0.f); glVertex3f(-0.1f, 1.f, -1.1f);
		glTexCoord2f(3.f, 0.f); glVertex3f(-0.1f, 1.f, -1.1f);
		glTexCoord2f(3.f, 3.f); glVertex3f(1.5f, 2.5f, -1.1f);
		glTexCoord2f(0.f, 3.f); glVertex3f(3.1f, 1.f, -1.1f);
		//middle side
		glTexCoord2f(0.f, 0.f); glVertex3f(-0.1f, 1.f, -1.1f);
		glTexCoord2f(3.f, 0.f); glVertex3f(-0.1f, 1.f, 0.1f);
		glTexCoord2f(3.f, 3.f); glVertex3f(3.1f, 1.f, 0.1f);
		glTexCoord2f(0.f, 3.f); glVertex3f(3.1f, 1.f, -1.1f);
	}
	glEnd();
}

void House::DrawWindows() {
	// Create 3 rectangles and apply window texture
	glPushMatrix();
	glClearColor(0.5f, 0.5f, 0.5f, 0.0f);
	glTranslatef(0.5f, 0.25f, 0.01f);
	glScalef(0.25f, 0.25f, 0);
	glBindTexture(GL_TEXTURE_2D, _tBlade);
	DrawWindow();
	glTranslatef(3.5f, 0.0f, 0.0f);
	DrawWindow();
	glTranslatef(3.5f, 0.0f, 0.0f);
	DrawWindow();
	glPopMatrix();
}

void House::DrawWindow() {
	// Draw a rectangle
	glBegin(GL_POLYGON); {
		glTexCoord2f(0.f, 0.f);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glTexCoord2f(0.f, 2.f); glVertex3f(0.f, 2.f, 0.0f);
		glTexCoord2f(2.f, 2.f); glVertex3f(2.f, 2.f, 0.0f);
		glTexCoord2f(2.f, 2.f); glVertex3f(2.f, 0.f, 0.0f);
	}
	glEnd();
}

void House::DrawEntrance() {
	int y;
	y = 4.f;

	// Draw a door
	glScalef(0.07f, 0.07f, 0.3f);
	glTranslatef(0.0f, 0.01f, -0.7f);
	glBindTexture(GL_TEXTURE_2D, _tDoor);
	glBegin(GL_POLYGON); {
		glTexCoord2f(0.f, 0.f); glVertex3f(-0.01f, 4.0f, -0.5f);
		glTexCoord2f(0.f, 1.f); glVertex3f(-0.01f, 13.0f, -0.5f);
		glTexCoord2f(1.f, 1.f); glVertex3f(-0.01f, 13.0f, -1.5f);
		glTexCoord2f(1.f, 0.f); glVertex3f(-0.01f, 4.0f, -1.5f);
	}
	glEnd();

	glBindTexture(GL_TEXTURE_2D, _tWood);
	//  Loop for making stairs
	for (int i = 5; i > 0; i--) {
		glBegin(GL_POLYGON); {
			glTexCoord2f(0.f, 0.f); glVertex3f(-1.0f, 0.0f, 0.0f);
			glTexCoord2f(1.f, 0.f); glVertex3f(-1.0f, y, 0.0f);
			glTexCoord2f(1.f, 1.f); glVertex3f(0.0f, y, 0.0f);
			glTexCoord2f(0.f, 1.f); glVertex3f(0.0f, 0.0f, 0.0f);
		}
		glEnd();
		glBegin(GL_POLYGON); {
			glTexCoord2f(0.f, 0.f); glVertex3f(-1.0f, 0.0f, 0.0f);
			glTexCoord2f(1.f, 0.f); glVertex3f(-1.0f, y, 0.0f);
			glTexCoord2f(1.f, 1.f); glVertex3f(-1.0f, y, -2.0f);
			glTexCoord2f(0.f, 1.f); glVertex3f(-1.0f, 0.0f, -2.0f);
		}
		glEnd();
		glBegin(GL_POLYGON); {
			glTexCoord2f(0.f, 0.f); glVertex3f(-1.0f, y, 0.0f);
			glTexCoord2f(1.f, 0.f); glVertex3f(-1.0f, y, -2.0f);
			glTexCoord2f(1.f, 1.f); glVertex3f(0.0f, y, -2.0f);
			glTexCoord2f(0.f, 1.f); glVertex3f(0.0f, y, 0.0f);
		}
		glEnd();

		glBegin(GL_POLYGON); {
			glTexCoord2f(0.f, 0.f); glVertex3f(-1.0f, 0.0f, -2.0f);
			glTexCoord2f(1.f, 0.f); glVertex3f(-1.0f, y, -2.0f);
			glTexCoord2f(1.f, 1.f); glVertex3f(0.0f, y, -2.0f);
			glTexCoord2f(0.f, 1.f); glVertex3f(0.0f, 0.0f, -2.0f);
		}
		glEnd();
		glTranslatef(-1.f, 0.0f, 0.0f);
		y -= 0.20f;
	}
}