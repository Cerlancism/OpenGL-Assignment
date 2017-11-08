#pragma once
#include "Shape.h"
class Square : public Shape
{
public:
	Square(ShapeType type, Colour colour, bool isfilled, float size);

	static std::vector<Square> List;

	void Draw() override;

	~Square();

private:
	Vector2f topLeft = Vector2f(-1, 1);
	Vector2f topright = Vector2f(1, 1);
	Vector2f bottomleft = Vector2f(-1, -1);
	Vector2f bottomright = Vector2f(1, -1);

	float lineWidth = 2;
};

