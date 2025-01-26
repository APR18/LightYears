#include "framework/Actor.h"

namespace ly
{
	Actor::Actor(World* owningWorld, const std::string& texturePath ) :
		mOwningWorld{owningWorld},mBeganPlay{false}
	{
		setTexture(texturePath);
	}
	Actor::~Actor()
	{
		LOG("Actor Destroyed");
	}
	void Actor::beginPlayInternal()
	{
		if (!mBeganPlay)
		{
			mBeganPlay = true;
			beginPlay();
		}
	}
	void Actor::beginPlay()
	{
		LOG("Actor Begin play");
	}
	void Actor::tickInternal(float deltaTime)
	{
		if (!isPendingDestroy())
		{
			tick(deltaTime);
		}
	}
	void Actor::tick(float deltaTime)
	{
		LOG("Actor Ticking");
	}
	void Actor::setTexture(const std::string& texturePath)
	{
		mTexture.loadFromFile(texturePath);
		mSprite.setTexture(mTexture);

		int textureWidth = mTexture.getSize().x;
		int textureHeight = mTexture.getSize().y;
		mSprite.setTextureRect(sf::IntRect{ sf::Vector2i{},sf::Vector2i{textureWidth,textureHeight} });
	}
	void Actor::render(sf::RenderWindow& window)
	{
		if (isPendingDestroy())
			return;
		window.draw(mSprite);
	}
}
