#pragma once
#include "Shape.h"
#include <cmath>
//Triangle shape derived from shape class
class Triangle : public Shape
{
public:
	Triangle(Colour colour, bool isfilled, float size);

	void Draw() override;

	~Triangle();

private:
	//3 vertices of a triangle
	Vector2f top = Vector2f(0, -1.0f + sqrt(3.0f)); //Equilateral triangle
	Vector2f bottomleft = Vector2f(-1.0f, -1.0f);
	Vector2f bottomright = Vector2f(1.0f, -1.0f);

	float lineWidth = 2;
};

