/*
File Name: Controller.h
Purpose: 
Creation Date: 16-09-20
Created By: Andrea Andreu Salvagnin
*/

#ifndef Controller_h
#define Controller_h


enum COMMAND_TYPE
{
	QUIT,
	KEY,
	NOTHING
};

class Controller
{
public:
	Controller(){}
	~Controller(){}
	COMMAND_TYPE ManageInput();
};
#endif /* Controller_h */
