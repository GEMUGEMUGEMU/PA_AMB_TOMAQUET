/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PAT_ComponentStorage.hpp
*  Purpose: Store and manage components
*  Creation Date: 26-02-21
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef PAT_ComponentStorage_hpp
#define PAT_ComponentStorage_hpp

#include "PAT_ComponentVector.hpp"

namespace ECS
{

struct PAT_ComponentStorage
{
	explicit PAT_ComponentStorage(std::size_t InitialSize) :
		mInitialSize(InitialSize) { }


	PAT_ComponentStorage(const PAT_ComponentStorage&) = delete;
	PAT_ComponentStorage(const PAT_ComponentStorage&&) = delete;
	PAT_ComponentStorage& operator=(const PAT_ComponentStorage&) = delete;
	PAT_ComponentStorage& operator=(const PAT_ComponentStorage&&) = delete;


	template <typename ComponentType>
	ComponentType& CreateComponent(EntityID eid)
	{
		auto& r_comp_vector = GetComponents<ComponentType>();
		auto& r_comp = r_comp_vector.emplace_back(eid);
		return r_comp;
	}

	template <typename ComponentType>
	Vector<ComponentType>& CreateComponentVector()
	{
		auto up_comp_vector =
			std::make_unique<PAT_ComponentVector<ComponentType>>();
		up_comp_vector->mComponentVector.reserve(mInitialSize);
		auto* p_comp_vector = up_comp_vector.get();

		auto type_id = ComponentType::GetComponentTypeID();
		mComponentVectorsMap[type_id] = std::move(up_comp_vector);
		return p_comp_vector->mComponentVector;
	}

	template <typename Component>
	Vector<Component>& GetComponents()
	{
		Vector<Component>* comp_vector { nullptr };
		auto comp_type_id = Component::GetComponentTypeID();
		auto iterator = mComponentVectorsMap.find(comp_type_id);


		if( iterator != mComponentVectorsMap.end() )
		{
			auto* p_component_vector =
				dynamic_cast<PAT_ComponentVector<Component>*>
					(iterator->second.get());
//TODO: check if null
			comp_vector = &(p_component_vector->mComponentVector);
		}
		else
		{
			comp_vector = &CreateComponentVector<Component>();
		}

		return *comp_vector;
	}

	template <typename ComponentType>
	const Vector<ComponentType>& GetComponents() const
	{
		Vector<ComponentType> p_comp_vec{nullptr};
		auto type_id = ComponentType::GetComponentTypeID();
		auto iterator = mComponentVectorsMap.find(type_id);

		if(iterator != mComponentVectorsMap.end())
		{
			auto* p_vec_cast =
				dynamic_cast<PAT_ComponentVector<ComponentType>*>
					(iterator->second.get());
			p_comp_vec = &(p_vec_cast->mComponents);
		}
		else
		{
			throw ("error");
		}

		return *p_comp_vec;
	}

	// Delete a component by it's type ID and entity ID
	void DeleteEntityComponent(ComponentTypeID compTypeID, EntityID eID)
	{
		auto it = mComponentVectorsMap.find(compTypeID);
		if ( it == mComponentVectorsMap.end()) return; //TODO: manage errors

		auto comp_vector { it->second.get() };
		comp_vector->DeleteComponentByEntityID(eID);
	}

private:
	UMap<ComponentTypeID, UPtr<PAT_ComponentVectorBase>>
		mComponentVectorsMap;
	std::size_t mInitialSize { 100 };
};

}
#endif /* PAT_ComponentStorage_hpp */
