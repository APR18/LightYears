#ifndef ACTOR_HPP
#define ACTOR_HPP
namespace LightYears
{
	class Level;
	class Actor
	{
	public:
		Actor(Level* owningLevel);
		void beginPlayInternal();
		void beginPlay();
		virtual void update(float deltaTime);
	private:
		bool mBeginPlay;
		Level* mOwningLevel;

	};
}

#endif 