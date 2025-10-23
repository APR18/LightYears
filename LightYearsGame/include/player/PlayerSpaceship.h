#ifndef PLAYER_SPACESHIP_HPP
#define PLAYER_SPACESHIP_HPP
#include "framework/Level.h"
#include "spaceship/spaceship.h"
namespace LightYears
{
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
		sf::Vector2f mMovement;
		float mSpeed;

	};
}
#endif // !PLAYER_SPACESHIP_HPP
