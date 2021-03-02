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
#include "PAT_Component.hpp"

TEST_CASE("Instantiate a base component", "[ecs]")
{
	struct TestComponentA : public ECS::PAT_Component<TestComponentA>
	{
		TestComponentA() : PAT_Component(777){ }
	};

	WHEN("a base component is instantiated")
	{
		ECS::ComponentTypeID comp_type =
			TestComponentA::GetComponentTypeID();
		ECS::ComponentTypeID comp_type1 =
			TestComponentA::GetComponentTypeID();
		ECS::ComponentTypeID comp_type2 =
			TestComponentA::GetComponentTypeID();


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
	struct TestComponent : public ECS::PAT_Component<TestComponent>
	{
		TestComponent() : PAT_Component(777){ }
	};


	struct TestComponent1 :
		public ECS::PAT_Component<TestComponent1>
	{
		TestComponent1() : PAT_Component(777){ }
	};

	struct TestComponent2 :
		public ECS::PAT_Component<TestComponent2>
	{
		TestComponent2() : PAT_Component(777){ }
	};


	ECS::ComponentTypeID comp_type =
		TestComponent::GetComponentTypeID();
	ECS::ComponentTypeID comp_type1 =
		TestComponent1::GetComponentTypeID();
	ECS::ComponentTypeID comp_type2 =
		TestComponent2::GetComponentTypeID();



	WHEN("different base components are instantiated")
	{
		THEN("Component ID is different for every new component type")
		{
			REQUIRE(comp_type != comp_type1);

			REQUIRE(comp_type2 != comp_type);

			REQUIRE(comp_type2 != comp_type1);
		}
	}
}
