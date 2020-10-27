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

Player::~Player()
{
	delete mAnimationManager;
}

void Player::Init(float speed, uint32_t x, uint32_t y, SDL_Renderer* render)
{
	mSpeed = speed;
	mAnimationManager = new PlayerAnimationManager();
	mAnimationManager->Init(render);

	mX = x;
	mY = y;
}

void Player::Move(float deltaTime)
{
	Vector2D newPosition = mDirection * mSpeed * deltaTime;

	mX += newPosition.GetX();
	mY += newPosition.GetY();

	mDirection.SetX(0);
	mDirection.SetY(0);
}

void Player::Update(float deltaTime)
{
	mAnimationManager->UpdateFrame();
	Move(deltaTime);
}

void Player::SetDirection(Vector2D newDirection)
{
	mDirection.SetX(newDirection.GetX());
	mDirection.SetY(newDirection.GetY());
}
