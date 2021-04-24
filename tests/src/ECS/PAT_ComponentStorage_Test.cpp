/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PAT_ComponentStorage_Test.cpp
*  Purpose:
*  Creation Date: 13-03-21
*  Created By: Andrea Andreu Salvagnin
*/


#include "catch.hpp"
#include "PAT_ComponentStorage.hpp"
#include "PAT_Component.hpp"

TEST_CASE("Instantiate a component storage", "[ecs]")
{
	ECS::PAT_ComponentStorage component_storage(5);

	struct TestComponentCS : public ECS::PAT_Component<TestComponentCS>
	{
		TestComponentCS(ECS::EntityID eid) : PAT_Component(eid){ }
	};

	WHEN("a base component storage is instantiated")
	{
	        TestComponentCS& component =
			component_storage.CreateComponent<TestComponentCS>(777);

		THEN("it's possible to create a component inside it and retrieve it")
		{
			REQUIRE(component.GetComponentTypeID() != 0);
		}

		THEN("it's possible to delete an added compoent")
		{
			component_storage.
				DeleteEntityComponent(component.GetComponentTypeID(),
				component.GetEnityID());

			ECS::Vector<TestComponentCS> vector =
				component_storage.GetComponents<TestComponentCS>();

			REQUIRE(vector.Size() == 0);
		}
	}
}

