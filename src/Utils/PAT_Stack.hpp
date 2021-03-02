/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: PAT_Stack.hpp
*  Purpose:
*  Creation Date: 01-11-20
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef PAT_Stack_hpp
#define PAT_Stack_hpp

#include <stdint.h>

template <class T>
class PAT_Stack
{
private:
	struct Node
	{
		T *mData;
		Node *next;
		Node(): next(nullptr){}
		Node(T* newData): mData(newData), next(nullptr){}
	};
	Node * mTop = nullptr;
	uint32_t mSize = 0;
public:
	PAT_Stack(){}
	~PAT_Stack();

	void Pop();
	void Push(T* newValue);
	bool IsEmpty();
	T* GetOnTop();
};

template <class T>
bool PAT_Stack<T>::IsEmpty()
{
	if(mTop == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <class T>
void PAT_Stack<T>::Push(T* newValue)
{
	Node *newNode = new Node(newValue);

	if(mTop == nullptr)
	{
		mTop = newNode;
	}
	else
	{
		Node *tempNode = mTop;
		newNode->next = tempNode;
		mTop = newNode;
	}

	mSize = mSize + 1;
}

template <class T>
PAT_Stack<T>::~PAT_Stack()
{
	while(!IsEmpty())
	{
		Pop();
	}
}

template <class T>
T* PAT_Stack<T>::GetOnTop()
{
	return mTop->mData;
}


template <class T>
void PAT_Stack<T>::Pop()
{
	if(!IsEmpty())
	{
		if(mTop->next == nullptr)
		{
			delete	mTop;
			mTop = nullptr;
		}
		else
		{
			Node * tempNode = mTop;

			mTop = tempNode->next;

			delete tempNode;
		}
	}
}

#endif /* PAT_Stack_hpp */
