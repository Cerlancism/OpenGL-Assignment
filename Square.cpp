#include "stdafx.h"
#include "Square.h"

Square::Square(ShapeType type, Colour colour, bool isfilled, float size)
{
	Type = type;
	ShapeColour = colour;
	IsFilled = isfilled;
	ShapeSize = size;
	lineWidth = ShapeSize < 0.1 ? 1 : 2;
	//Calculate the vertices based on the size and position
	topLeft = topLeft * ShapeSize + position;
	topright = topright * ShapeSize + position;
	bottomleft = bottomleft * ShapeSize + position;
	bottomright = bottomright * ShapeSize + position;
}

void Square::Draw()
{
	glLineWidth(lineWidth);
	glBegin(IsFilled ? GL_POLYGON : GL_LINE_LOOP);
	glColor3f(ShapeColour.Red, ShapeColour.Green, ShapeColour.Blue);
	glVertex2f(topLeft.X, topLeft.Y);
	glVertex2f(topright.X, topright.Y);
	glVertex2f(bottomright.X, bottomright.Y);
	glVertex2f(bottomleft.X, bottomleft.Y);
	glEnd();
}

Square::~Square()
{}
