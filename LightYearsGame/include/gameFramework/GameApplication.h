#include "framework/Application.h"
#include "framework/Core.h"
#include "player/PlayerSpaceship.h"
namespace LightYears
{
	class Actor;
	class GameApplication : public Application
	{
	public:
		GameApplication();
		virtual void update(float deltaTime) override;
	private:
		
		weak<PlayerSpaceship> testSpaceship;
	};
}