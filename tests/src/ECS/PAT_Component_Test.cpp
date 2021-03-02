/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PAT_Component_Test.cpp
*  Purpose:
*  Creation Date: 02-03-21
*  Created By: Andrea Andreu Salvagnin
*/


#include "catch.hpp"
#include "PAT_BaseComponent.hpp"

TEST_CASE("Instantiate a base component", "[ecs]")
{
	struct TestComponentA : public ECS::PAT_BaseComponent<TestComponentA>
	{
		TestComponentA() : PAT_BaseComponent(777){ }
//		ECS::EntityID e_id {777};
	};

        TestComponentA component;

	ECS::ComponentTypeID comp_type = component.GetComponetTypeID();
	ECS::ComponentTypeID comp_type1 = component.GetComponetTypeID();
	ECS::ComponentTypeID comp_type2 = component.GetComponetTypeID();

	WHEN("a base component is instantiated")
	{
		THEN("it's Component type ID doesn't change")
		{
			REQUIRE(comp_type == comp_type1);
			REQUIRE(comp_type1 == comp_type2);
			REQUIRE(comp_type == comp_type2);
		}
	}

}

TEST_CASE("Instantiate more base component", "[ecs]")
{
	struct TestComponent : public ECS::PAT_BaseComponent<TestComponent>
	{
		TestComponent() : PAT_BaseComponent(777){ }
	};

	struct TestComponent1 : public ECS::PAT_BaseComponent<TestComponent1>
	{
		TestComponent1() : PAT_BaseComponent(777){ }
	};

	struct TestComponent2 : public ECS::PAT_BaseComponent<TestComponent2>
	{
		TestComponent2() : PAT_BaseComponent(777){ }
	};

        TestComponent component;
        TestComponent1 component1;
        TestComponent2 component2;

	WHEN("different base components are instantiated")
	{
		THEN("Component ID is different for every new component type")
		{
			REQUIRE(component.GetComponetTypeID() !=
				component1.GetComponetTypeID());

			REQUIRE(component1.GetComponetTypeID() !=
				component2.GetComponetTypeID());

			REQUIRE(component2.GetComponetTypeID() !=
				component.GetComponetTypeID());
		}
	}
}
