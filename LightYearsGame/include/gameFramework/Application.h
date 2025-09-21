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
	private:
		sf::RenderWindow mWindow;
	};
}
#endif