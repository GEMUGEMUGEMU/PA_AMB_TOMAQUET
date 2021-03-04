/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: PAT_Singleton.hpp
*  Purpose:
*  Creation Date: 06-12-20
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef PAT_Singleton_hpp
#define PAT_Singleton_hpp

template <class T>
class PAT_Singleton
{
public:
	PAT_Singleton(){}
	~PAT_Singleton(){}
	static T& GetInstance();
};

template <class T>
T& PAT_Singleton<T>::GetInstance()
{
	static T t;
	return t;
}
#endif /* PAT_Singleton_hpp */
