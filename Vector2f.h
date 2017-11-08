#pragma once
class Vector2f
{
public:
	static const Vector2f Top;

	static Vector2f MousePosition;

	float X;
	float Y;

	Vector2f();
	Vector2f(float x, float y);

	static void ConvertMouseCoordinates(int x, int y, int width, int height);

	std::string ToString()
	{
		return std::to_string(X) + " " + std::to_string(Y);
	}

	~Vector2f();
};

Vector2f operator+(Vector2f left, Vector2f right);

Vector2f operator-(Vector2f left, Vector2f right);

Vector2f operator*(Vector2f value, float multiplier);

Vector2f operator*(float multiplier, Vector2f value);

Vector2f operator/(Vector2f value, float divider);

Vector2f operator/(float divider, Vector2f value);
