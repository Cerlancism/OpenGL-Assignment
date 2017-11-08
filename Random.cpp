#include "stdafx.h"
#include "Random.h"

int Random::RandomRange(int start, int end)
{
	float normalised = (float)rand() / (float)RAND_MAX;
	return start + int((end - start + 1) * normalised);
}

float Random::RandomRange(float start, float end)
{
	float normalised = (float)rand() / (float)RAND_MAX;
	return start + (end - start) * normalised;
}

float Random::RandomFloatNormal()
{
	float normalised = (float)rand() / (float)RAND_MAX;
	return normalised;
}
