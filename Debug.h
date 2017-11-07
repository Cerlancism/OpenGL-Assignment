#pragma once

class Debug
{
public:
	static void Debug::Log(std::string log);
	static void Debug::Log(char a[]);
	static void Debug::Log(char a[], std::string log);
};

