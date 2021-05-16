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
#include "PrehistoricSprite.hpp"

struct GraphicSystem : public PAT_GameSystem
{
	GraphicSystem();
	~GraphicSystem();

	unsigned short int Init(ECS::PAT_EntityManager* pEntityManager);
	void Update(ECS::PAT_EntityManager* pEntityManager) override;

	PrehistoricSprite mPrehistoricSpriteSheet;

private:
	PAT::Window mWindow;
	PAT::Renderer mRenderer;
};

#endif /* GraphicSystem_hpp */
