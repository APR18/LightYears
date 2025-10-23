#ifndef MATH_UTILITY_HPP
#define MATH_UTILITY_HPP
#include <SFML/Graphics.hpp>
namespace LightYears
{
	sf::Vector2f RotationToVector(float rotation);
	float DegreesToRadians(float degrees);
	float RadiansToDegrees(float Radians);
}
#endif // !MATH_UTILITY_HPP
