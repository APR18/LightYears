#pragma once
#include <SFML/Graphics.hpp>
#include"framework/Core.h"
#include "framework/World.h"

namespace ly
{
	class World;
	class Application
	{
	public:
		Application(unsigned int windowWidth, unsigned int windowHeight, const std::string& title,sf::Uint32 style);
		void run();


		// This function sets the currentWorld to the the world that has been passed to the template
		// so when the tickInternal inside the Application class is called it checks for currentWorld if it's there 
		// it calls the tickInternal inside it
		template<typename WorldType>
		weak<WorldType> loadWorld()
		{
			//creates a shared pointer named newWorld and passes a Application class reference to it
			shared<WorldType> newWorld{ new WorldType{this} };
			//sets the currentWorld of application class to the world that has been passed
			currentWorld = newWorld;
			return newWorld;
		}

	private:
		sf::RenderWindow mWindow;
		float mTargetFrameRate;
		sf::Clock mTickClock;

		void tickInternal(float deltaTime);
		void renderInternal();

		void virtual render();
		void virtual tick(float deltaTime);

		shared<World> currentWorld;
	};
}