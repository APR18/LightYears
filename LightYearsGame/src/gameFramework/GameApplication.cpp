#include "gameFramework/GameApplication.h"
#include "framework/Level.h"
#include "framework/Actor.h"
#include "config.h"
LightYears::Application* GetApplication()
{
	return new LightYears::GameApplication();
}
// This function loads the levels and actors before the Application::run() function is called from the Entrypoint.h file
LightYears::GameApplication::GameApplication()
	:Application(600,980,"Light Years",sf::Style::Titlebar|sf::Style::Close)
{
	weak<Level> newWorld = loadLevel<Level>(); // loadLevel is a function in Application class
	newWorld.lock()->spawnActor<Actor>();
	actorToDestroy = newWorld.lock()->spawnActor<Actor>();
	actorToDestroy.lock()->setTexture(GetResourceFolder() + "SpaceShooterRedux/PNG/playerShip1_blue.png");
	counter = 0;

}

void LightYears::GameApplication::update(float deltaTime)
{
	counter += deltaTime;
	if (counter > 2.f)
	{
		if (!actorToDestroy.expired())
		{
			actorToDestroy.lock()->destroy();
		}
	}
}
