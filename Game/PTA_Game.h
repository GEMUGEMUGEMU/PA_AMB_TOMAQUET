/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: PTA_Game.h
*  Purpose:
*  Creation Date: 06-12-20
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef PTA_Game_h
#define PTA_Game_h

#include "SDL2/SDL.h"
#include "SceneManager.h"
#include "Screen.h"

class PTA_Game
{
public:
	PTA_Game(){}
	virtual ~PTA_Game(){}
	virtual bool Init(uint32_t width, uint32_t height,
		const char* windowName) = 0;
	void Run();
	void Close();

	void Input();
	void Update(double deltaTime);
	void Render();

protected:
	static double FRAME_PER_SECOND;
	bool mRunning = false;
	SDL_Window * mWindow;
	Screen mScreen;
	SceneManager* mSceneManager;
};

#endif /* PTA_Game_h */
