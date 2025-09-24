
#ifndef CORE_HPP
#define CORE_HPP
#include<memory>
#include<map>
#include<stdio.h>
#include<unordered_map>

namespace LightYears
{
	template<typename T>
	using unique = std::unique_ptr<T>;

	template<typename T>
	using shared = std::shared_ptr<T>;

	template<typename T>
	using weak = std::weak_ptr<T>;

	template<typename T>
	using list = std::vector<T>;

	template<typename keyType, typename valType, typename Pr = std::less<keyType>>
	using map = std::map<keyType, valType, Pr>;


	template<typename keyType, typename valType, typename hasher = std::hash<keyType>>
	using dictionary = std::unordered_map<keyType, valType,hasher>;

	#define LOG(M, ...) printf(M "\n", ##__VA_ARGS__)
}

#endif