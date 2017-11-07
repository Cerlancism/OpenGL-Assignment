#pragma once
class Vector2f
{
public:
	Vector2f();
	Vector2f(float x, float y);

	static void ConvertMouseCoordinates(int x, int y, int width, int height, bool isCLick);

	float X;
	float Y;

	static const Vector2f Top;

	static Vector2f MousePosition;

	~Vector2f();
};

