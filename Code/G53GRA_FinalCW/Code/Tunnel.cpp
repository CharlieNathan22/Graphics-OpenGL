#include "Tunnel.h"

Tunnel::Tunnel(GLuint tBase, GLuint tRoad) : _tBase(tBase), _tRoad(tRoad) {
	size(_INIT_SIZE);
}

void Tunnel::Display() {
	glPushMatrix();
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glScalef(100.0f, 100.0f, 100.0f);
	glTranslatef(-8.0f, 0.0f, -8.0f);
	// Draw first tunnel
	DrawTunnel();
	glPushMatrix();
	// Draw road
	DrawRoad();
	glPopMatrix();
	// Draw second tunnel
	glTranslatef(4.0f, 0.0f, 20.0f);
	glRotatef(180, 0.0f, 1.0f, 0.0f);
	DrawTunnel();
	glPopAttrib();
	glPopMatrix();
}

void Tunnel::Update(const double& deltaTime) {

}

void Tunnel::DrawTunnel() {
	glColor3f(1.f, 1.f, 1.f);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _tBase);
	glBegin(GL_POLYGON);

	// Draw the sides
	glTexCoord2f(0.f, 0.f); glVertex3f(0.0f, 0.0f, 0.0f); 
	glTexCoord2f(0.f, 2.f); glVertex3f(0.0f, 2.0f, 0.0f);
	glTexCoord2f(1.f, 3.f); glVertex3f(1.0f, 3.0f, 0.0f); 
	glTexCoord2f(3.f, 3.f); glVertex3f(3.0f, 3.0f, 0.0f); 
	glTexCoord2f(4.f, 2.f); glVertex3f(4.0f, 2.0f, 0.0f); 
	glTexCoord2f(4.f, 0.f); glVertex3f(4.0f, 0.0f, 0.0f); 
	glEnd();
	glTranslatef(0.0f, 0.0f, 0.01f);

	// create a tunnel shape
	glBegin(GL_POLYGON);
	glTexCoord2f(0.f, 0.f); glVertex3f(0.0f, 0.0f, 0.0f);
	glTexCoord2f(0.f, 1.f); glVertex3f(0.0f, 2.0f, 0.0f);
	glTexCoord2f(1.f, 1.f); glVertex3f(0.0f, 2.0f, -3.0f);
	glTexCoord2f(1.f, 0.f); glVertex3f(0.0f, 0.0f, -3.0f);
	glEnd();
	glBegin(GL_POLYGON);
	glTexCoord2f(0.f, 0.f); glVertex3f(0.0f, 2.0f, 0.0f);
	glTexCoord2f(0.f, 1.f); glVertex3f(1.0f, 3.0f, 0.0f);
	glTexCoord2f(1.f, 1.f); glVertex3f(1.0f, 3.0f, -3.0f);
	glTexCoord2f(1.f, 0.f); glVertex3f(0.0f, 2.0f, -3.0f);
	glEnd();
	glBegin(GL_POLYGON);
	glTexCoord2f(0.f, 0.f); glVertex3f(1.0f, 3.0f, 0.0f);
	glTexCoord2f(0.f, 1.f); glVertex3f(3.0f, 3.0f, 0.0f);
	glTexCoord2f(1.f, 1.f); glVertex3f(3.0f, 3.0f, -3.0f);
	glTexCoord2f(1.f, 0.f); glVertex3f(1.0f, 3.0f, -3.0f);
	glEnd();
	glBegin(GL_POLYGON);
	glTexCoord2f(0.f, 0.f); glVertex3f(3.0f, 3.0f, 0.0f);
	glTexCoord2f(0.f, 1.f); glVertex3f(4.0f, 2.0f, 0.0f);
	glTexCoord2f(1.f, 1.f); glVertex3f(4.0f, 2.0f, -3.0f);
	glTexCoord2f(1.f, 0.f); glVertex3f(3.0f, 3.0f, -3.0f);
	glEnd();
	glBegin(GL_POLYGON);
	glTexCoord2f(0.f, 0.f); glVertex3f(4.0f, 2.0f, 0.0f);
	glTexCoord2f(0.f, 1.f); glVertex3f(4.0f, 0.0f, 0.0f);
	glTexCoord2f(1.f, 1.f); glVertex3f(4.0f, 0.0f, -3.0f);
	glTexCoord2f(1.f, 0.f); glVertex3f(4.0f, 2.0f, -3.0f);
	glEnd();
	glColor3f(0.f, 0.f, 0.f);
	glBegin(GL_POLYGON);
	glVertex3f(3.0f, 0.0f, 0.0f); 
	glVertex3f(3.0f, 2.0f, 0.0f); 
	glVertex3f(1.0f, 2.0f, 0.0f); 
	glVertex3f(1.0f, 0.0f, 0.0f); 
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);

}

void Tunnel::DrawRoad() {
	// draw road with road texture and stretch it to the tunnels
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(1.0f, 0.01f, 0.0f);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _tRoad);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.f, 0.f); glVertex3f(0.0f, 0.0f, 0.0f);
	glTexCoord2f(0.f, 1.f); glVertex3f(2.0f, 0.0f, 0.0f);
	glTexCoord2f(1.f, 1.f); glVertex3f(2.0f, 0.0f, 20.0f);
	glTexCoord2f(1.f, 0.f); glVertex3f(0.0f, 0.0f, 20.0f);
	glEnd();
	



}