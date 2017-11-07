#include "Debug.h"
#include "stdafx.h"
#include "WinBase.h"

void Debug::Log(std::string log)
{
	OutputDebugStringA(log.c_str());
	OutputDebugStringA("\n");
}

void Debug::Log(char a[])
{
	OutputDebugStringA(a);
	OutputDebugStringA("\n");
}

void Debug::Log(char a[], std::string log)
{
	OutputDebugStringA(a);
	OutputDebugStringA(" : ");
	OutputDebugStringA(log.c_str());
	OutputDebugStringA("\n");
}
