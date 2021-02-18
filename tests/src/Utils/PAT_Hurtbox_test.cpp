/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PAT_Hurtbox_test.cpp
*  Purpose:
*  Creation Date: 18-02-21
*  Created By: Andrea Andreu Salvagnin
*/

#include "catch.hpp"
#include "PAT_Vector2D.hpp"
#include "PAT_Hurtbox.hpp"


const uint32_t gWidth = 10;
const uint32_t gHeight = 15;
const PAT_Vector2D gRelPos(50, 50);

class TestHurtbox : public PAT_Hurtbox
{
public:
	TestHurtbox() :
		PAT_Hurtbox(gRelPos, gWidth, gHeight)
	{

	}
	~TestHurtbox()
	{

	}
};


TEST_CASE("Hurtbox test", "[utils]")
{
	TestHurtbox test_hurtbox;

	WHEN( "object position is 0 relative position doesn't change" ) {

            THEN( "no changes in hurtbox position" ) {
		SDL_Rect* test_rect =
			test_hurtbox.GetHurtbox(PAT_Vector2D(0, 0));

                REQUIRE( test_rect->x == gRelPos.GetX());
                REQUIRE( test_rect->y == gRelPos.GetY());
                REQUIRE( test_rect->w == gWidth);
                REQUIRE( test_rect->h == gHeight);
            }
        }

	WHEN( "object position is 30,30 relative position change" ) {

		THEN( "no changes in hurtbox position" ) {
			SDL_Rect* test_rect =
				test_hurtbox.GetHurtbox(PAT_Vector2D(30, 30));

			REQUIRE( test_rect->x == gRelPos.GetX() + 30);
			REQUIRE( test_rect->y == gRelPos.GetY() + 30);
			REQUIRE( test_rect->w == gWidth);
			REQUIRE( test_rect->h == gHeight);
		}
	}

}

