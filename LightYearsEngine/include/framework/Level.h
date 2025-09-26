#ifndef LEVEL_HPP
#define LEVEL_HPP
#include "Core.h"

namespace LightYears
{
	class Application;
	class Actor;
	class Level
	{
	public:
		Level(Application* owningApp);
		void beginPlayInternal();
		void updateInternal(float deltaTime);
		 virtual  ~Level();
		 template<typename ActorType>
		 weak<ActorType> spawnActor();

	private:
		Application* mOwningApp;
		bool mBeginPlay;
		void beginPlay();
		void update(float deltaTime);
		list<shared<Actor>> mActors;
		list<shared<Actor>> mPendingActors;
	};

	template<typename ActorType>
	weak<ActorType> Level::spawnActor()
	{
		shared<ActorType> newActor{ new ActorType{ this } };
		mPendingActors.push_back(newActor);
		return newActor;
	}
}

#endif // !LEVEL_HPP
