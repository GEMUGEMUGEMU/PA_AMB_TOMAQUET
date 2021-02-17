/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PAT_Subject.cpp
*  Purpose:
*  Creation Date: 10-02-21
*  Created By: Andrea Andreu Salvagnin
*/

#include "PAT_Subject.hpp"

PAT_Subject::PAT_Subject()
{

}

void PAT_Subject::Attach(PAT_Observer* pObserver)
{
	mObserversList.Add(pObserver);
}

void PAT_Subject::Detach(PAT_Observer* pObserver)
{
	mObserversList.Remove(pObserver);
}

void PAT_Subject::Notify()
{
	PAT_Observer* p_this_observer = nullptr;

	uint32_t size = mObserversList.GetSize();
	uint32_t counter = 0;

	while(counter < size)
	{
		p_this_observer = mObserversList.Get(counter);
		p_this_observer->UpdateFromSubject(this);
		counter = counter + 1;
	}
}

