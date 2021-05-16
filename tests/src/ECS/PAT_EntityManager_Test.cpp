/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PAT_EntityManager_Test.cpp
*  Purpose:
*  Creation Date: 13-03-21
*  Created By: Andrea Andreu Salvagnin
*/


#include "catch.hpp"
#include "PAT_EntityManager.hpp"
#include "PAT_Component.hpp"

TEST_CASE("Instantiate an entity manager", "[ecs]")
{
	ECS::PAT_EntityManager em;

	WHEN("an entity manager is instantiated")
	{

		ECS::EntityID id;
		id = em.CreateEntity();

		ECS::EntityID id2;
		id2 = em.CreateEntity();

		ECS::EntityID expected_equal_id = em.DeleteEntity(id);

		ECS::EntityID expected_id_0 = em.DeleteEntity(id);

		THEN("it's possible to put an entity")
		{
			REQUIRE(id != 0);
		}

		THEN("second entity has different id from previous one")
		{
			REQUIRE(id != id2);
		}

		THEN("it's possible to delete an entity")
		{
			REQUIRE(id == expected_equal_id);
		}

		THEN("return 0 if you try to erase a non existent EntityID")
		{
			REQUIRE(expected_id_0 == 0);
		}
	}
}

TEST_CASE("Associate components to an entity", "[ecs]")
{
	ECS::PAT_EntityManager em;

	ECS::EntityID id = em.CreateEntity();

	struct TestComponentEM : public ECS::PAT_Component<TestComponentEM>
	{
		TestComponentEM(ECS::EntityID eid) : PAT_Component(eid){ }
	};

	WHEN("an entity manager is instantiated")
	{
		TestComponentEM comp =
				em.CreateComponent<TestComponentEM>(id);

		THEN("it's possible to associate a compoent")
		{
			REQUIRE(comp.GetEnityID() == id);
		}

		THEN("it's possible to delete an associate compoent")
		{
			em.DeleteEntityComponent(comp.GetComponentTypeID(),
				id);
		}
	}
}
