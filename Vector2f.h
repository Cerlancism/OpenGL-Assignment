#pragma once
class Vector2f
{
public:
	Vector2f();
	Vector2f(float x, float y);

	static void ConvertMouseCoordinates(int x, int y, int width, int height);

	float X = 0;
	float Y = 0;

	static const Vector2f Top;

	static Vector2f MousePosition;

	~Vector2f();
};

