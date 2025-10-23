#ifndef ACTOR_HPP
#define ACTOR_HPP
#include<SFML/Graphics.hpp>
#include "framework/Object.h"
#include "framework/Core.h"
#include "MathUtility.h"
namespace LightYears
{
	
	class Level;
	class Actor:public Object
	{
	public:
		Actor(Level* owningLevel,const std::string& texturePath = "");
		virtual ~Actor();
		void beginPlayInternal();
		void beginPlay();
		void updateInternal(float deltaTime);
		virtual void update(float deltaTime);
		void setTexture(const std::string& texturePath);
		void render(sf::RenderWindow& window);
		
		void setActorLocation(const sf::Vector2f newLoc);
		void setActorRotation(float newRot);
		void addActorLocationOffset(const sf::Vector2f& offsetAmnt);
		void addActorRotationOffset(float offsetAmnt);
		sf::Vector2f getActorLocation();
		float getActorRotation();
		sf::Vector2f getActorforwardDirection();
		sf::Vector2f getActorRightDirection();
	private:
		void centerPivot();
		bool mBeginPlay;
		Level* mOwningLevel;
		sf::Sprite mSprite;
		shared <sf::Texture> mTexture;
	};
}

#endif 