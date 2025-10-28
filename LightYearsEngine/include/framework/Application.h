#ifndef APPLICATION_HPP
#define APPLICATION_HPP
#include<SFML/Graphics.hpp>
#include "framework/Core.h"
#include "AssetManager.h"
namespace LightYears
{
	class Level;
	class Application
	{
	public:
		Application(unsigned int windowWidth, unsigned int windowHeight, const std::string& title, sf::Uint32 style);
		void run();
		template<typename LevelType>
		weak<LevelType> loadLevel();
		sf::Vector2u getWindowSize() const;
	private:
		void updateInternal(float deltaTime);
		void renderInternal();

		void virtual update(float deltaTime);
		void virtual render();
		float mTargetFrameRate;
		sf::RenderWindow mWindow;
		sf::Clock mClock;
		shared<Level> mCurrentLevel;
		sf::Clock mCleanCycleClock;
		float mCleanCycleInterval;
	};

	template<typename LevelType>
	weak<LevelType> Application::loadLevel()
	{
		shared<LevelType> newLevel{ new Level(this) };
		mCurrentLevel = newLevel;
		return newLevel;
	}
}
#endif