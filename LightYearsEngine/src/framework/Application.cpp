#include "framework\Application.h"
#include<framework/Core.h>
namespace ly
{
	Application::Application()
		:mWindow{sf::VideoMode(600,800), "Light Years"},
		mTargetFrameRate{60.f},
		mTickClock{},
		currentWorld{nullptr}
	{
		
	}
	void Application::run()
	{
		mTickClock.restart();
		float accumulatedTime = 0.f;
		float targetDeltaTime = 1.f / mTargetFrameRate;
		while (mWindow.isOpen())
		{
			sf::Event windowEvent;
			while (mWindow.pollEvent(windowEvent))
			{
				if (windowEvent.type == sf::Event::EventType::Closed)
				{
					mWindow.close();
				}
			}
			// this not only restarts the clock but also returns the amount of time passed
			accumulatedTime += mTickClock.restart().asSeconds(); // increases the accumulated time 
			while (accumulatedTime > targetDeltaTime) // when the accumulated time is greater than the delta time
			{
				// it subracts the targetDeltaTime so that it resets for the next frame to be rendered
				accumulatedTime -= targetDeltaTime;
				tickInternal(targetDeltaTime);
				renderInternal();
			}
		}
	}
	void Application::tickInternal(float deltaTime)
	{
		tick(deltaTime);
		if (currentWorld)
		{
			currentWorld->beginPlayInternal();
			currentWorld->tickInternal(deltaTime);
		}
	}

	void Application::renderInternal()
	{
		mWindow.clear();
		render();
		mWindow.display();
	}
	void Application::render()
	{
		sf::CircleShape circle{ 50 };
		circle.setFillColor(sf::Color::Magenta);
		circle.setOrigin(50, 50);
		circle.setPosition(mWindow.getSize().x / 2, mWindow.getSize().y / 2);
		mWindow.draw(circle);
	}
	void Application::tick(float deltaTime)
	{
		LOG("Ticking at framerate: %f", 1.f / deltaTime);
	}
}

