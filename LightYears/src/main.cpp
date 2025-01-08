#include <iostream>
#include<memory>
#include<framework/Application.h>
#include<SFML/Graphics.hpp>
int main()
{
	std::unique_ptr<ly::Application> app = std::make_unique<ly::Application>();
	app->run();
}