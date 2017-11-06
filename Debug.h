#pragma once
#include <string>

class Debug
{
public:
	static void Debug::Log(std::wstring log);
	static void Debug::Log(char a[]);
	static void Debug::Log(char a[], std::wstring log);
};

