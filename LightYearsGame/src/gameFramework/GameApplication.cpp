#include "gameFramework/GameApplication.h"
#include "framework/Level.h"
LightYears::Application* GetApplication()
{
	return new LightYears::GameApplication();
}

LightYears::GameApplication::GameApplication()
{
	loadLevel<Level>();
}
