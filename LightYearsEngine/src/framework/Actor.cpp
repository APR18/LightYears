#include "framework/Actor.h"
#include"framework/Core.h"
#include "framework/AssetManager.h"

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
		
	}
	void Actor::setTexture(const std::string& texturePath)
	{
		mTexture = AssetManager::Get().loadTexture(texturePath);
		if (!mTexture)
			return;
		mSprite.setTexture(*mTexture);
		int textureWidth = mTexture->getSize().x;
		int textureHeight = mTexture->getSize().y;
		mSprite.setTextureRect(sf::IntRect(sf::Vector2i(), sf::Vector2i(textureWidth, textureHeight)));
	}
	void Actor::render(sf::RenderWindow& window)
	{
		if (isPendingDestroy())
			return;
		window.draw(mSprite);
	}
}