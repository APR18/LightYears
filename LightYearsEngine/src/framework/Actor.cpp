#include "framework/Actor.h"
#include"framework/Core.h"

namespace LightYears
{
	Actor::Actor(Level* owningLevel) :
		mBeginPlay(false),
		mOwningLevel(owningLevel)

	{

	}
	void Actor::beginPlayInternal()
	{
		if (!mBeginPlay)
		{
			mBeginPlay = true;
			beginPlay();
		}
	}

	void Actor::beginPlay()
	{
		LOG("Actor begin play");
	}
	void Actor::update(float deltaTime)
	{
		LOG("Actor Ticking now");
	}
}