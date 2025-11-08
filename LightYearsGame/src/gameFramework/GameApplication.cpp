#include "config.h"
#include "framework/Level.h"
#include "framework/Actor.h"
#include "framework/AssetManager.h"
#include "gameFramework/GameApplication.h"

LightYears::Application* GetApplication()
{
	return new LightYears::GameApplication();
}
// This function loads the levels and actors before the Application::run() function is called from the Entrypoint.h file
LightYears::GameApplication::GameApplication()
	:Application(600,980,"Light Years",sf::Style::Titlebar|sf::Style::Close)
{
	AssetManager::Get().setAssetRootDir(GetResourceFolder());
	weak<Level> newWorld = loadLevel<Level>(); // loadLevel is a function in Application 
	testSpaceship = newWorld.lock()->spawnActor<PlayerSpaceship>();
	testSpaceship.lock()->setActorLocation(sf::Vector2f(300, 490));
	testSpaceship.lock()->setActorRotation(-90);
	weak<Spaceship> testSpaceship2 = newWorld.lock()->spawnActor<Spaceship>();
	testSpaceship2.lock()->setTexture("SpaceShooterRedux/PNG/playerShip1_blue.png");
	testSpaceship2.lock()->setActorLocation(sf::Vector2f(100.f, 50.f));
}

void LightYears::GameApplication::update(float deltaTime)
{
	
}
