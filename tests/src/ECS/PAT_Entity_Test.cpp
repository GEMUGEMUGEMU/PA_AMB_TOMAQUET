/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PAT_Entity_Test.cpp
*  Purpose:
*  Creation Date: 28-02-21
*  Created By: Andrea Andreu Salvagnin
*/


#include "catch.hpp"
#include "PAT_Entity.hpp"

TEST_CASE("Instantiate an entity", "[ecs]")
{
        ECS::PAT_Entity entity;
}

TEST_CASE("Add an attribute to an entity", "[ecs]")
{
        ECS::PAT_Entity entity;

//        WHEN( "object position is 0 relative position doesn't change" ) {
//
//            THEN( "no changes in hurtbox position" ) {
//                SDL_Rect* test_rect =
//                        test_hurtbox.GetHurtbox(PAT_Vector2D(0, 0));
//
//                REQUIRE( test_rect->x == gRelPos.GetX());
//                REQUIRE( test_rect->y == gRelPos.GetY());
//                REQUIRE( test_rect->w == gWidth);
//                REQUIRE( test_rect->h == gHeight);
//            }
//        }
//
//        WHEN( "object position is 30,30 relative position change" ) {
//
//                THEN( "no changes in hurtbox position" ) {
//                        SDL_Rect* test_rect =
//                                test_hurtbox.GetHurtbox(PAT_Vector2D(30, 30));
//
//                        REQUIRE( test_rect->x == gRelPos.GetX() + 30);
//                        REQUIRE( test_rect->y == gRelPos.GetY() + 30);
//                        REQUIRE( test_rect->w == gWidth);
//                        REQUIRE( test_rect->h == gHeight);
//                }
//        }

}
