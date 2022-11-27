#pragma once
#include "VectorIterator.h"

template <class T>
class VectorIterator;

template <class T>
class Vector
{
	T* array;
	int size;
	int capacity;
public:
	Vector(int size = 0) : size{ size }
	{
		if (size < 5)
			capacity = 4;
		else
			capacity = size + size / 2;

		array = nullptr;
		if (size)
			array = new T[capacity]{};
	}

	Vector(const Vector& vector)
	{
		this->size = vector.size;
		this->capacity = vector.size;

		this->array = new T[this->capacity];
		for (int i = 0; i < this->size; i++)
			this->array[i] = vector.array[i];
	}

	~Vector()
	{
		if (array)
			delete[]array;
	}

	int Size();
	int Capacity();

	T& At(int index);
	T& operator[](int index);

	Vector operator=(const Vector& vector);

	void PushBack(T value);
	T PopBack();

	Iterator<T>* GetBeginIt();

	//void Insert(int index, T value);
	//T Replace(int index);
};

template <class T>
int Vector<T>::Size()
{
	return this->size;
}

template <class T>
int Vector<T>::Capacity()
{
	return this->capacity;
}

template <class T>
T& Vector<T>::At(int index)
{
	if (index >= 0 && index < this->size)
		return this->array[index];
}

template <class T>
T& Vector<T>::operator[](int index)
{
	if (index >= 0 && index < this->size)
		return this->array[index];
}

template <class T>
Vector<T> Vector<T>::operator=(const Vector<T>& vector)
{
	if (this->array)
		delete[]this->array;

	this->size = vector.size;
	this->capacity = vector.size;

	this->array = new T[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->array[i] = vector.array[i];

	return *this;
}

template <class T>
void Vector<T>::PushBack(T value)
{
	if (size < capacity)
	{
		array[size++] = value;
		return;
	}

	capacity += size / 2;
	int* arrayNew = new T[capacity];
	for (int i = 0; i < size; i++)
		arrayNew[i] = array[i];
	arrayNew[size++] = value;

	delete[] array;
	array = arrayNew;
}

template <class T>
T Vector<T>::PopBack()
{
	int value = array[--size];

	if (size < capacity / 2)
	{
		capacity -= size / 2;
		int* arrayNew = new T[capacity];
		for (int i = 0; i < size; i++)
			arrayNew[i] = array[i];

		delete[] array;
		array = arrayNew;
	}

	return value;
}

template <class T>
class VectorIterator : public Iterator<T>
{
	int index;
	Vector<T>* vect;
public:
	VectorIterator(Vector<T>* vect, int index = 0)
		: vect{ vect }, index{ index } {}

	void Set()
	{
		index = 0;
	}

	void Next()
	{
		index++;
	}

	int operator++(int)
	{
		int oldIndex = index;
		index++;
		return oldIndex;
	}

	bool IsEnd()
	{
		return index >= vect->Size();
	}

	T Current()
	{
		return vect->At(index);
	}
};


template <class T>
Iterator<T>* Vector<T>::GetBeginIt()
{
	return new VectorIterator<T>(this, 0);
}