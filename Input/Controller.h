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
	NOTHING,
	PAUSE
};

class Controller
{
public:
	Controller(){}
	virtual ~Controller(){ }
	virtual COMMAND_TYPE ManageInput(){return NOTHING;}
};
#endif /* Controller_h */
