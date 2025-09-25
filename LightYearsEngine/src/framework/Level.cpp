#include "framework/Level.h"
#include "framework/Core.h"
namespace LightYears
{
	Level::Level(Application* owningApp):
		mOwningApp{owningApp},mBeginPlay{false}
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


