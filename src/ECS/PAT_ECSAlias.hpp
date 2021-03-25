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

#include <memory>
#include "PAT_UnorderedMap.hpp"
#include "PAT_Vector.hpp"

namespace ECS
{

template<typename T>
using Vector = PAT_Vector<T>;

template<typename Key, typename Value>
using UMap = PAT_UnorderedMap<Key, Value>;

template<typename T>
using UPtr= std::unique_ptr<T>;

using EntityID = std::size_t;
using ComponentID = std::size_t;
using ComponentTypeID = std::size_t;

using VecEntities = PAT_Vector<EntityID>;

}

#endif /* PAT_ECSAlias_hpp */
