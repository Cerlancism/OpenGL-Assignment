#pragma once
#include <vector>
#include <gl\GL.h>
#include <gl\GLU.h>

class Shape
{
public:
	enum class ShapeType { SQURE, TRIANGLE, CIRCLE, RANDOM, RANDOMANY };
	enum class Fill { FILLED, WIREFRAME, RANDOM };
	enum class Size { SMALL, MEDIUM, LARGE, RANDOM, RANDOMANY};

	static std::vector<Shape*> List;

	ShapeType Type;
	Colour ShapeColour;
	Vector2f position = Vector2f::MousePosition;
	bool IsFilled;
	float ShapeSize;

	Shape();
	Shape(ShapeType type, Colour colour, Fill fillmode, Size size);

	virtual void Draw();

	~Shape();
};

