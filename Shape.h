#pragma once
class Shape
{
public:
	enum class ShapeType{SQURE, TRIANGLE, CIRCLE, RANDOM };
	enum class Fill {FILLED, WIREFRAME, RANDOM};
	enum class Size {SMALL, MEDIUM, LARGE, RANDOM};

	Shape();
	~Shape();
};

