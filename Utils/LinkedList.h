/*
File Name: LinkedList.h
Purpose: 
Creation Date: 19-09-20
Created By: Andrea Andreu Salvagnin
*/

#ifndef LinkedList_h
#define LinkedList_h
#include "stdint.h"

template <class T> 
class LinkedList
{
private:
	struct Node
	{
		T *mData;
		Node *next;
		Node(): next(nullptr){}
		Node(T* newData): mData(newData), next(nullptr){}
	};

	Node *mHead = nullptr;
	uint32_t mSize = 0;

public:
	LinkedList(){}
	~LinkedList();
	
	uint32_t GetSize();
	
	void Add(T* newValue);
	T* Get(uint32_t index);

	void Delete(uint32_t index);

};

template <class T> 
LinkedList<T>::~LinkedList()
{	
	Node *targetNode = mHead;
	Node *nodeToDelete;

	while (targetNode != nullptr)
	{
		nodeToDelete = targetNode;
		targetNode = targetNode->next;
		delete nodeToDelete;
	}

	mHead = nullptr;
}


template <class T> 
void LinkedList<T>::Add(T *newValue)
{
	Node *newNode = new Node(newValue);
	
	if(mHead == nullptr)
	{
		mHead = newNode;
	}
	else
	{
		Node *tempNode = mHead;

		while(tempNode->next != nullptr)
		{
			tempNode = tempNode->next;
		}

		tempNode->next= newNode;
	}

	mSize = mSize + 1;
}


template <class T> 
T* LinkedList<T>::Get(uint32_t index)
{
	Node *targetNode = mHead;
	uint32_t counter = 0;

	while (targetNode != nullptr && index < mSize && counter < mSize )
	{
		
		if(counter == index)
		{
			return targetNode->mData;
		}

		targetNode = targetNode->next;
		counter = counter + 1;
	}

	return nullptr;
}

template <class T> 
uint32_t LinkedList<T>::GetSize()
{
	return mSize;
}

template <class T> 
void LinkedList<T>::Delete(uint32_t index)
{	

	Node *targetNode = mHead;
	Node *previousNode = nullptr;
	uint32_t counter = 0;
	uint32_t lastIndex = mSize -1;

	while (targetNode != nullptr && index < mSize && counter < mSize )
	{

		if(counter == index)
		{
			//if it's head then
			if(counter == 0)
			{
				mHead = targetNode->next;
			}
			else
			{
				//If it's tail then
				if(counter == lastIndex)
				{
					previousNode->next = nullptr;
				}
				else
				{
					previousNode->next = targetNode->next;
				}
			}

			delete targetNode;
			mSize = mSize -1;
			break;
		}

		previousNode = targetNode;
		targetNode = targetNode->next;
		counter = counter + 1;
	}
}
#endif /* LinkedList_h */
