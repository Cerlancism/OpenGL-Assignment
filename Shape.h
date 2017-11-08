#pragma once
class Shape
{
public:
	enum class ShapeType { SQURE, TRIANGLE, CIRCLE, RANDOM, RANDOMANY };
	enum class Fill { FILLED, WIREFRAME, RANDOM };
	enum class Size { SMALL, MEDIUM, LARGE, RANDOM, RANDOMANY};

	ShapeType Type;
	Vector2f position;
	bool IsFilled;
	float size;

	Shape(ShapeType type, Colour colour, Fill fillmode, Size size);

	virtual void Draw();

	~Shape();
};

