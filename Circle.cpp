#include "stdafx.h"
#include "Circle.h"

Circle::Circle(ShapeType type, Colour colour, bool isfilled, float size, bool isdistorted)
{
	Type = type;
	ShapeColour = colour;
	IsFilled = isfilled;
	ShapeSize = size;
	lineWidth = ShapeSize < 0.1 ? 1 : 2;

	if (!isdistorted)
	{
		vertices.clear();
		int definition = ShapeSize * 320 + 8;
		float angularstep = 360.0f / definition;
		for (size_t i = 0; i < definition; i++)
		{
			Vector2f vertex;
			vertex.X = position.X + ShapeSize * cos(degToRad(angularstep * i));
			vertex.Y = position.Y + ShapeSize * sin(degToRad(angularstep * i));
			vertices.push_back(vertex);
		}
	}
	else
	{
		vertices.clear();
		int definition = ShapeSize * 16 + Random::RandomRange(4, 12);
		float angularstep = 360.0f / definition;
		for (size_t i = 0; i < definition; i++)
		{
			Vector2f vertex;
			vertex.X = position.X + ShapeSize * cos(degToRad(angularstep * i) + Random::RandomRange(-0.5f, 0.5f));
			vertex.Y = position.Y + ShapeSize * sin(degToRad(angularstep * i)+ Random::RandomRange(-0.5f, 0.5f));
			vertices.push_back(vertex);
		}
	}
	
}

float degToRad(float degAngle)
{
	double pi = atan(1) * 4;
	return degAngle / 180.0 * pi;
}

void Circle::Draw()
{
	glLineWidth(lineWidth);
	glBegin(IsFilled ? GL_POLYGON : GL_LINE_LOOP);
	glColor3f(ShapeColour.Red, ShapeColour.Green, ShapeColour.Blue);
	for (size_t i = 0; i < vertices.size(); i++)
	{
		glVertex2f(vertices[i].X, vertices[i].Y);
	}
	glEnd();
}

Circle::~Circle()
{

}
