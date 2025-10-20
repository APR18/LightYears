#include "framework/Object.h"

#include "framework/Object.h"
#include "framework/Core.h"
namespace LightYears
{

	Object::Object() :mIspendingDestroy{ false }

	{
	}

	Object::~Object()
	{
		LOG("Object Destroyed");
	}

	void Object::destroy()
	{
		mIspendingDestroy = true;
	}

	bool Object::isPendingDestroy() const
	{
		return mIspendingDestroy;
	}
}
