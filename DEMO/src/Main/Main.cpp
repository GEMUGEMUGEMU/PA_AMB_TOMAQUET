/*
File Name: main.cpp
Purpose:
Creation Date: 08-09-20
Created By: Andrea Andreu Salvagnin
*/

#include "PAT_System.hpp"
#include "Game.hpp"

Game gGame;

int main(int argc, const char * argv[])
{
	if(PAT_System::Init() == 0)
	{
		if(gGame.Init() == 0)
		{
			gGame.Run();
		}
	}

	PAT_System::Quit();

	return 0;
}

