#pragma once

namespace ly
{
	class Application;
	class World 
	{
	public:
		World(Application* owningApp);
		void beginPlayInternal();
		void tickInternal(float deltaTime);
		virtual ~World();

	private:
		void beginPlay();
		void tick(float deltaTime);
		Application* mowningAPP;
		bool mbeganPlay;

	};
}