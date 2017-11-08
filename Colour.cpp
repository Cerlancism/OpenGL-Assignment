#include "stdafx.h"
#include "Colour.h"

const Colour Colour::BLACK(0, 0, 0);
const Colour Colour::RED(1, 0, 0);
const Colour Colour::GREEN(0, 1, 0);
const Colour Colour::BLUE(0, 0, 1);
const Colour Colour::YELLOW(1, 1, 0);

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
	switch (Random::RandomRange(1 , 4))
	{
		case 1:
			return Colour::RED;

		case 2:
			return Colour::GREEN;

		case 3:
			return Colour::BLUE;

		case 4:
			return Colour::YELLOW;
	}
	return Colour::BLACK;
}

Colour Colour::RandomAny()
{
	return Colour(Random::RandomFloatNormal(), Random::RandomFloatNormal(), Random::RandomFloatNormal());
}

void Colour::FadetoWhite()
{
	float rate = 0.01f;
	Red = Red + rate >= 1 ? 1 : Red + rate;
	Green = Green + rate >= 1 ? 1 : Green + rate;
	Blue = Blue + rate >= 1 ? 1 : Blue + rate;
}

std::string Colour::ToString()
{
	return to_string(Red) + " " + to_string(Green) + " " + to_string(Blue);
}

Colour::~Colour()
{

}
