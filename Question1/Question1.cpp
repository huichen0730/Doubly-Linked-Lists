#include "pch.h"
#include "DoublyList.h"
#include <iostream>
#include <iomanip>
using namespace std;

void show_menu();
int check_input(int input);

int main()
{
	DoublyList int_doubly_list;						//create a interger doublylist object

	bool keep_looping;
	do
	{
		show_menu();
		keep_looping = 1;
		int choice;
		cout << endl << "Choose the operation you want to perform: " << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
		{   //add an new element
			cout << "Enter an integer. " << endl;
			int new_element;
			cin >> new_element;
			new_element = check_input(new_element);

			if (int_doubly_list.Insert(new_element))
				cout << "The new number has been added successfully into the list." << endl;
			cout << endl;
			break;
		}
		case 2:
		{	//delete an element
			if (int_doubly_list.Empty())
				cout << "Sorry this is an empty list." << endl;
			else
			{
				cout << "Enter the number you want to delete." << endl;
				int dele_number;
				cin >> dele_number;
				dele_number = check_input(dele_number);
				if (int_doubly_list.Delete(dele_number))
					cout << "The deletion has been completed." << endl;
				else
					cout << "Sorry, the element you want to delete is not found in this list." << endl;
			}
			cout << endl;
			break;
		}
		case 3:
		{	//list elements in ascending order
			cout << "The list of elements (ascending order): " << endl;
			int_doubly_list.Print_Asc();
			cout << endl;
			break;
		}
		case 4:
		{ //list elements in descending order
			cout << "The list of elements (descending order): " << endl;
			int_doubly_list.Print_Desc();
			cout << endl;
			break;
		}
		case 5:
		{ // quit the program
			keep_looping = 0;
			cout << "Thank you for using the program." << endl;
			break;
		}
		default:
		{ //handling any unexpected input
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Sorry, the system cannot recognise your choice. Try again!" << endl;
			break;
		}
		}
	} while (keep_looping);

	return 0;
}

void show_menu()
{
	cout << endl << endl;
	cout << "* -------------------------------------------- *" << endl;
	cout << "* " << setw(20) << "< Welcome to Doubly Linked List System> " << setw(6) << "    *" << endl;
	cout << "* " << setw(20) << "Menu" << setw(26) << "     *" << endl;
	cout << "* " << setw(20) << "Press 1 to add an new element" << setw(17) << " *" << endl;
	cout << "* " << setw(20) << "Press 2 to delete an element" << setw(18) << " *" << endl;
	cout << "* " << setw(20) << "Press 3 to list elements in ascending order" << setw(3) << " *" << endl;
	cout << "* " << setw(20) << "Press 4 to list elements in descending order" << setw(2) << " *" << endl;
	cout << "* " << setw(20) << "Press 5 to quit the program" << setw(19) << " *" << endl;
	cout << "* -------------------------------------------- *" << endl << endl;
}

int check_input(int input)
{
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Please enter a proper integer." << endl;
		cin >> input;
	}
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return input;
}