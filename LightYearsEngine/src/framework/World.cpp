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

		for (auto iter = mActors.begin(); iter != mActors.end();)
		{
			// here get is used because iter is a shared pointer pointing to Actor so to dereference it we use get()
			if (iter->get()->isPendingDestroy())
			{
				iter = mActors.erase(iter);
			}
			else
			{
				iter->get()->tick(deltaTime);
				iter++;
			}
		}

		tick(deltaTime);
	}

	void World::render(sf::RenderWindow& window)
	{
		for (auto actor : mActors)
		{
			actor->render(window);
		}
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

