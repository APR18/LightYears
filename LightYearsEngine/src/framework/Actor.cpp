#include "framework/Actor.h"
#include"framework/Core.h"

namespace LightYears
{
	Actor::Actor(Level* owningLevel, const std::string& texturePath) :
		mBeginPlay(false),
		mOwningLevel(owningLevel),
		mSprite(),
		mTexture()

	{
		setTexture(texturePath);
	}
	Actor::~Actor()
	{
		LOG("Actor Destroyed");
	}
	void Actor::beginPlayInternal()
	{
		if (!mBeginPlay)
		{
			mBeginPlay = true;
			beginPlay();
		}
	}

	void Actor::beginPlay()
	{
		LOG("Actor begin play");
	}
	void Actor::updateInternal(float deltaTime)
	{
		if (!isPendingDestroy())
		{
			update(deltaTime);
		}
	}
	void Actor::update(float deltaTime)
	{
		LOG("Actor Ticking now");
	}
	void Actor::setTexture(const std::string& texturePath)
	{
		mTexture.loadFromFile(texturePath);
		mSprite.setTexture(mTexture);
		int textureWidth = mTexture.getSize().x;
		int textureHeight = mTexture.getSize().y;
		mSprite.setTextureRect(sf::IntRect(sf::Vector2i(), sf::Vector2i(textureWidth, textureHeight)));
	}
	void Actor::render(sf::RenderWindow& window)
	{
		if (isPendingDestroy())
			return;
		window.draw(mSprite);
	}
}