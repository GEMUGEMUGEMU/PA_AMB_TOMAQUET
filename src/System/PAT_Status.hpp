/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PAT_Status.hpp
*  Purpose:
*  Creation Date: 04-05-21
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef PAT_Status_hpp
#define PAT_Status_hpp


namespace PAT
{

enum/* class*/ Status
{
	OK = 0,
	PAT_SYS_UNINT,
	INVALID_ARGS,
	LOAD_FILE_E,
	INIT_ERROR
};

}

#endif /* PAT_Status_hpp */
