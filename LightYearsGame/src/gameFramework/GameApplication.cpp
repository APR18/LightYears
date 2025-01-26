#include "gameFramework/GameApplication.h"
#include "framework/World.h"
#include "framework/Actor.h"
#include "config.h"
ly::Application* GetApplication()
{
	return new ly::GameApplication{};
}

namespace ly
{
	GameApplication::GameApplication()
		:Application{600, 980,"Light Years",sf::Style::Titlebar | sf::Style::Close}
	{
		weak<World> newWorld = loadWorld<World>();
		/*
		This function creates a new actor and adds it to the mPending Actor list
		*/
		newWorld.lock()->spawnActor<Actor>();
		actorToDestroy = newWorld.lock()->spawnActor<Actor>();
		actorToDestroy.lock()->setTexture(getResourceDir()+"SpaceShooterRedux/PNG/playerShip1_orange.png");
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

