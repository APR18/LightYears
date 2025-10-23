#include "framework/AssetManager.h"
#include <iostream>
namespace LightYears
{
	unique<AssetManager> AssetManager::assetmanager{ nullptr };
	AssetManager& AssetManager::Get()
	{
		if (!assetmanager)
		{
			// this is legal because we are inside the member function of a class ---- the constructor is accessible to the member function of the class
			assetmanager = unique<AssetManager>{ new AssetManager };
			// std::unique is not a member function or friend of the class AssetManager so it cannot call protected constructor of the AssetManager class
			//assetmanager = std::make_unique<AssetManager>();
		}
		return *assetmanager;
	}
	shared<sf::Texture> AssetManager::loadTexture(const std::string& filepath)
	{
		auto found = mLoadedTextureMap.find(filepath);
		if (found != mLoadedTextureMap.end())
		{
			return found->second;
		}
		//create a new texture and store it in the map or dictionary
		shared<sf::Texture> newTexture = std::make_shared<sf::Texture>();
		if (newTexture->loadFromFile(mAssetRootDir + filepath))
		{
			mLoadedTextureMap.insert({ filepath, newTexture });
			return newTexture;
		}

		return shared<sf::Texture>(nullptr);
	}

	void AssetManager::cleanCycle()
	{
		for (auto iter = mLoadedTextureMap.begin(); iter != mLoadedTextureMap.end();)
		{
			if (iter->second.unique())
			{
				LOG("Cleaning texture: %s " ,iter->first.c_str());
				iter = mLoadedTextureMap.erase(iter);
			}
			else
			{
				++iter;
			}
		}
	}

	void AssetManager::setAssetRootDir(const std::string& rootDir)
	{
		mAssetRootDir = rootDir;
	}

	

	AssetManager::AssetManager():
		mAssetRootDir{""}
	{
		
	}
}


