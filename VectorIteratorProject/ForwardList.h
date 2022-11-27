#pragma once
#include "VectorIterator.h"

template <class T>
class ListIterator;

template <class T>
struct Node
{
	T value;
	Node* next = nullptr;
};

template <class T>
class ForwardList
{
	Node<T>* head;
	int size;
public:

	friend ListIterator<T>;

	ForwardList() : head{ nullptr }, size{ 0 } {}
	~ForwardList()
	{
		Node<T>* nodeDel;
		while (head)
		{
			nodeDel = head;
			head = head->next;
			delete nodeDel;
		}
	}

	//void Show();

	Node<T>* GetHead() { return head; }

	void PushFront(T value);
	T PopFront();

	Iterator<T>* GetBeginIt();

	void Insert(int index, T value);
	T Replace(int index);
};

template <class T>
void ForwardList<T>::Insert(int index, T value)
{
	if (!index)
	{
		PushFront(value);
		return;
	}

	Node<T>* nodeNew = new Node<T>();
	nodeNew->value = value;

	if (head)
	{
		Node<T>* nodeCurr{ head };
		for (int i = 0; i < index; i++)
			nodeCurr = nodeCurr->next;

		nodeNew->next = nodeCurr->next;
		nodeCurr->next = nodeNew;
	}
	else
	{
		head = nodeNew;
	}
	size++;
}

template <class T>
T ForwardList<T>::Replace(int index)
{
	if (!index)
		return PopFront();

	Node<T>* nodeDel;
	if (size > 1)
	{
		Node<T>* nodeCurr{ head };
		for (int i = 0; i < index; i++)
			nodeCurr = nodeCurr->next;

		nodeDel = nodeCurr->next;
		nodeCurr->next = nodeDel->next;
	}
	else
	{
		nodeDel = head;
		head = nullptr;
	}

	int value = nodeDel->value;
	delete nodeDel;

	size--;
	return value;
}

template <class T>
class ListIterator : public Iterator<T>
{
	Node<T>* current;
	ForwardList<T>* list;
public:
	ListIterator(ForwardList<T>* list)
		: list{ list } 
	{
		current = list->GetHead();
	}

	void Set()
	{
		current = list->head;
	}

	void Next()
	{
		current = current->next;
	}

	bool IsEnd()
	{
		return current == nullptr;
	}

	T Current()
	{
		return current->value;
	}
};

template<class T>
Iterator<T>* ForwardList<T>::GetBeginIt()
{
	return new ListIterator<T>(this);
}
