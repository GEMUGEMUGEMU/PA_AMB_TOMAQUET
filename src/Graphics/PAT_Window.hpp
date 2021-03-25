/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PAT_Window.hpp
*  Purpose: SDL_Window Adapter
*  Creation Date: 23-03-21
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef PAT_Window_hpp
#define PAT_Window_hpp
#include "PAT.hpp"
#include "PAT_Sprite.hpp"

struct PAT_Window
{
	enum STATUS {OK, WRONG_DIMENSINOS, WRONG_W_NAME, INIT_ERROR,
		QUIT_UNINT_WINDOW, E_PAT_UNINT, RENDERER_ERROR, SURFACE_ERROR};

	typedef short unsigned int SI;

	PAT_Window(SI height, SI width, const char* windowName);

	void Render();
	void CleanRender();
	void AddToRender(PAT_Sprite* pSprite);

	~PAT_Window();

	STATUS Init();
	STATUS Quit();
	SDL_Renderer* mRenderer { nullptr };

protected:
	SI mHeight = 0;
	SI mWidth = 0;

	const char* mWindowName { nullptr };

private:
	void DeleteSDLWindow();
	void DeleteSDLRender();
	void FreePixelFormat();

	SDL_Window* mWindow { nullptr };
	SDL_PixelFormat* mPixelFormat { nullptr };
	uint32_t mCleanColor;
};

#endif /* PAT_Window_hpp */
