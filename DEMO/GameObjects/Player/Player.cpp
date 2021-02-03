/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: Player.cpp
*  Purpose:
*  Creation Date: 27-10-20
*  Created By: Andrea Andreu Salvagnin
*/

#include "Player.h"
#include "PAT_State.h"
#include "PAT_MathUtils.h"
#include "PlayerAnimationManager.h"
#include "PlayerSIdle.h"

Player::~Player()
{
}

//void Player::Init(float speed, uint32_t x, uint32_t y, SDL_Renderer* render)
//{
//	mSpeed = speed;
//	//mAnimationManager = new PlayerAnimationManager();
//	mAnimationManager->Init(render);
//
//	mPosition = PAT_Vector2D(x, y);
//
//	mState = new PlayerSIdle();
//}

void Player::Init(float speed, PAT_Vector2D vector, SDL_Renderer * render)
{
	mSpeed = speed;
	//mAnimationManager = new PlayerAnimationManager();
	mAnimationManager.Init(render);

	mPosition = vector;

	mState = new PlayerSIdle();
}

//Function that moves player. Return 1 if it has arrived otherwise 0;
uint8_t Player::Move(float deltaTime)
{
	float secondsDeltaTime = deltaTime / 100;

	//How much player can move in one second
	if(mArrival == nullptr)
	{
		mArrival = new PAT_Vector2D(( mDirection * mSpeed ) + mPosition);
	}

	//How much player can move in this delta time
	PAT_Vector2D newPosition = (mDirection * mSpeed * secondsDeltaTime)
		+ mPosition;

	float distanceToTravel =
		mPosition.DistanceFromPoint(&newPosition);

	float distanceToArrival =
		mPosition.DistanceFromPoint(mArrival);

	//If arrival is surpassed then put new position as arrival
	if(distanceToArrival <= distanceToTravel)
	{
		mPosition = mArrival;
		mDirection = PAT_Vector2D::Vector2DZero;
		delete(mArrival);
		mArrival = nullptr;

		return 1;
	}
	else
	{
		mPosition = newPosition;

		return 0;
	}
}

void Player::Update(float deltaTime)
{
	mState->Update(deltaTime, this);
}

void Player::Draw(SDL_Renderer* render)
{
	mState->Draw(render, this);
	//mAnimationManager->Draw(mPosition.GetX(),mPosition.GetY(), renderer);
}

void Player::SetDirection(PAT_Vector2D newDirection)
{
	if(mDirection.EqualsVectorZero())
	{
		mDirection = newDirection;
	}
}

//void Player::SetState(PlayerState* newState)
//{
//	mState = newState;
//}

//void Player::SetAnimation(PAT_Animation* newAnimation)
//{
//	mAnimationManager->SetAnimation(newAnimation);
//}

bool Player::DirectionIsNull()
{
	return mDirection.EqualsVectorZero();
}
