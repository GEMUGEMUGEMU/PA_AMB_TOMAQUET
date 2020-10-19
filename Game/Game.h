/*
File Name: Game.h
Purpose: 
Creation Date: 05-09-20
Created By: Andrea Andreu Salvagnin
*/

#ifndef Game_h
#define Game_h

#include <stdint.h>
#include "SDL2/SDL.h"
#include "Screen.h"
#include "Controller.h"
#include "LinkedList.h"
#include "GraphicObject.h"


class Game
{
public:
	Game(){}
	~Game(){}
	static Game& Singleton();
	bool Init(uint32_t width, uint32_t height, const char* windowName);
	void Run();
	void Close();
	void Update(double deltaTime);
	void Draw();
	void Render();
private:
	Screen mScreen;
	SDL_Window * mWindow;
	SDL_Surface* mSurface;
	Controller mController;
	static double FRAME_PER_SECOND;
	LinkedList<GraphicObject> mGraphicObjectsList;
};
#endif /* Game_h */
