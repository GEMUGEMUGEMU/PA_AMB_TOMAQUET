/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: PAT_Game.hpp
*  Purpose:
*  Creation Date: 06-12-20
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef PAT_Game_hpp
#define PAT_Game_hpp

#include "SDL2/SDL.h"
#include "PAT_SceneManager.hpp"
#include "PAT_Screen.hpp"

class PAT_Game
{
public:
	PAT_Game(){}
	virtual ~PAT_Game(){}
	virtual bool Init(uint32_t width, uint32_t height,
		const char* windowName) = 0;

	void Run();
	bool InitSDL();
	void Close();

	void ProcessInput();
	void Update(double deltaTime);
	void Render();

protected:
	static double FRAME_PER_SECOND;
	bool mRunning = false;
	SDL_Window * mWindow;
	PAT_Screen mScreen;
	PAT_SceneManager* mSceneManager;
};

#endif /* PAT_Game_hpp */