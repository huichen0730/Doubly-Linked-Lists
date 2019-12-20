#include "pch.h"
#include "DoublyList.h"

//constructor
DoublyList::DoublyList()
{
	Left = nullptr;
	Right = nullptr;
}

//destructor
DoublyList::~DoublyList()
{
	Node* temp;
	while (Left != nullptr)
	{
		temp = Left;
		Left = Left->Next;
		delete temp;
	}
}

//check if it is empty
bool DoublyList::Empty() const
{
	return (Left == nullptr && Right == nullptr) ? true : false;
}

//insert a new element to its correct location, if it is bigger than the current element, by default, insert from the right side of the current element. 
//Otherwise, insert from the left side of the current element in order to keep an ascending order.
bool DoublyList::Insert(const int& new_element)
{
	if (Left == nullptr && Right == nullptr)					//case 1: there is no element in the list yet, so insert an new element as the first element;
	{
		Node* new_node = new Node(new_element, nullptr, nullptr);
		Left = new_node;
		Right = new_node;
	}
	else 												//otherwise, there are already elements in the list, there are another three different cases;
	{
		if (new_element < Left->Element)			//case 2: first need to compare if the new element should be placed in front of the first element (Left end)
		{
			Node* new_node = new Node(new_element, nullptr, Left);
			Left->Prev = new_node;
			Left = new_node;
		}
		else if (new_element >= Right->Element)			//case 3: Then, need to compare if the new element should be placed at back of the last element (Right end)
		{
			Node* new_node = new Node(new_element, Right, nullptr);
			Right->Next = new_node;
			Right = new_node;
		}
		else															//case 4: need to compare if the new element should be added in between the existing elements, 
		{				//in this case, need to traverse from the second element to the last element to compare with the new element to see which place the new element should be inserted.
			Node* temp1 = Left;
			Node* temp2 = Left->Next;
			while ((new_element > temp2->Element) && (temp2 != nullptr))
			{
				temp1 = temp1->Next;
				temp2 = temp2->Next;
			}
			Node* new_node = new Node(new_element, temp1, temp2);
			temp1->Next = new_node;
			temp2->Prev = new_node;
		}
	}
	return true;
}

//Delete an element from the list.
//Delete the first element found if there is more than one of the same number;
bool DoublyList::Delete(const int& del_element)
{
	Node* temp1;
	Node* temp2;

	if (Empty())																		//case 1: an empty list
		return false;
	else if (Left->Element == del_element)							
	{
		if (Left->Next == nullptr&&Right->Next == nullptr)		//case2: the first element is the only one element in the list which is also the one to delete
		{
			temp1 = Left;
			Left = nullptr;
			Right = nullptr;
			delete temp1;
			return true;
		}
		else																		//case3: the first element is the one to delete and there are more than one element in the list
		{
			temp1 = Left;
			Left = Left->Next;
			Left->Prev = nullptr;
			delete temp1;
			return true;
		}
	}
	else if (Left->Next == nullptr)								//case4: there is only one element which is not the one to delete
		return false;
	else if (Right->Element == del_element)				//case5: the last element (Right end) is the one to delete 
	{
		temp1 = Right;
		Right = Right->Prev;
		Right->Next = nullptr;
		delete temp1;
		return true;
	}
	else															//general case: search for the del_element from the second element to the second last element;
	{
		temp1 = Left;
		temp2 = Left->Next;

		while ((temp2->Element != del_element) &&
			(temp2->Next != nullptr))
		{
			temp1 = temp2;
			temp2 = temp2->Next;
		}
		if (temp2->Element == del_element)
		{
			temp1->Next = temp2->Next;
			temp2->Next->Prev = temp1;
			return true;
		}
		else			// list exhausted
			return false;
	}
	return true;
}

//print the list in ascending order
void DoublyList::Print_Asc() const
{
	Node* temp;
	temp = Left;
	while (temp != nullptr)
	{
		cout << temp->Element << " ";
		temp = temp->Next;
	}
}

//print the list in descending order
void DoublyList::Print_Desc() const
{
	Node* temp;
	temp = Right;
	while (temp != nullptr)
	{
		cout << temp->Element << " ";
		temp = temp->Prev;
	}
}

