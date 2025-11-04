#ifndef SHOOTER_CPP
#define SHOOTER_CPP
namespace LightYears
{
	class Actor;
	class Shooter
	{
	public:
		void Shoot();

		virtual bool canShoot() const;
		virtual bool isOnCoolDown() const;
		Actor* GetOwner() const;
	protected:
		Shooter(Actor* owner);
	private:
		virtual void  shootImpl() = 0;
		Actor* mOwner;
	};
}
#endif // !SHOOTER_CPP
