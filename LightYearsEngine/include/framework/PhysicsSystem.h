#ifndef PHYSICS_SYSTEM_HPP
#define PHYSICS_SYSTEM_HPP
#include "framework/Core.h"
#include <box2d/b2_world.h>
namespace LightYears
{
	class PhysicsContactListener : public b2ContactListener
	{
	public:
		virtual void BeginContact(b2Contact* contact);
		virtual void EndContact(b2Contact* contact);
	};
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
		PhysicsContactListener mContactListener;
	};
}
#endif // !PHYSICS_SYSTEM_HPP
