#include "weapon/Shooter.h"
namespace LightYears
{
	void Shooter::Shoot()
	{
		if (canShoot() && !isOnCoolDown())
			shootImpl();
	}
	bool Shooter::canShoot() const
	{
		return true;
	}
	bool Shooter::isOnCoolDown() const
	{
		return false;
	}
	Actor* Shooter::getOwner() const
	{
		return mOwner;
	}
	Shooter::Shooter(Actor* owner):
		mOwner(owner)
	{

	}
}

