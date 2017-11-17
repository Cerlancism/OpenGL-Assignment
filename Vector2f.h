#pragma once
//Vector class to store 2 floats values of X and Y
class Vector2f
{
public:
	//Global holder for current mouse position
	static Vector2f MousePosition;

	float X;
	float Y;

	Vector2f();
	Vector2f(float x, float y);
	//Update mouse position to GL coordinates
	static void ConvertMouseCoordinates(int x, int y, int width, int height);
	//Get a string representation for debug
	std::string ToString();

	~Vector2f();
};
//Define vector operator behaviours
Vector2f operator+(Vector2f left, Vector2f right);

Vector2f operator-(Vector2f left, Vector2f right);

Vector2f operator*(Vector2f value, float multiplier);

Vector2f operator*(float multiplier, Vector2f value);

Vector2f operator/(Vector2f value, float divider);
