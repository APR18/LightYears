#ifndef APPLICATION_HPP
#define APPLICATION_HPP
#include<SFML/Graphics.hpp>
namespace LightYears
{
	class Application
	{
	public:
		Application();
		void run();
		void updateInternal(float deltaTime);
		void virtual update(float deltaTime);
		void renderInternal();
		void virtual render();
	private:
		float mTargetFrameRate;
		sf::RenderWindow mWindow;
		sf::Clock mClock;

	};
}
#endif