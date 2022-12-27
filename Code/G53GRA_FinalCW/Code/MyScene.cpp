#include "MyScene.h"

#include "Car.h"
#include "Skybox.h"
#include "House.h"
#include "Tunnel.h"
#include "Turbine.h"

MyScene::MyScene(int argc, char** argv, const char *title, const int& windowWidth, const int& windowHeight)
	: Scene(argc, argv, title, windowWidth, windowHeight)
{
	
}

void MyScene::Projection()
{
	// Setting up projection
	GLdouble aspect = static_cast<GLdouble>(windowWidth) / static_cast<GLdouble>(windowHeight);
	gluPerspective(70.0, aspect, 2.0, 40000);
}

void MyScene::Initialise()
{
	// Setting the scene lighting
	glEnable(GL_LIGHT1);
	glClearColor(0.f, 0.f, 0.f, 1.0f);
	GLfloat ambient[3] = { 0.2f,0.2f,0.2f };
	GLfloat diffuse[3] = { 0, 0, 0 };
	GLfloat specular[3] = { 0, 0,0 };
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);

	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);

	// Adding Car to scene
	Car *car = new Car();
	AddObjectToScene(car);

	GLuint ft = Scene::GetTexture("Textures/Skybox_ft.bmp"); 
	GLuint bk = Scene::GetTexture("Textures/Skybox_bk.bmp"); 
	GLuint lf = Scene::GetTexture("Textures/Skybox_lf.bmp");
	GLuint rt = Scene::GetTexture("Textures/Skybox_rt.bmp");
	GLuint up = Scene::GetTexture("Textures/Skybox_up.bmp");
	GLuint dn = Scene::GetTexture("Textures/Skybox_dn.bmp");

	// Skybox around the scene
	Skybox *skybox = new Skybox(up, dn, lf, rt, ft, bk);
	AddObjectToScene(skybox);

	// Setting the scene textures
	GLuint brick = Scene::GetTexture("Textures/Brick.bmp");
	GLuint roof = Scene::GetTexture("Textures/Roof.bmp");
	GLuint window = Scene::GetTexture("Textures/Window.bmp");
	GLuint brick2 = Scene::GetTexture("Textures/Brick2.bmp");
	GLuint road = Scene::GetTexture("Textures/Road.bmp");
	GLuint metal = Scene::GetTexture("Textures/Metal.bmp");
	GLuint wood = Scene::GetTexture("Textures/Wood.bmp");

	GLuint door = Scene::GetTexture("Textures/Door.bmp");
	
	//  Adding Tunnels and Road
	Tunnel *tunnel = new Tunnel(brick2, road);
	AddObjectToScene(tunnel);
	glColor3f(1, 1, 1);
	

	// Adding 3 Turbines behind the road
	Turbine *turbine = new Turbine(metal);
	AddObjectToScene(turbine);	 

	// Adding 4 Houses on the side of the road
	House* house = new House(wood, roof, door, wood, window);
	AddObjectToScene(house);
}
