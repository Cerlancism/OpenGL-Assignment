#include "Vector2f.h"
#include "stdafx.h"

const Vector2f Top = Vector2f(0 , 1);
const Vector2f Bottom = Vector2f(0, -1);

Vector2f Vector2f::MousePosition = Vector2f();

Vector2f::Vector2f()
{
	X = 0;
	Y = 0;
}

Vector2f::Vector2f(float x, float y)
{
	X = x;
	Y = y;
}

void Vector2f::ConvertMouseCoordinates(int x, int y, int width, int height, bool isCLick)
{
	//Normalise pixels and fix offsets
	float normalisexWinPos = x * 2.0f * (400.0f / 383.0f) / width;
	float normaliseyWinPos = y * 2.0f * (400.0f / 340.0f) / height;
	MousePosition.X = normalisexWinPos > 1 ? normalisexWinPos - 1 : 0 - (1 - normalisexWinPos);
	MousePosition.Y = normaliseyWinPos > 1 ? ((0 - (1 - normaliseyWinPos)) * -1) : abs(normaliseyWinPos - 1);
	if (isCLick)
	{
		Debug::Log("Mouse Position", MousePosition.ToString());
		Debug::Log("Random Number", to_string(Random::RandomRange(0, 10)));
	}
}
std::string Vector2f::ToString()
{
	return to_string(X) + " " + to_string(Y);;
}



Vector2f::~Vector2f()
{}
