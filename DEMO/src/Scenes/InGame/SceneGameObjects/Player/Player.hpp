/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: Player.hpp
*  Purpose:
*  Creation Date: 27-10-20
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef Player_hpp
#define Player_hpp

#include "PAT_AnimatedKineticObject.hpp"
#include "PAT_Controller.hpp"
#include "PAT_CollidingObject.hpp"
#include "PAT_Subject.hpp"
#include "PAT_Animation.hpp"
#include "PAT_Vector2D.hpp"
#include "Pl_State.hpp"
#include "Pl_AnimationManager.hpp"

class Player : public PAT_AnimatedKineticObject, public PAT_Controller,
public PAT_CollidingObject, public PAT_Subject
{
public:
	Player(){}
	~Player();

	void Init(float speed, PAT_Vector2D vector, SDL_Renderer * renderer);

	uint8_t Move(float deltaTime) override;
	void Update(float deltaTime) override;
	void Draw(SDL_Renderer* render) override;
	void Input(SDL_Event * event) override;

	void SetState(Pl_State * newState);
	void SetDirection(PAT_Vector2D newDirection);
	void ResetMove();
	bool DirectionIsNull();

	Pl_AnimationManager mAnimationManager;

	PAT_Vector2D mPosition;
//protected:
	Pl_State * mState = nullptr;
	PAT_Vector2D * mArrival = nullptr;
};

#endif /* Player_hpp */
