/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: GraphicSystem.hpp
*  Purpose:
*  Creation Date: 24-04-21
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef GraphicSystem_hpp
#define GraphicSystem_hpp

#include "PAT_GameSystem.hpp"
#include "PAT_Window.hpp"

struct GraphicSystem //: public PAT_GameSystem
{
	GraphicSystem();
	~GraphicSystem();

	unsigned short int Init();
//	void Update(ECS::PAT_GameContext* pGameContext) override;
	void Update();

	PAT_Sprite mSprite;
private:
	PAT_Window mWindow;
	SDL_Texture* mTexture {nullptr};
};

#endif /* GraphicSystem_hpp */
