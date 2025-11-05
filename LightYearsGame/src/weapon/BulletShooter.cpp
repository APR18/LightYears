#include "weapon/BulletShooter.h"
#include "framework/Core.h"
#include "weapon/Bullet.h"
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
		weak<Bullet> newBullet = getOwner()->getLevel()->spawnActor<Bullet>(getOwner(),"SpaceShooterRedux/PNG/Lasers/laserBlue01.png");
		newBullet.lock()->setActorLocation(getOwner()->getActorLocation());
		newBullet.lock()->setActorRotation(getOwner()->getActorRotation());

		
	}

}
