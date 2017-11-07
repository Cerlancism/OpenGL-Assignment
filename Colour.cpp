#include "stdafx.h"
#include "Colour.h"

const Colour Colour::BLACK = Colour(0, 0, 0);
const Colour Colour::RED = Colour(1, 0, 0);
const Colour Colour::GREEN = Colour(0, 1, 0);
const Colour Colour::BLUE = Colour(0, 0, 1);
const Colour Colour::YELLOW = Colour(1, 1, 0);

Colour::Colour()
{

}

Colour::Colour(float red, float green, float blue)
{
	Red = red;
	Green = green;
	Blue = blue;
}

Colour Colour::Random()
{
	return Colour();
}

std::string Colour::ToString()
{
	return to_string(Red) + " " + to_string(Green) + " " + to_string(Blue);
}

Colour::~Colour()
{

}
