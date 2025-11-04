#include "player/PlayerSpaceship.h"
#include "weapon/BulletShooter.h"
namespace LightYears
{
	PlayerSpaceship::PlayerSpaceship(Level* owningWorld, const std::string& texturePath)
		:Spaceship(owningWorld, texturePath),
		mMovement{},
		mSpeed{100.f},
		mShooter{new BulletShooter(this)}
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
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			mMovement.y = 1.f;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			mMovement.x = -1.f;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			mMovement.x = 1.f;
		}
		restrictPlayeronEdge();
		normalizeInput();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			shoot();
		
		
	}
	void PlayerSpaceship::applyInput(float deltaTime)
	{
		setVelocity(mMovement * mSpeed);
		mMovement.x = mMovement.y = 0;
	}
	void PlayerSpaceship::restrictPlayeronEdge()
	{
		sf::Vector2f actorLocation = getActorLocation();
		if (actorLocation.x < 50 && mMovement.x == -1.f)
			mMovement.x = 0.f;
		if (actorLocation.x > (getwindowSize().x - 50) && mMovement.x == 1.f)
			mMovement.x = 0.f;
		if (actorLocation.y < 50 && mMovement.y == -1.f)
			mMovement.y = 0.f;
		if (actorLocation.y > (getwindowSize().y - 50) && mMovement.y == 1.f)
			mMovement.y = 0.f;

	}
	void PlayerSpaceship::normalizeInput()
	{
		normalizeVector(mMovement);
		//LOG("move input: %f , %f", mMovement.x, mMovement.y);
	}
	void PlayerSpaceship::shoot()
	{
		if (mShooter)
			mShooter->Shoot();
	}
}

