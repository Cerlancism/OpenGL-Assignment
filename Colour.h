#pragma once
class Colour
{
public:
	float Red = 0;
	float Green = 0;
	float Blue = 0;

	static const Colour BLACK;
	static const Colour RED;
	static const Colour GREEN;
	static const Colour BLUE;
	static const Colour YELLOW;

	Colour Random();
	std::string ToString();

	Colour();
	Colour(float red, float green, float blue);
	~Colour();
};

