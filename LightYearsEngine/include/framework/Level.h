#ifndef LEVEL_HPP
#define LEVEL_HPP


namespace LightYears
{
	class Application;
	class Level
	{
	public:
		Level(Application* owningApp);
		void beginPlayInternal();
		void updateInternal(float deltaTime);
		 virtual  ~Level();
	private:
		Application* mOwningApp;
		bool mBeginPlay;
		void beginPlay();
		void update(float deltaTime);
	};
}
#endif // !LEVEL_HPP
