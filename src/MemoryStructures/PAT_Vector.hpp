/*
*        ~_
*     ~_ )_)~_
*     )_))_))_)
*     _!__!__!_
*   ~~\t  Gemu/~~
*    ~GEAR~GEAR~
*
*  File Name: PAT_Vector.hpp
*  Purpose: Adapter of std::vector
*  Creation Date: 21-03-21
*  Created By: Andrea Andreu Salvagnin
*/

#ifndef PAT_Vector_hpp
#define PAT_Vector_hpp
#include <vector>

template <typename TypeVector>
struct PAT_Vector
{
	typedef std::vector<TypeVector> Vector;

	PAT_Vector () : mVector() { }


	PAT_Vector<TypeVector>* operator&()
	{
		return this;
	}

	void Reserve(unsigned long int size)
	{
		mVector.reserve(size);
	}

	template<typename Value>
	void PushBack(const Value& value)
	{
		mVector.push_back(value);
	}

	template<typename Value>
	void push_back( Value&& value )
	{
		mVector.push_back(value);
	}

	template<typename Value>
	TypeVector& EmplaceBack(const Value& value)
	{
		return mVector.emplace_back(value);
	}

	typename Vector::iterator Begin()
	{
		return mVector.begin();
	}

	const typename Vector::iterator Begin() const
	{
		return mVector.begin();
	}

	typename Vector::iterator End()
	{
		return mVector.end();
	}

	const typename Vector::iterator End() const
	{
		return mVector.end();
	}

	typename Vector::iterator Erase(typename Vector::iterator pos)
	{
		return mVector.erase(pos);
	}

	unsigned long int Size()
	{
		return mVector.size();
	}

private:
	Vector  mVector;
};

#endif /* PAT_Vector_hpp */
