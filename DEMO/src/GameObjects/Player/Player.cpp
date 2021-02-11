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

#include "Player.hpp"
#include "PAT_MathUtils.hpp"
#include "Pl_AnimationManager.hpp"
#include "Pl_S_Idle.hpp"

Player::~Player()
{
}


void Player::Init(float speed, PAT_Vector2D vector, SDL_Renderer * render)
{
	mSpeed = speed;

	mAnimationManager.Init(render);

	mPosition = vector;

	mState = new Pl_S_Idle();
}

//Function that moves player. Return  0 if it has arrived otherwise 1;
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
		ResetMove();
		return 0;
	}
	else
	{
		mPosition = newPosition;
		return 1;
	}
}

void Player::ResetMove()
{
	mDirection = PAT_Vector2D::Vector2DZero;
	delete(mArrival);
	mArrival = nullptr;
}

void Player::Update(float deltaTime)
{
	mState->Update(deltaTime, this);
}

void Player::Draw(SDL_Renderer* render)
{
	mState->Draw(render, this);
}

void Player::SetDirection(PAT_Vector2D newDirection)
{
	if(mDirection.EqualsVectorZero())
	{
		mDirection = newDirection;
	}
}

bool Player::DirectionIsNull()
{
	return mDirection.EqualsVectorZero();
}

void Player::SetState(Pl_State * newState)
{
	delete(mState);
	mState = newState;
}

void Player::Input(SDL_Event * event)
{

	mState->Input(event, this);
}
