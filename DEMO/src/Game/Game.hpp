/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: Game.hpp
*  Purpose:
*  Creation Date: 06-12-20
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef Game_hpp
#define Game_hpp

//#include "SDL2/SDL.h"
//#include "PAT_SceneManager.hpp"
//#include "PAT_Screen.hpp"
#include "PAT.hpp"
#include "Window.hpp"

class Game
{
public:
	typedef short unsigned int SI;
	Game();
	~Game();
//	virtual bool Init(uint32_t width, uint32_t height,
//		const char* windowName) = 0;

	SI Init();

	void Run();
//	bool InitSDL();
//	void Close();

	void ProcessInput();
//	void Update(double deltaTime);
	void Render();

protected:
//	static double FRAME_PER_SECOND;
	bool mRunning = true;
//	SDL_Window * mWindow;
	Window mWindow;
//	PAT_Screen mScreen;
//	PAT_SceneManager* mSceneManager;
};

#endif /* Game_hpp */
