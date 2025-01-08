#pragma once
#include <SFML/Graphics.hpp>
namespace ly
{
	class Application
	{
	public:
		Application();
		void run();
	private:
		sf::RenderWindow mWindow;
		float mTargetFrameRate;
		sf::Clock mTickClock;

		void tickInternal(float deltaTime);
		void renderInternal();

		void virtual render();
		void virtual tick(float deltaTime);
	};
}