#include<iostream>
#include<memory>
#include <SFML/Graphics.hpp>

#include "gameFramework/Application.h"

int main()
{
	std::unique_ptr<LightYears::Application> app = std::make_unique<LightYears::Application>();
	app->run();

}