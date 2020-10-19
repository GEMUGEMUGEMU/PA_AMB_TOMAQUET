/*
File Name: Controller.cpp
Purpose: 
Creation Date: 16-09-20
Created By: Andrea Andreu Salvagnin
*/

#include "SDL2/SDL.h"
#include "Controller.h"
#include "Vector2D.h"

COMMAND_TYPE Controller::ManageInput()
{
	SDL_Event event; 
	while( SDL_PollEvent( &event ) != 0 )
	{
		//User requests quit
		if( event.type == SDL_QUIT )
		{
			return QUIT;
		}
	}

	return NOTHING;
}
