#ifndef PHYSICS_SYSTEM_HPP
#define PHYSICS_SYSTEM_HPP
#include "framework/Core.h"
namespace LightYears
{
	class PhysicsSystem
	{
	public:
		static PhysicsSystem& get();
	protected:
		PhysicsSystem();
	private:
		static unique<PhysicsSystem> physicsSystem;
	};
}
#endif // !PHYSICS_SYSTEM_HPP
