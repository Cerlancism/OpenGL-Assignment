#include "stdafx.h"
#include "Random.h"
//Random int range inclusive
int Random::RandomRange(int start, int end)
{
	return start + int((end - start + 1) * RandomFloatNormal());
}
//Random float range inclusive
float Random::RandomRange(float start, float end)
{
	return start + (end - start) * RandomFloatNormal();
}
//Random float inclusive in 0 ~ 1
float Random::RandomFloatNormal()
{
	return (float)rand() / (float)RAND_MAX;
}
