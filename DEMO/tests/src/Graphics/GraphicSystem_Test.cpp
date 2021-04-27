/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: GraphicSystem_Test.cpp
*  Purpose:
*  Creation Date: 29-04-21
*  Created By: Andrea Andreu Salvagnin
*/


#include "catch.hpp"
#include "GraphicSystem.hpp"

TEST_CASE("Try to use GraphicSystem", "[grphcs]")
{

	GraphicSystem graphic_system;

	WHEN("GraphicSystem is instantiated without PAT been initialized")
	{
		PAT::Quit();
		THEN("initializing GraphicSystem retunrs an error")
		{
			REQUIRE(graphic_system.Init() != 0);
		}

		PAT::Init();
		THEN("initializing PAT then initializing a GraphicSystem do not returns an error")
		{
			REQUIRE(graphic_system.Init() == 0);
		}
		PAT::Quit();
	}
}

TEST_CASE("Try to render with GraphicSystem", "[grphcs]")
{
	GraphicSystem graphic_system;

	PAT::Init();
	graphic_system.Init();
	WHEN("GraphicSystem is instantiated without PAT been initialized")
	{
		THEN("initializing PAT then initializing a GraphicSystem do not returns an error")
		{
//			REQUIRE(graphic_system.Init() == 0);
//			graphic_system.Update();
		}
	}
	PAT::Quit();
}
