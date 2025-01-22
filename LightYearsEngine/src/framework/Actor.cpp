#include "framework/Actor.h"

namespace ly
{
	Actor::Actor(World* owningWorld):
		mOwningWorld{owningWorld},mBeganPlay{false}
	{
		
	}
	void Actor::beginPlayInternal()
	{
		if (!mBeganPlay)
		{
			mBeganPlay = true;
			beginPlay();
		}
	}
	void Actor::beginPlay()
	{
		LOG("Actor Begin play");
	}
	void Actor::tick(float deltaTime)
	{
		LOG("Actor Ticking");
	}
}
