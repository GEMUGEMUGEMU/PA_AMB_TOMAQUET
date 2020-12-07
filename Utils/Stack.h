/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*
*  File Name: Stack.h
*  Purpose:
*  Creation Date: 01-11-20
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef Stack_h
#define Stack_h

#include <stdint.h>

template <class T>
class Stack
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
	Stack(){}
	~Stack();

	void Pop();
	void Push(T* newValue);
	bool IsEmpty();
	T* GetOnTop();
};

template <class T>
bool Stack<T>::IsEmpty()
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
void Stack<T>::Push(T* newValue)
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
void Stack<T>::Pop()
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

template <class T>
Stack<T>::~Stack()
{
	while(!IsEmpty())
	{
		Pop();
	}
}


template <class T>
T* Stack<T>::GetOnTop()
{
	return mTop->mData;
}

#endif /* Stack_h */
