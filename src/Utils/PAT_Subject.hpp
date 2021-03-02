/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PAT_Subject.hpp
*  Purpose: Subject class for observer pattern
*  Creation Date: 10-02-21
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef PAT_Subject_hpp
#define PAT_Subject_hpp

#include "PAT_Observer.hpp"
#include "PAT_LinkedList.hpp"

class PAT_Subject
{
public:
	virtual ~PAT_Subject(){ }
	void Attach(PAT_Observer* pObserver);
	void Detach(PAT_Observer* pObserver);
	void Notify();

//protected:
	PAT_Subject();

//private:
	PAT_LinkedList<PAT_Observer> mObserversList;
};

#endif /* PAT_Subject_hpp */
