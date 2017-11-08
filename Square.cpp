#include "stdafx.h"
#include "Square.h"

vector<Square> Square::List;

Square::Square(ShapeType type, Colour colour, bool isfilled, float size)
{
	position = Vector2f::MousePosition;
	Type = type;
	ShapeColour = colour;
	IsFilled = isfilled;
	ShapeSize = size;
}

void Square::Draw()
{
	topLeft = topLeft * ShapeSize + position;
	topright = topright * ShapeSize + position;
	bottomleft = bottomleft * ShapeSize + position;
	bottomright = bottomright * ShapeSize + position;
	glBegin(IsFilled ? GL_LINE_STRIP : GL_POLYGON);
	glColor3f(ShapeColour.Red, ShapeColour.Green, ShapeColour.Blue);
	glVertex2f(topLeft.X, topLeft.Y);
	glVertex2f(topright.X, topright.Y);
	glVertex2f(bottomleft.X, bottomleft.Y);
	glVertex2f(bottomright.X, bottomright.Y);
	glEnd;
}

Square::~Square()
{}
