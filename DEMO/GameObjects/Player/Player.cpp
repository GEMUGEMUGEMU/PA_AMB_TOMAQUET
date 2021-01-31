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
#include "PlayerAnimationManager.h"
#include "PlayerState.h"
#include "PlayerSIdle.h"
#include "PAT_MathUtils.h"

Player::~Player()
{
	delete mAnimationManager;
}

//TODO: I need to set velocity as init argument?
void Player::Init(float speed, uint32_t x, uint32_t y, SDL_Renderer* render)
{
	mSpeed = speed;
	mAnimationManager = new PlayerAnimationManager();
	mAnimationManager->Init(render);

	mX = x;
	mY = y;

	mState = new PlayerSIdle();
}

//TODO: put this as returning state 0 if not arrived, 0 if arrived
void Player::Move(float deltaTime)
{
	//If it's the first time calculate wher it have to arrive
	if(destination.EqualsVectorZero)
	{
		mArrival =  mDirection * mMovingDistance;
	}
	//How much player can move in this delta time
	mNewPosition = mDirection * mSpeed * deltaTime;
//TODO: put a Vector2D member to player
	float distanceTraveled =
		TwoPointsDistance(mPosition /*actual position of player*/,
			mNewPosition);

	float distanceToArrival = TwoPointsDistance(position, mArrival);

	//If arrival is surpassed then put new position as arrival
	if(distanceToArrival < distanceTraveled)
	{
		mPosition = mArrival;
	}
}

//void Player::Move(float deltaTime)
//{
//	PAT_Vector2D newPosition = mDirection * mSpeed * deltaTime;
//
//	mX += newPosition.GetX();
//	mY += newPosition.GetY();
//
//	mDirection.SetX(0);
//	mDirection.SetY(0);
//}

void Player::Update(float deltaTime)
{
	mState->Update(deltaTime, this);
}

void Player::SetDirection(PAT_Vector2D newDirection)
{
	mDirection.SetX(newDirection.GetX());
	mDirection.SetY(newDirection.GetY());
}

void Player::SetState(PlayerState* newState)
{
	mState = newState;
}

void Player::SetAnimation(PAT_Animation* newAnimation)
{
	mAnimationManager->SetAnimation(newAnimation);
}

bool Player::DirectionIsNull()
{
	return mDirection.EqualsVectorZero();
}
