/*
File Name: main.cpp
Purpose:
Creation Date: 08-09-20
Created By: Andrea Andreu Salvagnin
*/

#include "Demo.h"
#include "Singleton.h"
const uint32_t SCREEN_WIDTH = 300;
const uint32_t SCREEN_HEIGHT = 400;
const char* WINDOW_NAME ="NISHIKIGOI DEMO";

int main(int argc, const char * argv[])
{
	Singleton<Demo> game;
	if(Singleton<Demo>::GetInstance().Init(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_NAME))
	{
		Singleton<Demo>::GetInstance().Run();
	}

	return 0;
}

