#pragma once
#ifndef DoublyList_h
#define DoublyList_h
#include <iostream>
using namespace std;

class DoublyList
{
private:
	class Node
	{
	public:
		int Element;		//integer data
		Node* Prev;		//a pointer pointing to the previous node
		Node* Next;		//a pointer pointing to the next node

		Node() : Prev(nullptr), Next(nullptr) {}
		Node(int data, Node* pPrev, Node* pNext) : Element(data), Prev(pPrev), Next(pNext) {}		//second constructor with three parameters
	};

	Node* Left; //as the left end of the list
	Node* Right; //as the right end of the list

public:
	DoublyList();
	~DoublyList();
	bool Empty() const;
	bool Insert(const int& new_element);
	bool Delete(const int& del_element);
	void Print_Asc() const;
	void Print_Desc() const;
};

#endif
