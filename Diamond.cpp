#include "stdafx.h"
#include "Diamond.h"


Diamond::Diamond(Colour colour, bool isfilled, float size)
{
	Type = Shape::ShapeType::DIAMOND;
	ShapeColour = colour;
	IsFilled = isfilled;
	ShapeSize = size;
	lineWidth = ShapeSize < 0.1 ? 1 : 2;
	//Calculate the vertices based on the size and position
	top = top * ShapeSize + position;
	left = left * ShapeSize + position;
	right = right * ShapeSize + position;
	bottom = bottom * ShapeSize + position;
}

void Diamond::Draw()
{
	glLineWidth(lineWidth);
	glBegin(IsFilled ? GL_POLYGON : GL_LINE_LOOP);
	glColor3f(ShapeColour.Red, ShapeColour.Green, ShapeColour.Blue);
	glVertex2f(top.X, top.Y);
	glVertex2f(left.X, left.Y);
	glVertex2f(bottom.X, bottom.Y);
	glVertex2f(right.X, right.Y);
	glEnd();
}

Diamond::~Diamond()
{}
