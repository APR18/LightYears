#include "player/PlayerSpaceship.h"

namespace LightYears
{
	PlayerSpaceship::PlayerSpaceship(Level* owningWorld, const std::string& texturePath)
		:Spaceship(owningWorld, texturePath),
		mMovement{},
		mSpeed{100.f}
	{

	}
	void PlayerSpaceship::update(float deltaTime)
	{
		Spaceship::update(deltaTime);
		handleInput();
		applyInput(deltaTime);
	}
	void PlayerSpaceship::setSpeed(float newSpeed)
	{
		mSpeed = newSpeed;
	}
	float PlayerSpaceship::getSpeed() const
	{
		return mSpeed;
	}
	void PlayerSpaceship::handleInput()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			mMovement.y = -1.f;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			mMovement.x = -1.f;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			mMovement.y = 1.f;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			mMovement.x = 1.f;
		}
	}
	void PlayerSpaceship::applyInput(float deltaTime)
	{
		setVelocity(mMovement * mSpeed);
		mMovement.x = mMovement.y = 0;
	}
}

