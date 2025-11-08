#include <box2d/b2_body.h>
#include "framework/Actor.h"
#include"framework/Core.h"
#include "framework/AssetManager.h"
#include "framework/PhysicsSystem.h"
namespace LightYears
{
	Actor::Actor(Level* owningLevel, const std::string& texturePath) :
		mBeginPlay(false),
		mOwningLevel(owningLevel),
		mSprite(),
		mTexture(),
		mPhysicsbody{nullptr},
		mPhysicsEnabled{false}
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
		centerPivot();
	}
	void Actor::render(sf::RenderWindow& window)
	{
		if (isPendingDestroy())
			return;
		window.draw(mSprite);
	}
	void Actor::setActorLocation(const sf::Vector2f newLoc)
	{
		mSprite.setPosition(newLoc);
		updatePhysicsBodyTransform();
	}
	void Actor::setActorRotation(float newRot)
	{
		mSprite.setRotation(newRot);
		updatePhysicsBodyTransform();
	}

	void Actor::addActorLocationOffset(const sf::Vector2f& offsetAmnt)
	{
		setActorLocation(getActorLocation() + offsetAmnt);
	}

	void Actor::addActorRotationOffset(float offsetAmnt)
	{
		setActorRotation(getActorRotation() + offsetAmnt);
	}

	sf::Vector2f Actor::getActorLocation() const
	{
		return mSprite.getPosition();
	}

	float Actor::getActorRotation() const
	{
		return mSprite.getRotation();
	}

	sf::Vector2f Actor::getActorforwardDirection() 
	{
		return RotationToVector(getActorRotation());
	}

	sf::Vector2f Actor::getActorRightDirection()
	{
		return RotationToVector(getActorRotation() + 90.f);
	}

	sf::Vector2u Actor::getwindowSize() const
	{
		return mOwningLevel->getwindowSize();
	}

	Level* Actor::getLevel() const
	{
		return mOwningLevel;
	}

	void Actor::initializePhysics()
	{
		if (!mPhysicsbody)
			mPhysicsbody = PhysicsSystem::get().addListener(this);
	}

	void Actor::unInitializePhysics()
	{
		if (mPhysicsbody)
			PhysicsSystem::get().removeListener(mPhysicsbody);
	}


	void Actor::setEnablePhysics(bool enablePhysics)
	{
		mPhysicsEnabled = enablePhysics;
		if (mPhysicsEnabled)
			initializePhysics();
		else
			unInitializePhysics();
	}

	void Actor::onActorBeginOverlap(Actor* other)
	{
		LOG("OVERLAPPED");
	}

	void Actor::onActorEndOverlap(Actor* other)
	{
		LOG("OVERLAP FINISHED");
	}

	void Actor::centerPivot()
	{
		sf::FloatRect bound = mSprite.getGlobalBounds();
		mSprite.setOrigin(bound.width / 2, bound.height / 2);
	}
	void Actor::updatePhysicsBodyTransform()
	{
		if (mPhysicsbody)
		{
			float physicsScale = PhysicsSystem::get().getPhysicsScale();
			b2Vec2 pos{ getActorLocation().x * physicsScale, getActorLocation().y * physicsScale };
			float rotation = DegreesToRadians(getActorRotation());
			mPhysicsbody->SetTransform(pos, rotation);
		}
	}
	bool Actor::isActorOutOfBounds() const
	{
		float windowWidth = getLevel()->getwindowSize().x;
		float windowHeight = getLevel()->getwindowSize().y;

		float width = getActorGlobalBounds().width;
		float height = getActorGlobalBounds().height;

		sf::Vector2f actorPos = getActorLocation();
		if (actorPos.x < -width)
			return true;
		if (actorPos.x > windowWidth + width)
			return true;
		if (actorPos.y < -height)
			return true;
		if (actorPos.y > windowHeight + height)
			return true;
		return false;

	}

	sf::FloatRect Actor::getActorGlobalBounds() const
	{
		return mSprite.getGlobalBounds();
	}


	
}