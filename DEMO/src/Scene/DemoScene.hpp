/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: DemoScene.hpp
*  Purpose:
*  Creation Date: 10-02-21
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef DemoScene_hpp
#define DemoScene_hpp

enum DEMO_SCENE_STATE
{
	//No things to do
	NOTHING,
	//Pop this scene
	POP,
	//Pop and push a scene
	POP_AND_PUSH,
	//Push a scene upon this
	PUSH,
};

class DemoScene : public PAT_Scene , public PAT_Subject
{
public:
	DEMO_SCENE_STATE state;
};

#endif /* DemoScene_hpp */
