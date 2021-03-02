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

Player::Player(float speed, PAT_Vector2D position) :
	PAT_AnimatedKineticObject(speed), PAT_CollidingObject(mPosition),
	mPosition(position), mpState(new Pl_S_Idle())
{
}

Player::~Player()
{
	if(mpArrival)
	{
		delete mpArrival;
		mpArrival = nullptr;
	}

	if(mpState)
	{
		delete mpState;
		mpState = nullptr;
	}
}

void Player::Init( SDL_Renderer * pRenderer)
{
	mAnimationManager.Init(pRenderer);
}

//Function that moves player. Return  0 if it has arrived otherwise 1;
uint8_t Player::Move(float deltaTime)
{
	float secondsDeltaTime = deltaTime / 100;

	//How much player can move in one second
	if(mpArrival == nullptr)
	{
		mpArrival = new PAT_Vector2D(( mDirection * mSpeed ) + mPosition);
	}

	//How much player can move in this delta time
	PAT_Vector2D newPosition = (mDirection * mSpeed * secondsDeltaTime)
		+ mPosition;

	float distanceToTravel =
		mPosition.DistanceFromPoint(&newPosition);

	float distanceToArrival =
		mPosition.DistanceFromPoint(mpArrival);

	//If arrival is surpassed then put new position as arrival
	if(distanceToArrival <= distanceToTravel)
	{
		mPosition = mpArrival;
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
	delete(mpArrival);
	mpArrival = nullptr;
}

void Player::Update(float deltaTime)
{
	mpState->Update(deltaTime, this);
}

void Player::Draw(SDL_Renderer* pRenderer)
{
	mpState->Draw(this);
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

void Player::SetState(Pl_State * pNewState)
{
	delete(mpState);
	mpState = pNewState;
}

void Player::Input(SDL_Event * pEvent)
{
	mpState->Input(pEvent, this);
}

