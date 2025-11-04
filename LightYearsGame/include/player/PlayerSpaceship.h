#ifndef PLAYER_SPACESHIP_HPP
#define PLAYER_SPACESHIP_HPP
#include "framework/Level.h"
#include "spaceship/spaceship.h"
#include "framework/MathUtility.h"
namespace LightYears
{
	class BulletShooter;
	class PlayerSpaceship:public Spaceship
	{
	public:
		PlayerSpaceship(Level* owningWorld, const std::string& texturePath = "SpaceShooterRedux/PNG/playerShip1_blue.png");
		virtual void update(float deltaTime) override;
		void setSpeed(float newSpeed);
		float getSpeed() const;
	private:
		void handleInput();
		void applyInput(float deltaTime);
		void restrictPlayeronEdge();
		void normalizeInput();
		virtual void shoot() override;
		sf::Vector2f mMovement;
		float mSpeed;
		unique<BulletShooter> mShooter;
	};
}
#endif // !PLAYER_SPACESHIP_HPP
