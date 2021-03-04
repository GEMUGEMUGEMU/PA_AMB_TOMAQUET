/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PAT_Entity_Test.cpp
*  Purpose:
*  Creation Date: 28-02-21
*  Created By: Andrea Andreu Salvagnin
*/


#include "catch.hpp"
#include "PAT_Entity.hpp"
#include "PAT_BaseComponent.hpp"

TEST_CASE("Instantiate an entity", "[ecs]")
{
        ECS::PAT_Entity entity;
}

TEST_CASE("Add an attribute to an entity", "[ecs]")
{
        ECS::PAT_Entity entity;

	struct TestComponent : public ECS::PAT_BaseComponent<TestComponent>
	{
		TestComponent(ECS::ComponentTypeID cid) : PAT_BaseComponent(cid){ }
	};

	WHEN("a componet is added to an entity")
	{

	}


}
