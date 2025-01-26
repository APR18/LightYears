#pragma once
#include <string>
std::string getResourceDir() 
{
#ifdef NDEBUG
	return "assets/";
#else
	return "C:/Users/anand/Documents/c++ UDEMY/LightYears/LightYearsGame/assets/"
#endif
}
