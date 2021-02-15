/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: NPC.hpp
*  Purpose:
*  Creation Date: 11-02-21
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef NPC_hpp
#define NPC_hpp

#include "PAT_AnimatedObject.hpp"
#include "PAT_CollidingObject.hpp"
#include "PAT_Subject.hpp"
#include "PAT_Vector2D.hpp"
#include "NPC_AnimationManager.hpp"

class NPC : public PAT_AnimatedObject, public PAT_CollidingObject,
public PAT_Subject
{
public:
	NPC();
	~NPC();
	void Init(PAT_Vector2D newPosition, SDL_Renderer * render);

	void Draw(SDL_Renderer* renderer) override;
	void Update(float deltaTime) override;

	NPC_AnimationManager mAnimationManager;

	PAT_Hitbox mHitbox;
	PAT_Vector2D mPosition;
};

#endif /* NPC_hpp */
