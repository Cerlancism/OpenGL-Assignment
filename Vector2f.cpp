#include "stdafx.h"
#include "Vector2f.h"

const Vector2f Vector2f::Top = Vector2f(0 , 1);

Vector2f::Vector2f()
{

}

Vector2f::Vector2f(float x, float y)
{
	X = x;
	Y = y;
}


Vector2f::~Vector2f()
{}
