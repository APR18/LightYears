#include "gameFramework/GameApplication.h"
#include "framework/Level.h"
#include "framework/Actor.h"
#include "config.h"
#include "framework/AssetManager.h"
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
}

void LightYears::GameApplication::update(float deltaTime)
{
	
}
