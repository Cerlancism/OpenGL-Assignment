#include "stdafx.h"
#include "Shape.h"
#include "Square.h"

Shape::Shape()
{

}

Shape::Shape(ShapeType type, Colour colour, Fill fillmode, Size size)
{

	bool isfill = false;
	float sizevalue = 0.1f;
	float sizepool[] = { 0.1f, 0.2f, 0.4f };

	switch (fillmode)
	{
		case Fill::FILLED:
			isfill = true;
			break;
		case Fill::WIREFRAME:
			isfill = false;
			break;
		case Fill::RANDOM:
			isfill = Random::RandomRange(0, 1) == 0 ? true : false;
			break;
	}
	
	switch (size)
	{
		case Size::SMALL:
			sizevalue = sizepool[0];
			break;
		case Size::MEDIUM:
			sizevalue = sizepool[1];
			break;
		case Size::LARGE:
			sizevalue = sizepool[2];
			break;
		case Size::RANDOM:
			sizevalue = sizepool[Random::RandomRange(0, 2)];
			break;
		case Size::RANDOMANY:
			sizevalue = Random::RandomRange(0.1f, 0.5f);
			break;
	}
	Square newsquare(type, colour, isfill, sizevalue);
	switch (type)
	{
		case ShapeType::SQURE:
			Square::List.push_back(newsquare);
			break;

		case ShapeType::TRIANGLE:
			break;

		case ShapeType::CIRCLE:
			break;

		case ShapeType::RANDOM:
			break;

		case ShapeType::RANDOMANY:
			break;
	}
	this->~Shape();
}

void Shape::Draw()
{

}

Shape::~Shape()
{

}
