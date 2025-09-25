#ifndef APPLICATION_HPP
#define APPLICATION_HPP
#include<SFML/Graphics.hpp>
#include "framework/Core.h"
namespace LightYears
{
	class Level;
	class Application
	{
	public:
		Application();
		void run();
		template<typename LevelType>
		weak<LevelType> loadLevel();
	private:
		void updateInternal(float deltaTime);
		void renderInternal();

		void virtual update(float deltaTime);
		void virtual render();
		float mTargetFrameRate;
		sf::RenderWindow mWindow;
		sf::Clock mClock;
		shared<Level> mCurrentLevel;
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