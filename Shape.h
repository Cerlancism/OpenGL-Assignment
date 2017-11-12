#pragma once
#include <vector>
#include <gl\GL.h>
#include <gl\GLU.h>
//Base class for all the shapes
class Shape
{
public:
	//Configuration enums for what type of shapes can construct
	enum class ShapeType { SQURE, TRIANGLE, CIRCLE, RANDOM, RANDOMANY };
	enum class Fill { FILLED, WIREFRAME, RANDOM };
	enum class Size { SMALL, MEDIUM, LARGE, RANDOM, RANDOMANY};
	//Glocalised holder pointing to all the constructed shapes
	static std::vector<Shape*> List;

	ShapeType Type;
	Colour ShapeColour;
	Vector2f position = Vector2f::MousePosition;
	bool IsFilled;
	float ShapeSize;

	Shape();
	Shape(ShapeType type, Colour colour, Fill fillmode, Size size);
	//Virtual draw method to be overriden by derived shapes
	virtual void Draw();

	~Shape();
};

