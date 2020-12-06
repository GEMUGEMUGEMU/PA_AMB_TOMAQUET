/*
File Name: main.cpp
Purpose: 
Creation Date: 08-09-20
Created By: Andrea Andreu Salvagnin
*/
#include "Game.h"
const uint32_t SCREEN_WIDTH = 600;
const uint32_t SCREEN_HEIGHT = 600;
const char* WINDOW_NAME ="PA AMB TOMÀQUET DEMO";

int main(int argc, const char * argv[])
{
	if(Game::Singleton().Init(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_NAME))
	{
		Game::Singleton().Run();
	}

    return 0;
}


