#ifndef ASSET_MANAGER_HPP
#define ASSET_MANAGER_HPP

#include <SFML/Graphics.hpp>
#include "framework/Core.h"
namespace LightYears
{
	class AssetManager
	{
	public:
		static AssetManager& Get();
		shared<sf::Texture> loadTexture(const std::string& filepath);
		void cleanCycle();
		void setAssetRootDir(const std::string& rootDir);
	protected:
		AssetManager();
	private:
		static unique<AssetManager> assetmanager;
		dictionary<std::string, shared<sf::Texture>> mLoadedTextureMap;
		std::string mAssetRootDir;
	};
}
#endif // !ASSET_MANAGER_HPP
