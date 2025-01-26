#pragma once
#include <framework/Application.h>
#include "framework/Core.h"
namespace ly
{
	class Actor;
	class GameApplication : public Application
	{
	public:
		GameApplication();
		virtual void tick(float deltatime) override;

	private:
		float counter = 0;
		weak<Actor> actorToDestroy;

	};
}