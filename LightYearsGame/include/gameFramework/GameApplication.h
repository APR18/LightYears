#include "framework/Application.h"
#include "framework/Core.h"
namespace LightYears
{
	class Actor;
	class GameApplication : public Application
	{
	public:
		GameApplication();
		virtual void update(float deltaTime) override;
	private:
		float counter;
		weak<Actor> actorToDestroy;
	};
}