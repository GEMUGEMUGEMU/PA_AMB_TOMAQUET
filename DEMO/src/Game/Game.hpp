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

#include "PAT_System.hpp"
#include "PAT_EntityManager.hpp"
#include "GraphicSystem.hpp"


class Game
{
public:
	typedef short unsigned int SI;
	Game();
	~Game();

	SI Init();

	void Run();

	void ProcessInput();
//	void Update(double deltaTime);
	void Render();

protected:
//	static double FRAME_PER_SECOND;
	bool mRunning = true;
	GraphicSystem mGraphicSystem;
//	PAT_Screen mScreen;
//	PAT_SceneManager* mSceneManager;
	ECS::PAT_EntityManager mEntityManager;
};

#endif /* Game_hpp */
