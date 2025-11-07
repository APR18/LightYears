#include "weapon/Bullet.h"
namespace LightYears
{
	Bullet::Bullet(Level* level, Actor* owner, const std::string& texturePath, float speed, float damage)
		:Actor(level,texturePath), 
		mOwner(owner), 
		mSpeed(speed), 
		mDamage(damage)
	{

	}

	void Bullet::setSpeed(float newSpeed)
	{
		mSpeed = newSpeed;
	}
	void Bullet::setDamage(float newDamage)
	{
		mDamage = newDamage;
	}
	void Bullet::update(float deltaTime)
	{
		Actor::update(deltaTime);
		move(deltaTime);
		if (isActorOutOfBounds())
			destroy();
	}
	void Bullet::beginPlay()
	{
		Actor::beginPlay();
		setEnablePhysics(true);
	}
	void Bullet::move(float deltaTime)
	{
		addActorLocationOffset(getActorforwardDirection() * mSpeed * deltaTime);

	}
}
