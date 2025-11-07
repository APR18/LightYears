#include "framework/PhysicsSystem.h"
namespace LightYears
{
	unique<PhysicsSystem> PhysicsSystem::physicsSystem{ nullptr };

	PhysicsSystem& PhysicsSystem::get()
	{
		if (!physicsSystem)
		{
			physicsSystem = std::move(unique<PhysicsSystem> {new PhysicsSystem});
		}
		return *physicsSystem;
	}
}