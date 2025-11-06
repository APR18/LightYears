
#include "framework/Application.h"
#include"framework/Core.h"
#include"framework/Level.h"
namespace LightYears
{
	Application::Application(unsigned int windowWidth, unsigned int windowHeight, const std::string& title, sf::Uint32 style) :
		mWindow(sf::VideoMode(windowWidth, windowHeight), title,style),
		mTargetFrameRate(60.f),
		mClock(),
		mCurrentLevel(nullptr),
		mCleanCycleClock(),
		mCleanCycleInterval(2.f)
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

	sf::Vector2u Application::getWindowSize() const
	{
		return mWindow.getSize();
	}

	void Application::updateInternal(float deltaTime)
	{
		update(deltaTime);
		if (mCurrentLevel)
		{
			mCurrentLevel->beginPlayInternal();
			mCurrentLevel->updateInternal(deltaTime);
		}
		if (mCleanCycleClock.getElapsedTime().asSeconds()>=mCleanCycleInterval)
		{
			mCleanCycleClock.restart();
			AssetManager::Get().cleanCycle();
			if (mCurrentLevel)
				mCurrentLevel->cleanCycle();
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
		if (mCurrentLevel)
			mCurrentLevel->render(mWindow);

	}



}
