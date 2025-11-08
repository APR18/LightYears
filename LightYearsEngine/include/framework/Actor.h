#ifndef ACTOR_HPP
#define ACTOR_HPP
#include<SFML/Graphics.hpp>
#include "framework/Object.h"
#include "framework/Core.h"
#include "MathUtility.h"
#include "Level.h"
class b2Body;
namespace LightYears
{

	class Level;
	class Actor:public Object
	{
	public:
		Actor(Level* owningLevel,const std::string& texturePath = "");
		virtual ~Actor();
		void beginPlayInternal();
		virtual void beginPlay();
		void updateInternal(float deltaTime);
		virtual void update(float deltaTime);
		void setTexture(const std::string& texturePath);
		void render(sf::RenderWindow& window);
		void setActorLocation(const sf::Vector2f newLoc);
		void setActorRotation(float newRot);
		void addActorLocationOffset(const sf::Vector2f& offsetAmnt);
		void addActorRotationOffset(float offsetAmnt);
		sf::Vector2f getActorLocation() const;
		float getActorRotation() const;
		sf::Vector2f getActorforwardDirection();
		sf::Vector2f getActorRightDirection();
		sf::Vector2u getwindowSize() const;
		Level* getLevel() const;
		bool isActorOutOfBounds() const;
		sf::FloatRect getActorGlobalBounds() const;
		void initializePhysics();
		void unInitializePhysics();
		void setEnablePhysics(bool enablePhysics);
		virtual void onActorBeginOverlap(Actor* other);
		virtual void onActorEndOverlap(Actor* other);
	private:
		void centerPivot();
		void updatePhysicsBodyTransform();
		bool mBeginPlay;
		Level* mOwningLevel;
		sf::Sprite mSprite;
		shared <sf::Texture> mTexture;
		b2Body* mPhysicsbody;
		bool mPhysicsEnabled;
	};
}

#endif 