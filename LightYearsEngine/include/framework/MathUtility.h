#ifndef MATH_UTILITY_HPP
#define MATH_UTILITY_HPP
#include <SFML/Graphics.hpp>
namespace LightYears
{
	sf::Vector2f RotationToVector(float rotation);
	float DegreesToRadians(float degrees);
	float RadiansToDegrees(float Radians);

	template <typename T>
	float getLengthOfVector( const sf::Vector2<T>& vector)
	{
		return std::sqrt(vector.x * vector.x + vector.y * vector.y);
	}

	template <typename T>
	void scaleVector(sf::Vector2<T>& vector, float amnt)
	{
		vector.x*= amnt;
		vector.y*= amnt;
	}

	template <typename T>
	void normalizeVector(sf::Vector2<T>& vector)
	{
		float vectorLength = getLengthOfVector(vector);
		if (vectorLength == 0.f)
			return;
		scaleVector(vector, 1/vectorLength);
	}
}
#endif // !MATH_UTILITY_HPP
