#include "spaceship/Spaceship.h"


namespace LightYears
{
	Spaceship::Spaceship(Level* owningWorld, const std::string& texturePath)
		: Actor(owningWorld,texturePath),
		mVeclocity{}
	{

	}
	void Spaceship::update(float deltaTime)
	{
		Actor::update(deltaTime);
		addActorLocationOffset(getVelocity() * deltaTime);

	}
	void Spaceship::setVelocity(sf::Vector2f& newVelocity)
	{
		mVeclocity = newVelocity;
	}
	sf::Vector2f Spaceship::getVelocity() const
	{
		return mVeclocity;
	}
	void Spaceship::shoot()
	{
	}
}
