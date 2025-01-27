#pragma once
#include "framework/Core.h"
#include <SFML/Graphics.hpp>
namespace ly
{

	class AssetManager
	{
	public:
		static AssetManager& get();
		shared<sf::Texture> loadTexture(const std::string& path);
	protected:
		AssetManager();
	private:
		static unique<AssetManager> assetManager;
		Dictionary<std::string, shared<sf::Texture>> mLoadedTextureMap;
	};
}