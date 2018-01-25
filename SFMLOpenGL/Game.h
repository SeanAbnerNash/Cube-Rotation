#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "Matrix3.h"

using namespace std;
using namespace sf;
//@Author Sean Nash De Andrade
//@Login C00217019
//Cube Rotation Assignment
struct CubeSide//Struct for each side, the vertexes and if the side is visible
{
	MyVector3 m_vertexCords[4];
	bool m_visible;
};

class Game
{
public:
	Game();
	~Game();
	void run();
	CubeSide m_side[6];//6 Cube Sides
	void visibilityCheck();
	bool m_changed;//If the Matrix has been changed
	Matrix3 m_Matrix;//Transformation Matrix

private:
	Window window;
	bool isRunning = false;
	void initialize();
	void update();
	void draw();
	void unload();
	GLuint index;
	Clock clock;
	Time elapsed;




	float rotationAngle = 0.0f;
};