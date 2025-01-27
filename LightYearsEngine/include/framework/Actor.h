#pragma once
#include "framework/Core.h"
#include "framework/Object.h"
#include <SFML/Graphics.hpp>
namespace ly
{
	class World;
	class Actor : public Object
	{
	public:
		Actor(World* owningWorld,const std::string& texturePath = "");
		virtual ~Actor();
		void beginPlayInternal();
		virtual void beginPlay();
		void tickInternal(float deltaTime);
		virtual void tick(float deltaTime);
		void setTexture(const std::string& texturePath);
		void render(sf::RenderWindow& window);

	private:
		World* mOwningWorld;
		bool mBeganPlay;
		sf::Sprite mSprite;
		shared<sf::Texture> mTexture;
	};
}