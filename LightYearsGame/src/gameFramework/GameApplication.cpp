#include "gameFramework/GameApplication.h"
#include "framework/Level.h"
#include "framework/Actor.h"
LightYears::Application* GetApplication()
{
	return new LightYears::GameApplication();
}

LightYears::GameApplication::GameApplication()
{
	weak<Level> newWorld = loadLevel<Level>();
	newWorld.lock()->spawnActor<Actor>();
}
