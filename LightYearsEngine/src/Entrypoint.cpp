#include "Entrypoint.h"

int main()
{
	LightYears::Application* app = GetApplication(); // things to take care of before the game loop
	app->run(); // game loop
	delete app;
}