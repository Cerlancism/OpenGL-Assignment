#include "Debug.h"
#include "stdafx.h"
#include "WinBase.h"

void Debug::Log(std::wstring log)
{
	auto output = log.c_str();
	OutputDebugStringW(output);
	OutputDebugStringA("\n");
}

void Debug::Log(char a[])
{
	OutputDebugStringA(a);
	OutputDebugStringA("\n");
}

void Debug::Log(char a[], std::wstring log)
{
	OutputDebugStringA(a);
	OutputDebugStringA(" : ");
	auto output = log.c_str();
	OutputDebugStringW(output);
	OutputDebugStringA("\n");
}
