#include "framework/World.h"
#include"framework/Core.h"
namespace ly 
{
	World::World(Application* owningApp)
		:mowningAPP{owningApp},mbeganPlay{false}
	{

	}
	void World::beginPlayInternal()
	{
		if (!mbeganPlay) 
		{
			mbeganPlay = true;
			beginPlay();
		}
	}
	void World::tickInternal(float deltaTime)
	{
	}
	World::~World()
	{
	}
	void World::beginPlay()
	{
		LOG("Began play");
	}
	void World::tick(float deltaTime)
	{
		LOG("Tick at the frame rate %f", 1.f / deltaTime);
	}
}

