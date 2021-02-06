/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: Player.h
*  Purpose:
*  Creation Date: 27-10-20
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef Player_h
#define Player_h

#include "PAT_AnimatedKineticObject.h"
#include "PAT_Controller.h"
#include "PAT_Animation.h"
#include "PAT_Vector2D.h"
#include "PlayerState.h"
#include "PlayerAnimationManager.h"

class Player : public PAT_AnimatedKineticObject, public PAT_Controller
{
public:
	Player(){}
	~Player();

	void Init(float speed, PAT_Vector2D vector, SDL_Renderer * render);

	uint8_t Move(float deltaTime) override;
	void Update(float deltaTime) override;
	void Draw(SDL_Renderer* render) override;
	void Input(SDL_Event * event) override;

	void SetState(PlayerState * newState);
	void SetDirection(PAT_Vector2D newDirection);
	void ResetMove();
	bool DirectionIsNull();

	PlayerAnimationManager mAnimationManager;

protected:
	PlayerState * mState = nullptr;
	PAT_Vector2D * mArrival = nullptr;
};

#endif /* Player_h */
