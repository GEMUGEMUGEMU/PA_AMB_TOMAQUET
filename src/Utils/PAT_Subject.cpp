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

void PAT_Subject::Attach(PAT_Observer* observer)
{
	mObserversList.Add(observer);
}

void PAT_Subject::Detach(PAT_Observer* observer)
{
	mObserversList.Remove(observer);
}

void PAT_Subject::Notify()
{
	PAT_Observer* thisObserver = nullptr;

	uint32_t size = mObserversList.GetSize();
	uint32_t counter = 0;

	while(counter < size)
	{
		thisObserver = mObserversList.Get(counter);
		thisObserver.Update(this);
		counter = counter + 1;
	}
}

