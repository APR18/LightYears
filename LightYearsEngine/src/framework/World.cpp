#include "framework/World.h"
#include"framework/Core.h"
#include "framework/Actor.h"
namespace ly 
{
	World::World(Application* owningApp)
		:mOwningApp{owningApp},mBeganPlay{false},mActors{},mPendingActors{}
	{

	}
	void World::beginPlayInternal()
	{
		if (!mBeganPlay) 
		{
			mBeganPlay = true;
			beginPlay();
		}
	}
	void World::tickInternal(float deltaTime)
	{
		for (shared<Actor> actor : mPendingActors)
		{
			mActors.push_back(actor);
			actor->beginPlayInternal();
		}
		mPendingActors.clear();

		for (shared<Actor> actor: mActors)
		{
			actor->tick(deltaTime);
		}
		tick(deltaTime);
	}
	World::~World()
	{
	}
	void World::beginPlay()
	{
		LOG("Began play");
	}
	void World::tick(float deltaTime)
	{
		LOG("Tick at the frame rate %f", 1.f / deltaTime);
	}
}

