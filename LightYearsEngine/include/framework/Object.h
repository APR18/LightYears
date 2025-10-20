#ifndef OBJECT_HPP
#define OBJECT_HPP
namespace LightYears
{
	class Object
	{
	public:
		Object();
		~Object();
		void destroy();
		bool isPendingDestroy() const;
	private:
		bool mIspendingDestroy;
	};
}
#endif 
