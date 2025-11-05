#ifndef LEVEL_HPP
#define LEVEL_HPP
#include "Core.h"
#include<SFML/Graphics.hpp>
#include "framework/Actor.h"
#include "Application.h"
namespace LightYears
{
	class Spaceship;
	class Actor;
	class Level
	{
	public:
		Level(Application* owningApp);
		void beginPlayInternal();
		void updateInternal(float deltaTime);
		void render(sf::RenderWindow& window);
		virtual  ~Level();
		template<typename ActorType, typename... Args>
		weak<ActorType> spawnActor(Args... args);
		sf::Vector2u getwindowSize();

	private:
		Application* mOwningApp;
		bool mBeginPlay;
		void beginPlay();
		void update(float deltaTime);
		list<shared<Actor>> mActors;
		list<shared<Actor>> mPendingActors;
	};

	template<typename ActorType, typename... Args>
	weak<ActorType> Level::spawnActor(Args... args)
	{
		shared<ActorType> newActor{ new ActorType{ this,args... } };
		mPendingActors.push_back(newActor);
		return newActor;
	}
}

#endif // !LEVEL_HPP
