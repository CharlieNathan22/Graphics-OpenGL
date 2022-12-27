#include "Skybox.h"

Skybox::Skybox(GLuint tTop, GLuint tBottom, GLuint tLeft, GLuint tRight, GLuint tFront, GLuint tBack) :
	_tTop(tTop), _tBottom(tBottom), _tLeft(tLeft), _tRight(tRight), _tFront(tFront), _tBack(tBack)
{

}

void Skybox::Display() //display the skybox
{
	glPushAttrib(GL_ALL_ATTRIB_BITS); // Push attrib bits so that only the skybox glows
	glPushMatrix();
	glTranslatef(-1000.f, -800.f, -1000.f); // Position the skybox at the center
	glScalef(2500.f, 2500.f, 2500.f); // Scale the box so its large enough for my scene

	// Draw each plane of the skybox and bind the textures to each face
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _tBack);
	glBegin(GL_QUADS);
	{
		glTexCoord2f(0.f, 0.f); glVertex3f(0.f, 0.f, 0.f);
		glTexCoord2f(1.f, 0.f); glVertex3f(1.f, 0.f, 0.f);
		glTexCoord2f(1.f, 1.f); glVertex3f(1.f, 1.f, 0.f);
		glTexCoord2f(0.f, 1.f); glVertex3f(0.f, 1.f, 0.f);
	}
	glEnd();
	// Top face
	glColor3f(1.f, 1.f, 1.f);
	glBindTexture(GL_TEXTURE_2D, _tTop);
	glBegin(GL_QUADS);
	{
		glTexCoord2f(0.f, 0.f); glVertex3f(0.f, 1.f, 0.f);
		glTexCoord2f(1.f, 0.f); glVertex3f(1.f, 1.f, 0.f);
		glTexCoord2f(1.f, 1.f); glVertex3f(1.f, 1.f, 1.f);
		glTexCoord2f(0.f, 1.f); glVertex3f(0.f, 1.f, 1.f);
	}
	glEnd();
	// Front face
	glBindTexture(GL_TEXTURE_2D, _tFront);
	glBegin(GL_QUADS);
	{
		glTexCoord2f(0.f, 0.f); glVertex3f(1.f, 0.f, 1.f);
		glTexCoord2f(1.f, 0.f); glVertex3f(0.f, 0.f, 1.f);
		glTexCoord2f(1.f, 1.f); glVertex3f(0.f, 1.f, 1.f);
		glTexCoord2f(0.f, 1.f); glVertex3f(1.f, 1.f, 1.f);
	}
	glEnd();
	// Left face
	glBindTexture(GL_TEXTURE_2D, _tLeft);
	glBegin(GL_QUADS);
	{
		glTexCoord2f(0.f, 0.f); glVertex3f(0.f, 0.f, 1.f);
		glTexCoord2f(1.f, 0.f); glVertex3f(0.f, 0.f, 0.f);
		glTexCoord2f(1.f, 1.f); glVertex3f(0.f, 1.f, 0.f);
		glTexCoord2f(0.f, 1.f); glVertex3f(0.f, 1.f, 1.f);
	}
	glEnd();
	// Right face
	glBindTexture(GL_TEXTURE_2D, _tRight);
	glBegin(GL_QUADS);
	{
		glTexCoord2f(0.f, 0.f); glVertex3f(1.f, 0.f, 0.f);
		glTexCoord2f(1.f, 0.f); glVertex3f(1.f, 0.f, 1.f);
		glTexCoord2f(1.f, 1.f); glVertex3f(1.f, 1.f, 1.f);
		glTexCoord2f(0.f, 1.f); glVertex3f(1.f, 1.f, 0.f);
	}
	glEnd();

	glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	glPopAttrib();

	// Floor of Skybox --Ground Texture 
	glPushMatrix();
	glTranslatef(0.f, 1500.f, 0.f);
	glScalef(4000.f, 1500.f, 4000.f);
	const float Amt = 100.0f; // Split up ground into multiple quads so lighting works
	float quad = 1.0f / Amt;

	glNormal3f(0.0f, 1.0f, 0.0f); //normal facing upwards, used for light
	glEnable(GL_TEXTURE_2D); // Apply texture
	glBindTexture(GL_TEXTURE_2D, _tBottom);
	// Use a for loop to put all the quads together that forms the skybox
	for (float x = -1.0f; x < 1.0f; x += quad)
	{
		for (float y = -1.0f; y < 1.0f; y += quad)
		{
			glBegin(GL_QUADS);
			{
				glTexCoord2f(0.f, 0.f); glVertex3f(x, -1.0f, y);
				glTexCoord2f(1.f, 0.f); glVertex3f(x, -1.0f, y + quad);
				glTexCoord2f(1.f, 1.f); glVertex3f(x + quad, -1.0f, y + quad);
				glTexCoord2f(0.f, 1.f); glVertex3f(x + quad, -1.0f, y);
			}
			glEnd();
		}
	}
	glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}
