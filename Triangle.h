#pragma once
#include "Shape.h"
#include <cmath>
class Triangle : public Shape
{
public:
	Triangle(ShapeType type, Colour colour, bool isfilled, float size);

	void Draw() override;

	~Triangle();

private:
	Vector2f top = Vector2f(0, -1.0f + sqrt(4.0f));
	Vector2f bottomleft = Vector2f(-1.0f, -1.0f);
	Vector2f bottomright = Vector2f(1.0f, -1.0f);

	float lineWidth = 2;
};

