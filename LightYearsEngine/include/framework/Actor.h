#pragma once
#include<framework/Core.h>
namespace ly
{
	class World;
	class Actor
	{
	public:
		Actor(World* owningWorld);
		void beginPlayInternal();
		virtual void beginPlay();
		virtual void tick(float deltaTime);

	private:
		World* mOwningWorld;
		bool mBeganPlay;
	};
}