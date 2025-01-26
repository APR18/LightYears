#pragma once
#include "framework/Core.h"
#include "framework/Object.h"
namespace ly
{
	class World;
	class Actor : public Object
	{
	public:
		Actor(World* owningWorld);
		virtual ~Actor();
		void beginPlayInternal();
		virtual void beginPlay();
		virtual void tick(float deltaTime);

	private:
		World* mOwningWorld;
		bool mBeganPlay;
	};
}