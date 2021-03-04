/*
File Name: PAT_LinkedList.hpp
Purpose:
Creation Date: 19-09-20
Created By: Andrea Andreu Salvagnin
*/

#ifndef PAT_LinkedList_hpp
#define PAT_LinkedList_hpp
#include "stdint.h"

template <class T>
class PAT_LinkedList
{
private:
	struct Node
	{
		T *mData;
		Node *next;
		Node(): next(nullptr){}
		Node(T* newData): mData(newData), next(nullptr){}
	};

	Node *mHead;
	uint32_t mSize;

public:
	PAT_LinkedList() : mHead(nullptr), mSize(0) {}
	~PAT_LinkedList();

	uint32_t GetSize();

	void Add(T* newValue);
	T* Get(uint32_t index);
	T* RemoveAtIndex(uint32_t index);
	T* Remove(T* toRemove);
};

template <class T>
PAT_LinkedList<T>::~PAT_LinkedList()
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
void PAT_LinkedList<T>::Add(T *newValue)
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
T* PAT_LinkedList<T>::Get(uint32_t index)
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
uint32_t PAT_LinkedList<T>::GetSize()
{
	return mSize;
}

template <class T>
T* PAT_LinkedList<T>::RemoveAtIndex(uint32_t index)
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

			mSize = mSize -1;

			T* removedData = targetNode->mData;
			delete targetNode;
			return removedData;
		}

		previousNode = targetNode;
		targetNode = targetNode->next;
		counter = counter + 1;
	}

	return nullptr;
}

template <class T>
T* PAT_LinkedList<T>::Remove(T* toRemove)
{
	Node *targetNode = mHead;
	Node *previousNode = nullptr;

	while (targetNode != nullptr)
	{
		if(targetNode->mData==toRemove)
		{
			if(targetNode == mHead)
			{
				//If there was only one node
				if(mHead->next == nullptr)
				{
					mHead = nullptr;
				}
				else
				{
					mHead=targetNode->next;
				}
			}
			else
			{
				previousNode->next = targetNode->next;
			}

			mSize = mSize - 1;

			T* removedData = targetNode->mData;
			delete targetNode;
			return removedData;
		}
	}

	return nullptr;
}

#endif /* PAT_LinkedList_hpp */
