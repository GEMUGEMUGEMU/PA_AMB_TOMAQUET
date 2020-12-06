/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: Singleton.h
*  Purpose:
*  Creation Date: 06-12-20
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef Singleton_h
#define Singleton_h

template <class T>
class Singleton
{
public:
	Singleton(){}
	~Singleton(){}
	static T& GetInstance();
};

template <class T>
T& Singleton<T>::GetInstance()
{
	static T t;
	return t;
}
#endif /* Singleton_h */
