#include "gameFramework/GameApplication.h"
#include "framework/World.h"
#include "framework/Actor.h"
ly::Application* GetApplication()
{
	return new ly::GameApplication{};
}

namespace ly
{
	GameApplication::GameApplication()
	{
		weak<World> newWorld = loadWorld<World>();
		/*
		This function creates a new actor and adds it to the mPending Actor list
		*/
		newWorld.lock()->spawnActor<Actor>();
		actorToDestroy = newWorld.lock()->spawnActor<Actor>();
		counter = 0;
	}
	void GameApplication::tick(float deltatime)
	{
		counter += deltatime;
		if (counter > 2.f)
		{
			if (!actorToDestroy.expired())
			{
				actorToDestroy.lock()->destroy();
			}
		}
	}
}

