#include "Game.h"

bool updatable = false;


Game::Game() : window(VideoMode(800, 600), "OpenGL Cube")
{
	index = glGenLists(1);
	m_changed = false;
	//Front - 0
	//Initalize all the structs with each Vertex Co ordinates
	m_side[0].m_vertexCords[0] = { 1.0f, 1.0f, -5.0f };
	m_side[0].m_vertexCords[1] = { 1.0f, 1.0f, -5.0f };
	m_side[0].m_vertexCords[2] = { 1.0f, 1.0f, -5.0f };
	m_side[0].m_vertexCords[3] = { 1.0f, 1.0f, -5.0f };


	//Back - 1
	m_side[1].m_vertexCords[0] = { 1.0f, 1.0f, -15.0f };
	m_side[1].m_vertexCords[1] = { -1.0f, 1.0f, -15.0f };
	m_side[1].m_vertexCords[2] = { -1.0f, -1.0f, -15.0f };
	m_side[1].m_vertexCords[3] = { 1.0f, -1.0f, -15.0f };

	//Top - 2
	m_side[2].m_vertexCords[0] = { 1.0f, 1.0f, -15.0f };
	m_side[2].m_vertexCords[1] = { -1.0f, 1.0f, -15.0f };
	m_side[2].m_vertexCords[2] = { -1.0f, 1.0f, -5.0f };
	m_side[2].m_vertexCords[3] = { 1.0f, 1.0f, -5.0f };

	//Front Left - 3
	m_side[3].m_vertexCords[0] = { -1.0f, 1.0f, -5.0f };
	m_side[3].m_vertexCords[1] = { -1.0f, 1.0f, -15.0f };
	m_side[3].m_vertexCords[2] = { -1.0f, -1.0f, -15.0f };
	m_side[3].m_vertexCords[3] = { -1.0f, -1.0f, -5.0f };

	//Front Right - 4
	m_side[4].m_vertexCords[0] = { 1.0f, 1.0f, -15.0f };
	m_side[4].m_vertexCords[1] = { 1.0f, 1.0f, -5.0f };
	m_side[4].m_vertexCords[2] = { 1.0f, -1.0f, -5.0f };
	m_side[4].m_vertexCords[3] = { 1.0f, -1.0f, -15.0f };


	//Bottom - 5
	m_side[5].m_vertexCords[0] = { 1.0f, -1.0f, -15.0f };
	m_side[5].m_vertexCords[1] = { -1.0f, -1.0f, -15.0f };
	m_side[5].m_vertexCords[2] = { -1.0f, -1.0f, -5.0f };
	m_side[5].m_vertexCords[3] = { 1.0f, -1.0f, -5.0f };
	visibilityCheck();
}

Game::~Game(){}

void Game::run()
{

	initialize();//Sets up the OpenGL

	Event event;

	while (isRunning){


		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
isRunning = false;
			}
		}
		update();
		draw();
	}

}

void Game::visibilityCheck()
{
	MyVector3 tempNormal;
	//Side 0
	//n=(P2−P1)×(P3−P1) 
	tempNormal = (m_side[0].m_vertexCords[2] - m_side[0].m_vertexCords[1]) ^ (m_side[0].m_vertexCords[3] - m_side[0].m_vertexCords[1]);
	if (tempNormal.getZ() >= 0)
	{
		m_side[0].m_visible = true;
	}
	//Side 1
	tempNormal = (m_side[1].m_vertexCords[2] - m_side[1].m_vertexCords[1]) ^ (m_side[1].m_vertexCords[3] - m_side[1].m_vertexCords[1]);
	if (tempNormal.getZ() >= 0)
	{
		m_side[1].m_visible = true;
	}
	//Side 2
	tempNormal = (m_side[2].m_vertexCords[2] - m_side[2].m_vertexCords[1]) ^ (m_side[2].m_vertexCords[3] - m_side[2].m_vertexCords[1]);
	if (tempNormal.getZ() >= 0)
	{
		m_side[2].m_visible = true;
	}
	//Side 3
	tempNormal = (m_side[3].m_vertexCords[2] - m_side[3].m_vertexCords[1]) ^ (m_side[3].m_vertexCords[3] - m_side[3].m_vertexCords[1]);
	if (tempNormal.getZ() >= 0)
	{
		m_side[3].m_visible = true;
	}
	//Side 4
	tempNormal = (m_side[4].m_vertexCords[2] - m_side[4].m_vertexCords[1]) ^ (m_side[4].m_vertexCords[3] - m_side[4].m_vertexCords[1]);
	if (tempNormal.getZ() >= 0)
	{
		m_side[4].m_visible = true;
	}
	//Side 5
	tempNormal = (m_side[5].m_vertexCords[2] - m_side[5].m_vertexCords[1]) ^ (m_side[5].m_vertexCords[3] - m_side[5].m_vertexCords[1]);
	if (tempNormal.getZ() >= 0)
	{
		m_side[5].m_visible = true;
	}
}//Checks to see if the normal of each side is correct to be visible

void Game::initialize()
{
	isRunning = true;

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);

}

void Game::update()
{
	elapsed = clock.getElapsedTime();

	if (elapsed.asSeconds() >= 1.0f)
	{
		clock.restart();

		if (!updatable)
		{
			updatable = true;
		}
		else
			updatable = false;
	}

	if (updatable)
	{
		rotationAngle += 0.005f;

		if (rotationAngle > 360.0f)
		{
			rotationAngle -= 360.0f;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))//Rotates Right
	{
		m_changed = true;
		m_Matrix = m_Matrix.Rotation(1);
			
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))//Rotates Left
	{
		m_changed = true;
		m_Matrix = m_Matrix.Rotation(-1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))//Moves Right
	{
		m_changed = true;
		m_Matrix = m_Matrix.Translate(0.001, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))//Moves Left
	{
		m_changed = true;
		m_Matrix = m_Matrix.Translate(-0.001, 0);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Add))//Scales Down
	{
		m_changed = true;
		m_Matrix = m_Matrix.Scale(99.5, 99.5);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Subtract))//Scales Up
	{
		m_changed = true;
		m_Matrix = m_Matrix.Scale(100.5, 100.5);
	}
}

void Game::draw()
{
	if (m_changed)//If the Matrix has changed it enters
	{
		m_changed = false;
		for (int i = 0; i < 6; i++)//Changes each vertex for each side
		{
			for (int u = 0; u < 4; u++)
			{
				m_side[i].m_vertexCords[u] = m_side[i].m_vertexCords[u] * m_Matrix;
				

			}
		}
	}
	visibilityCheck();//Checks to see which side is visible

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	//glRotatef(rotationAngle, 0, 1, 0); // Rotates the camera on Y Axis
	
	glBegin(GL_QUADS);
	if (m_side[0].m_visible == true)//If Visible 
	{
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(m_side[0].m_vertexCords[0].getX(), m_side[0].m_vertexCords[0].getY(), m_side[0].m_vertexCords[0].getZ());
		glVertex3f(m_side[0].m_vertexCords[1].getX(), m_side[0].m_vertexCords[1].getY(), m_side[0].m_vertexCords[1].getZ());
		glVertex3f(m_side[0].m_vertexCords[2].getX(), m_side[0].m_vertexCords[2].getY(), m_side[0].m_vertexCords[2].getZ());
		glVertex3f(m_side[0].m_vertexCords[3].getX(), m_side[0].m_vertexCords[3].getY(), m_side[0].m_vertexCords[3].getZ());
	}
	if (m_side[1].m_visible == true)
	{
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(m_side[1].m_vertexCords[0].getX(), m_side[1].m_vertexCords[0].getY(), m_side[1].m_vertexCords[0].getZ());
		glVertex3f(m_side[1].m_vertexCords[1].getX(), m_side[1].m_vertexCords[1].getY(), m_side[1].m_vertexCords[1].getZ());
		glVertex3f(m_side[1].m_vertexCords[2].getX(), m_side[1].m_vertexCords[2].getY(), m_side[1].m_vertexCords[2].getZ());
		glVertex3f(m_side[1].m_vertexCords[3].getX(), m_side[1].m_vertexCords[3].getY(), m_side[1].m_vertexCords[3].getZ());
	}
	if (m_side[2].m_visible == true)
	{
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(m_side[2].m_vertexCords[0].getX(), m_side[2].m_vertexCords[0].getY(), m_side[2].m_vertexCords[0].getZ());
		glVertex3f(m_side[2].m_vertexCords[1].getX(), m_side[2].m_vertexCords[1].getY(), m_side[2].m_vertexCords[1].getZ());
		glVertex3f(m_side[2].m_vertexCords[2].getX(), m_side[2].m_vertexCords[2].getY(), m_side[2].m_vertexCords[2].getZ());
		glVertex3f(m_side[2].m_vertexCords[3].getX(), m_side[2].m_vertexCords[3].getY(), m_side[2].m_vertexCords[3].getZ());
	}
	if (m_side[3].m_visible == true)
	{
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex3f(m_side[3].m_vertexCords[0].getX(), m_side[3].m_vertexCords[0].getY(), m_side[3].m_vertexCords[0].getZ());
		glVertex3f(m_side[3].m_vertexCords[1].getX(), m_side[3].m_vertexCords[1].getY(), m_side[3].m_vertexCords[1].getZ());
		glVertex3f(m_side[3].m_vertexCords[2].getX(), m_side[3].m_vertexCords[2].getY(), m_side[3].m_vertexCords[2].getZ());
		glVertex3f(m_side[3].m_vertexCords[3].getX(), m_side[3].m_vertexCords[3].getY(), m_side[3].m_vertexCords[3].getZ());
	}
	if (m_side[4].m_visible == true)
	{
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex3f(m_side[4].m_vertexCords[0].getX(), m_side[4].m_vertexCords[0].getY(), m_side[4].m_vertexCords[0].getZ());
		glVertex3f(m_side[4].m_vertexCords[1].getX(), m_side[4].m_vertexCords[1].getY(), m_side[4].m_vertexCords[1].getZ());
		glVertex3f(m_side[4].m_vertexCords[2].getX(), m_side[4].m_vertexCords[2].getY(), m_side[4].m_vertexCords[2].getZ());
		glVertex3f(m_side[4].m_vertexCords[3].getX(), m_side[4].m_vertexCords[3].getY(), m_side[4].m_vertexCords[3].getZ());
	}
	if (m_side[5].m_visible == true)
	{
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex3f(m_side[5].m_vertexCords[0].getX(), m_side[5].m_vertexCords[0].getY(), m_side[5].m_vertexCords[0].getZ());
		glVertex3f(m_side[5].m_vertexCords[1].getX(), m_side[5].m_vertexCords[1].getY(), m_side[5].m_vertexCords[1].getZ());
		glVertex3f(m_side[5].m_vertexCords[2].getX(), m_side[5].m_vertexCords[2].getY(), m_side[5].m_vertexCords[2].getZ());
		glVertex3f(m_side[5].m_vertexCords[3].getX(), m_side[5].m_vertexCords[3].getY(), m_side[5].m_vertexCords[3].getZ());
	}

	glEnd();
	window.display();

}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}
