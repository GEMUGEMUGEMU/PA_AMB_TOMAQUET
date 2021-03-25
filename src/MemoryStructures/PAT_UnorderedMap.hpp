/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PAT_UnorderedMap.hpp
*  Purpose: Adapter of std::unordered_map
*  Creation Date: 21-03-21
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef PAT_UnorderedMap_hpp
#define PAT_UnorderedMap_hpp

#include <unordered_map>

template <typename Key, typename Value>
struct PAT_UnorderedMap
{
	typedef std::unordered_map<Key, Value> UMap;

	PAT_UnorderedMap() :  mUnorderedMap() {};

	typename UMap::iterator Find(Key key)
	{
		return mUnorderedMap.find(key);
	}

	typename UMap::iterator End()
	{
		return mUnorderedMap.end();
	}

	const typename UMap::iterator End() const
	{
		return mUnorderedMap.end();
	}

	Value& operator[](Key key)
	{
		return mUnorderedMap[key];
	}

private:
	UMap mUnorderedMap;
};

#endif /* PAT_UnorderedMap_hpp */
