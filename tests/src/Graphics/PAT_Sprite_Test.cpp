/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PAT_Sprite_Test.cpp
*  Purpose:
*  Creation Date: 04-05-21
*  Created By: Andrea Andreu Salvagnin
*/


#include "catch.hpp"
#include "PAT_Sprite.hpp"
#include "PAT_System.hpp"
#include "TestWindow.hpp"
#include "PAT_Status.hpp"

TEST_CASE("Instantiate a PAT Sprite", "[grphcs]")
{
	struct TestSprite : public PAT::Sprite
	{
		PAT::Status Init(PAT::Renderer* pRender)
		{
			InitSprite(pRender, mFilePath);
		}

		char * mFilePath = "./DEMO/sprites/Prehistoric0.png";
	};

	struct TestWrongPath : public PAT::Sprite
	{
		PAT::Status Init(PAT::Renderer* pRender)
		{
			InitSprite(pRender, mFilePath);
		}

		char * mFilePath = "";
	};

	TestSprite t_sprite;


	TestWrongPath wrong_path;

	WHEN("PAT system is instantiated")
	{
		PAT_System::Init();
		TestWindow t_window;
		t_window.Init();

		THEN("Initializing a PAT sprite it's possible")
		{
			REQUIRE(t_sprite.Init(&t_window.mRenderer) == 0);
		}
		PAT_System::Quit();
	}


	WHEN("PAT sprite get a wrong path")
	{
		PAT_System::Init();
		TestWindow t_window;
		t_window.Init();

		THEN("Initializing a PAT sprite returns an error")
		{
			REQUIRE(wrong_path.Init(&t_window.mRenderer) ==
				PAT::Status::LOAD_FILE_E);
		}
		PAT_System::Quit();
	}

	WHEN("PAT sprite recives null arguments")
	{
		PAT_System::Init();
		TestWindow t_window;
		t_window.Init();

		THEN("for a null renderer PAT sprite returns an error")
		{
			REQUIRE(wrong_path.Init(nullptr) ==
				PAT::Status::INVALID_ARGS);
		}
		PAT_System::Quit();
	}
}

