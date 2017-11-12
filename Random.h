#pragma once
//Random number generation ultility
class Random
{
public:
	static int RandomRange(int start, int end);
	static float RandomRange(float start, float end);
	static float RandomFloatNormal();
};

