#ifndef PHYSICS_SYSTEM_HPP
#define PHYSICS_SYSTEM_HPP
#include "framework/Core.h"
#include <box2d/b2_world.h>
namespace LightYears
{
	class Actor;
	class PhysicsSystem
	{
	public:
		static PhysicsSystem& get();
		void step(float deltaTime);
		b2Body* addListener(Actor* listener);
		void removeListener(b2Body* bodyToRemove);
		float getPhysicsScale();
	protected:
		PhysicsSystem();
	private:
		static unique<PhysicsSystem> physicsSystem;
		b2World mPhysicsWorld;
		float mPhysicsScale;
		int mVelocityIterations;
		int mPositionIterations;
	};
}
#endif // !PHYSICS_SYSTEM_HPP
