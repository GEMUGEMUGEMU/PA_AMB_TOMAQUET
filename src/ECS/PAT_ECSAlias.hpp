/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PAT_ECSAlias.hpp
*  Purpose:
*  Creation Date: 28-02-21
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef PAT_ECSAlias_hpp
#define PAT_ECSAlias_hpp

#include <vector>
//#include <unordered_map>
#include <memory>
#include "PAT_UnorderedMap.hpp"

namespace ECS
{

template<typename T>
using Vector = std::vector<T>;

template<typename Key, typename Value>
//using UMap = std::unordered_map<Key, Value>;
using UMap = PAT_UnorderedMap<Key, Value>;

template<typename T>
using UPtr= std::unique_ptr<T>;

using EntityID = std::size_t;
using ComponentID = std::size_t;
using ComponentTypeID = std::size_t;

using VecEntities = std::vector<EntityID>;

}

#endif /* PAT_ECSAlias_hpp */
