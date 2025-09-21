#include "gameFramework/Application.h"
namespace LightYears
{
	Application::Application():mWindow(sf::VideoMode(800,640),"LightYears")
	{ }

	void Application::run()
	{
		while (mWindow.isOpen())
		{
			sf::Event event;
			while (mWindow.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					mWindow.close();
				}
			}
		}
	}
}