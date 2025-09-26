#include "framework/Level.h"
#include "framework/Actor.h"
namespace LightYears
{
	Level::Level(Application* owningApp):
		mOwningApp{owningApp},mBeginPlay{false},
		mPendingActors(),
		mActors()
	{

	}

	void Level::beginPlayInternal()
	{
		if (!mBeginPlay)
		{
			mBeginPlay = true;
			beginPlay();
		}
	}

	void Level::updateInternal(float deltaTime)
	{
		//transferring the actors from pending to actual actor list
		for (shared<Actor> actor : mPendingActors)
		{
			mActors.push_back(actor);
			actor->beginPlayInternal();
		}
		mPendingActors.clear();

		// updating each actor
		for (shared<Actor> actor : mActors)
		{
			actor->update(deltaTime);
		}

		update(deltaTime);
	}

	void Level::beginPlay()
	{
		LOG("Begin Play");
	}

	void Level::update(float deltaTime)
	{
		LOG("Updating at framerate: %f", 1.f / deltaTime);
	}

	Level::~Level()
	{

	}

}


