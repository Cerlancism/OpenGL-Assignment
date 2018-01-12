#include "stdafx.h"
#include "Shape.h"
#include "Square.h"
#include "Triangle.h"
#include "Circle.h"
#include "Diamond.h"

std::vector<Shape*> Shape::List;

Shape::Shape()
{

}
//The base constructor to process the input parameters which will then call the subsequent derived shape's constructor based on the shape type
Shape::Shape(ShapeType type, Colour colour, Fill fillmode, Size size)
{

	bool isfill = false;
	float sizevalue = 0.1f;
	float sizepool[] = { 0.02f, 0.06f, 0.12f };
	//Generate the random type
	if (type == ShapeType::RANDOM)
	{
		type = (ShapeType)Random::RandomRange(0, 2);
	}
	//Determine the fill mode
	switch (fillmode)
	{
		case Fill::FILLED:
			isfill = true;
			break;
		case Fill::WIREFRAME:
			isfill = false;
			break;
		case Fill::RANDOM: //Generate the random fill mode
			isfill = Random::RandomRange(0, 1) == 0 ? true : false;
			break;
	}
	//Determine the size of the shape
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
		case Size::RANDOM: //Generate a random fixed size
			sizevalue = sizepool[Random::RandomRange(0, 2)];
			break;
		case Size::RANDOMANY://Generate total random fixed size from a range
			sizevalue = Random::RandomRange(0.01f, 0.2f);
			break;
	}
	switch (type)
	{//Construct the derived shapes base on the type and add to the global shape pointer list
		case ShapeType::SQURE:
			List.push_back(new Square(colour, isfill, sizevalue));
			break;

		case ShapeType::TRIANGLE:
			List.push_back(new Triangle(colour, isfill, sizevalue));
			break;

		case ShapeType::CIRCLE:
			List.push_back(new Circle(colour, isfill, sizevalue, false));
			break;

		case ShapeType::DIAMOND:
			List.push_back(new Diamond(colour, isfill, sizevalue));
			break;

		case ShapeType::RANDOMANY:
			List.push_back(new Circle(colour, isfill, sizevalue, true));
			break;
	}
}
//To be overridden
void Shape::Draw()
{

}

Shape::~Shape()
{

}
