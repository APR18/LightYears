#ifndef ACTOR_HPP
#define ACTOR_HPP
#include<SFML/Graphics.hpp>
#include "framework/Object.h"
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
	private:
		bool mBeginPlay;
		Level* mOwningLevel;
		sf::Sprite mSprite;
		sf::Texture mTexture;
	};
}

#endif 