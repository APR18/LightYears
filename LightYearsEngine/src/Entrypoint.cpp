#include "Entrypoint.h"

int main()
{
	LightYears::Application* app = GetApplication();
	app->run();
	delete app;
}