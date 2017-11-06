#include "stdafx.h"
#include "Vector2f.h"

const Vector2f Top = Vector2f(0 , 1);

Vector2f Vector2f::MousePosition = Vector2f();

Vector2f::Vector2f()
{

}

Vector2f::Vector2f(float x, float y)
{
	X = x;
	Y = y;
}

void Vector2f::ConvertMouseCoordinates(int x, int y, int width, int height)
{
	//Normalise pixels
	float normalisexWinPos = x * 2.0f / width;
	float normaliseyWinPos = y * 2.0f / height;
	MousePosition.X = normalisexWinPos > 1 ? normalisexWinPos - 1 : 0 - (1 - normalisexWinPos) + ((-1.0f - MousePosition.Y) * 0.14);
	MousePosition.Y = (normaliseyWinPos > 1 ? (0 - (1 - normaliseyWinPos)) * -1 : (normaliseyWinPos - 1)  * -1) - ((1.0f - MousePosition.Y) * 0.14);
	Debug::Log("Mouse Position X||Y", std::to_wstring(MousePosition.X));
}


Vector2f::~Vector2f()
{}
