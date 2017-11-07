#include "stdafx.h"
#include "Random.h"

int Random::RandomRange(int start, int end)
{
	int overflowrange = 1 + (end - start) / RAND_MAX;
	return start + (rand() * overflowrange) % (end - start);
}

int Random::RandomRange(float start, float end)
{
	return 0;
}
