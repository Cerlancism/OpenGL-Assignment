#include "stdafx.h"
#include "Shape.h"
#include "Square.h"
#include "Triangle.h"
#include "Circle.h"

std::vector<Shape*> Shape::List;

Shape::Shape()
{

}

Shape::Shape(ShapeType type, Colour colour, Fill fillmode, Size size)
{

	bool isfill = false;
	float sizevalue = 0.1f;
	float sizepool[] = { 0.02f, 0.06f, 0.12f };

	if (type == ShapeType::RANDOM)
	{
		type = (ShapeType)Random::RandomRange(0, 2);
	}

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
			sizevalue = Random::RandomRange(0.01f, 0.5f);
			break;
	}
	switch (type)
	{
		case ShapeType::SQURE:
			List.push_back(new Square(type, colour, isfill, sizevalue));
			break;

		case ShapeType::TRIANGLE:
			List.push_back(new Triangle(type, colour, isfill, sizevalue));
			break;

		case ShapeType::CIRCLE:
			List.push_back(new Circle(type, colour, isfill, sizevalue, false));
			break;

		case ShapeType::RANDOMANY:
			List.push_back(new Circle(type, colour, isfill, sizevalue, true));
			break;
	}
}

void Shape::Draw()
{

}

Shape::~Shape()
{

}
