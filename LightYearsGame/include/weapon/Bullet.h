#ifndef BULLET_HPP
#define BULLET_HPP
#include "framework/Actor.h"
namespace LightYears
{
	class Bullet : public Actor
	{
	public:
		Bullet(Level* level, Actor* owner, const std::string& texturePath, float speed = 600.f, float damage = 10.f);
		void setSpeed(float newSpeed);
		void setDamage(float newDamage);
		virtual void update(float deltaTime) override;
		virtual void beginPlay () override;
	private:
		void move(float deltaTime);
		Actor* mOwner;
		float mSpeed;
		float mDamage;
	};
}
#endif // !BULLET_HPP
