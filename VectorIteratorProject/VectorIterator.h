#pragma once
#include "Vector.h"

template <class T>
class Iterator
{
public:
	virtual void Set() = 0;
	virtual void Next() = 0;
	virtual bool IsEnd() = 0;
	virtual T Current() = 0;
};
//
//template <class T>
//class VectorIterator //: public Iterator<T>
//{
//	size_t index;
//	Vector<T>* vect;
//public:
//	VectorIterator(Vector<T>* vect, int index = 0)
//		: vect { vect }, index{ index }{}
//
//	void Set()
//	{
//		index = 0;
//	}
//
//	void Next()
//	{
//		++index;
//	}
//
//	int operator++(int)
//	{
//		int oldIndex = index;
//		index++;
//		return oldIndex;
//	}
//
//	bool IsEnd()
//	{
//		return index >= vect->Size();
//	}
//
//	T Current()
//	{
//		return vect[index];
//	}
//};
