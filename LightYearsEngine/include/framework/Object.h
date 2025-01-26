#pragma once

namespace ly
{
	class Object
	{
	public:
		Object();
		virtual ~Object();

		bool isPendingDestroy() const 
		{
			return mIsPendingDestroy;
		}
		void destroy();
	private:
		bool mIsPendingDestroy;
	};
}