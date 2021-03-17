/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PAT_ComponentVector.hpp
*  Purpose: Structure used for PAT_ComponentStorage
*  Creation Date: 26-02-21
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef PAT_ComponentVector_hpp
#define PAT_ComponentVector_hpp

#include "PAT_ECSAlias.hpp"
#include <algorithm>


namespace ECS
{

struct PAT_ComponentVectorBase
{
	virtual ~PAT_ComponentVectorBase() = default;
	virtual void DeleteComponentByEntityID(EntityID eID) = 0;
};

template <typename ComponentType>
struct PAT_ComponentVector : PAT_ComponentVectorBase
{
//	explicit PAT_ComponentVector();
	~PAT_ComponentVector() { };

	void DeleteComponentByEntityID(EntityID eID) override final
	{
//		TODO:Impove search
		auto iter =
			std::find_if( mComponentVector.begin(),
				mComponentVector.end(),
				[&eID](ComponentType& comp)
				{
					return comp.GetEnityID() == eID;
				});

		if( iter == mComponentVector.end()) return; //ERROR
		mComponentVector.erase(iter);
	}

	Vector<ComponentType> mComponentVector;
};

}

#endif /* PAT_ComponentVector_hpp */
