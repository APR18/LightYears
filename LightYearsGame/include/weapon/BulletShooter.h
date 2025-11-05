#ifndef BULLET_SHOOTER_CPP
#define BULLET_SHOOTER_CPP
#include<SFML/System.hpp>
#include "weapon/Shooter.h"
namespace LightYears
{
	class BulletShooter : public Shooter
	{
	public:
		BulletShooter(Actor* owner, float coolDownTime = 0.2f);
		virtual bool isOnCoolDown() const override;
	private:
		virtual void shootImpl() override;
		sf::Clock mCoolDownClock;
		float mCoolDownTime;
	};
}
#endif // !BULLET_SHOOTER_CPP
