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

		// not incrementing here because the .erase returns the next iterator and in else we are incrementing it
		for (auto iter = mActors.begin(); iter != mActors.end();)
		{
			if (iter->get()->isPendingDestroy())
			{
				iter = mActors.erase(iter);
			}
			else
			{
				iter->get()->updateInternal(deltaTime);
				++iter;
			}
		}

		update(deltaTime);
	}
	void Level::render(sf::RenderWindow& window)
	{
		for (auto& actor : mActors)
			actor->render(window);
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


