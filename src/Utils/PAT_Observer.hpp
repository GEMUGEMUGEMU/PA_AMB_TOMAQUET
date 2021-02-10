/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PAT_Observer.hpp
*  Purpose: Observer class for observer pattern
*  Creation Date: 10-02-21
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef PAT_Observer_hpp
#define PAT_Observer_hpp

class PAT_Subject;

class PAT_Observer
{
public:
	virtual ~PAT_Observer(){}
	virtual void Update(PAT_Subject* changedSubject) = 0;
protected:
	PAT_Observer();
};

#endif /* PAT_Observer_hpp */
