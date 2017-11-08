#include "Vector2f.h"
#include "stdafx.h"

const Vector2f Top(0 , 1);
const Vector2f Bottom(0, -1);

Vector2f Vector2f::MousePosition;

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

void Vector2f::ConvertMouseCoordinates(int x, int y, int width, int height)
{
	//Normalise pixels and fix offsets
	float normalisexWinPos = x * 2.0f * (400.0f / 383.0f) / width;
	float normaliseyWinPos = y * 2.0f * (400.0f / 340.0f) / height;
	MousePosition.X = normalisexWinPos > 1 ? normalisexWinPos - 1 : 0 - (1 - normalisexWinPos);
	MousePosition.Y = normaliseyWinPos > 1 ? ((0 - (1 - normaliseyWinPos)) * -1) : abs(normaliseyWinPos - 1);
	Debug::Log("Mouse Position", MousePosition.ToString());
}

Vector2f operator+(Vector2f left, Vector2f right)
{
	Vector2f result;
	result.X = left.X + right.X;
	result.Y = left.Y + right.Y;
	return result;
}

Vector2f operator-(Vector2f left, Vector2f right)
{
	Vector2f result;
	result.X = left.X - right.X;
	result.Y = left.Y - right.Y;
	return result;
}

Vector2f operator*(Vector2f value, float multiplier)
{
	value.X *= multiplier;
	value.Y *= multiplier;
	return value;
}

Vector2f operator*(float multiplier, Vector2f value)
{
	value.X *= multiplier;
	value.Y *= multiplier;
	return value;
}

Vector2f operator/(Vector2f value, float divider)
{
	value.X /= divider;
	value.Y /= divider;
	return value;
}

Vector2f operator/(float divider, Vector2f value)
{
	value.X /= divider;
	value.Y /= divider;
	return value;
}

Vector2f::~Vector2f()
{}
