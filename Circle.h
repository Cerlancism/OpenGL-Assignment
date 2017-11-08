#pragma once
#include "Shape.h"

class Circle : public Shape
{
public:
	Circle(ShapeType type, Colour colour, bool isfilled, float size, bool isdistorted);

	void Draw() override;

	~Circle();

private:
	vector<Vector2f> vertices = vector<Vector2f>();
	float lineWidth;
};

float degToRad(float degAngle);
