#include "framework\Application.h"
#include<framework/Core.h>
namespace ly
{

	Application::Application(unsigned int windowWidth, unsigned int windowHeight, const std::string& title, sf::Uint32 style)
		:mWindow{ sf::VideoMode(windowWidth,windowHeight), title, style },
		mTargetFrameRate{ 60.f },
		mTickClock{},
		currentWorld{ nullptr }
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
		if (currentWorld)
		{
			currentWorld->render(mWindow);
		}
	}
	void Application::tick(float deltaTime)
	{
		LOG("Ticking at framerate: %f", 1.f / deltaTime);
	}
}

