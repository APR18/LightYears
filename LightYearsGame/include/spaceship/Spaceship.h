#ifndef SPACESHIP_HPP
#define SPACESHIP_HPP
#include "framework/Level.h"
#include "framework/Actor.h"
#include "SFML/Graphics.hpp"
namespace LightYears
{
	class Spaceship : public Actor
	{
	public:
		Spaceship(Level* owningWorld, const std::string& texturePath = "");
		virtual void update(float deltaTime) override;
		void setVelocity(sf::Vector2f& newVelocity);
		sf::Vector2f getVelocity() const;
		virtual void shoot();
		virtual void beginPlay() override;
	private:
		sf::Vector2f mVeclocity;
	};
}


#endif // !SPACESHIP_HPP
