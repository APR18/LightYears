#include "weapon/BulletShooter.h"
#include "framework/Core.h"
namespace LightYears
{
	BulletShooter::BulletShooter(Actor* owner, float coolDownTime)
		:Shooter(owner),
		mCoolDownTime(coolDownTime),
		mCoolDownClock()
	{

	}
	bool BulletShooter::isOnCoolDown() const
	{
		if (mCoolDownClock.getElapsedTime().asSeconds() > mCoolDownTime)
		{
			return false;
		}
		return true;
	}

	void BulletShooter::shootImpl()
	{
		mCoolDownClock.restart();
		LOG("Shooting!");
	}

}
