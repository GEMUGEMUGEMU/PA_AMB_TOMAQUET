/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PAT_Component.cpp
*  Purpose:
*  Creation Date: 28-02-21
*  Created By: Andrea Andreu Salvagnin
*/


#include "PAT_Component.hpp"

ECS::ComponentTypeID ECS::PAT_Component::mNextTypeID = 0;


ECS::PAT_Component::PAT_Component(EntityID entityID) : mEntityID(entityID) { }
