#pragma once
#include "framework/Core.h"
#include <SFML/Graphics.hpp>
namespace ly
{
	class Actor;
	class Application;
	class World 
	{
	public:
		World(Application* owningApp);
		void beginPlayInternal();
		void tickInternal(float deltaTime);
		void render(sf::RenderWindow& window);
		virtual ~World();
		
/*This function creates a new actor and adds it to the mPending Actor list*/
		template<typename ActorType>
		weak<ActorType> spawnActor()
		{
			shared<ActorType> newActor{ new ActorType{this} };
			mPendingActors.push_back(newActor);
			return newActor;
		}




	private:
		void beginPlay();
		void tick(float deltaTime);
		Application* mOwningApp;
		bool mBeganPlay;
		List<shared<Actor>> mActors;
		// pending actors are created because if we update the actors list while we are looping 
		//through it, it would cause problems
		List<shared<Actor>> mPendingActors;

	};
}