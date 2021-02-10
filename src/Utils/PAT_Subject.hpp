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

class PAT_Subjcet
public:
	virtual ~PAT_Subjcet(){}
	virtual void Attach(PAT_Observer* observer);
	virtual void Detach(PAT_Observer* observer);
	virtual void Notify();
protected:
	Subject();
private:
	PAT_LinkedList<PAT_Observer*> mObserversList;
};

#endif /* PAT_Subject_hpp */
