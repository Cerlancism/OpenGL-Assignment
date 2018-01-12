#pragma once
#include "Shape.h"
class Diamond : public Shape
{
public:
	Diamond(Colour colour, bool isfilled, float size);

	void Draw() override;

	~Diamond();

private:
	//4 vertices of a Diamond
	Vector2f top = Vector2f(0.0f, 1.5f);
	Vector2f left = Vector2f(-1.0f, 0.0f);
	Vector2f right = Vector2f(1.0f, 0.0f);
	Vector2f bottom = Vector2f(0.0f, -1.5f);

	float lineWidth = 2;
};

