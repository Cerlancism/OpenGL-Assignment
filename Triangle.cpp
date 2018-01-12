#include "stdafx.h"
#include "Triangle.h"

Triangle::Triangle(Colour colour, bool isfilled, float size)
{
	Type = Shape::ShapeType::TRIANGLE;
	ShapeColour = colour;
	IsFilled = isfilled;
	ShapeSize = size;
	lineWidth = ShapeSize < 0.1 ? 1 : 2;
	//Calculate the vertices based on the size and position
	top = (top * ShapeSize) + position;
	bottomleft = (bottomleft * ShapeSize) + position;
	bottomright = (bottomright * ShapeSize) + position;
}

void Triangle::Draw()
{
	glLineWidth(lineWidth);
	glBegin(IsFilled ? GL_POLYGON : GL_LINE_LOOP);
	glColor3f(ShapeColour.Red, ShapeColour.Green, ShapeColour.Blue);
	glVertex2f(top.X, top.Y);
	glVertex2f(bottomright.X, bottomright.Y);
	glVertex2f(bottomleft.X, bottomleft.Y);
	glEnd();
}

Triangle::~Triangle()
{}
