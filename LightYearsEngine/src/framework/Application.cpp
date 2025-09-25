
#include "framework/Application.h"
#include"framework/Core.h"
#include"framework/Level.h"
namespace LightYears
{
	Application::Application() :
		mWindow(sf::VideoMode(800, 640), "LightYears"),
		mTargetFrameRate(60.f),
		mClock(),
		mCurrentLevel(nullptr)
	{ }

	void Application::run()
	{
		mClock.restart();
		float timePassedSinceLastUpdate = 0.f;
		float targetDeltaTime = 1.f / mTargetFrameRate;
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
			float accumulatedTime = mClock.restart().asSeconds();
			timePassedSinceLastUpdate += accumulatedTime;
			while (timePassedSinceLastUpdate > targetDeltaTime)
			{
				timePassedSinceLastUpdate -= targetDeltaTime;
				updateInternal(targetDeltaTime);
				renderInternal();
				
			}
			
			//printf("Updateing at framerate: %f\n", 1.f / accumulatedTime);
			//LOG("Updateing at framerate: %f\n", 1.f / accumulatedTime);

		}
	}

	void Application::updateInternal(float deltaTime)
	{
		update(deltaTime);
		if (mCurrentLevel)
		{
			mCurrentLevel->beginPlayInternal();
			mCurrentLevel->updateInternal(deltaTime);
		}

	}

	void Application::update(float deltaTime)
	{
		//std::cout << "Updating at framerate: " << 1.f/deltaTime <<std::endl;
	}

	void Application::renderInternal()
	{
		mWindow.clear();
		render();
		mWindow.display();
	}

	void Application::render()
	{
		
		sf::CircleShape circle{ 50.f };
		circle.setFillColor(sf::Color::Cyan);
		circle.setOrigin(50, 50);
		circle.setPosition(mWindow.getSize().x/2, mWindow.getSize().y/2);
		mWindow.draw(circle);

	}



}
