#ifndef CONFIG_HPP
#define CONFIG_HPP
#include <string>
std::string GetResourceFolder()
{
#ifdef NDEBUG //release
	return "assets/";
#else
	return "C:/Users/anand/Documents/CODING/c++ UDEMY/no git lightyears/LightYears/LightYearsGame/assets/";
#endif // !NDEBUG

}
#endif // !CONFIG_HPP
