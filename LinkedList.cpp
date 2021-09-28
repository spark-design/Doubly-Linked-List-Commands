/*
Student Name: Connor Sparkman
Student NetID: cps260
Compiler Used: Visual Studio
*/
#include "LinkedList.h"
#include <iostream>

using namespace::std;

LinkedList::~LinkedList()
{
	Node* tmp = head;

	while (tmp != nullptr)
	{
		head = head->next;
		delete tmp;
		tmp = head;
	}

	tail = nullptr;
}

void LinkedList::append(string stringData, int data)
{
	Node* tmp = new Node(stringData, data);

	tmp->prev = tail;

	if (head == nullptr)
	{
		head = tmp;
	}
	else
	{
		tail->next = tmp;
	}

	tail = tmp;
}

void LinkedList::prepend(string stringData, int data)
{
	Node *tmp = new Node(stringData, data);

	tmp->next = head;

	if (head == nullptr)
	{
		tail = tmp;
	}
	else
	{
		head->prev = tmp;
	}

	tmp->next = head;

	head = tmp;
}

bool LinkedList::search(int data)
{
	Node *tmp = head;

	while (tmp != nullptr)
	{
		if (tmp->data == data)
		{
			return true;
		}

		tmp = tmp->next;
	}

	return false;
}

bool LinkedList::remove(string stringData)
{
	Node* tmp = head;

	while (tmp != nullptr)
	{
		if (tmp->stringData == stringData) // Finds a string and then removes it
		{
			if (tmp->prev != nullptr)
			{
				tmp->prev->next = tmp->next;
			}
			if (tmp->next != nullptr)
			{
				tmp->next->prev = tmp->prev;
			}
			if (tmp == head)
			{
				head = tmp->next;
			}
			if (tmp == tail)
			{
				tail = tmp->prev;
			}

			delete tmp;
			return true;
		}

		tmp = tmp->next;
	}

	return false;
}

void LinkedList::display()
{
	Node* tmp = head;

	while (tmp != nullptr)
	{
		if (tmp == head)
		{
			cout << "<-[ " << tmp->stringData << " " << tmp->data << " ]<-";
		}
		else if (tmp == tail)
		{
			cout << "->[ " << tmp->stringData << " " << tmp->data << " ]->";
		}
		else
		{
			cout << "->[ " << tmp->stringData << " " << tmp->data << " ]<-";
		}

		tmp = tmp->next;
	}
	cout << endl;
}

void LinkedList::displayReverse()
{
	Node* tmp = tail;

	while (tmp != nullptr)
	{
		if (tmp == tail)
		{
			cout << "<-[ " << tmp->data << " ]<-";
		}
		else if (tmp == head)
		{
			cout << "->[ " << tmp->data << " ]->";
		}
		else
		{
			cout << "->[ " << tmp->data << " ]<-";
		}

		tmp = tmp->prev;
	}
	cout << endl;
}

void LinkedList::displayUntil(int data) // Display events until an event doesn't have the allotted time to run through it completely.
{
	int elapsedTime = 0;
	Node* tmp = head;
	while (elapsedTime <= data) // Loops through until elapsedTime surpasses max time length given by user
	{
		elapsedTime += tmp->data;
		if (elapsedTime <= data) {
			if (tmp == head)
			{
				cout << "<-[ " << tmp->stringData << " " << tmp->data << " ]<-";
			}
			else if (tmp == tail)
			{
				cout << "->[ " << tmp->stringData << " " << tmp->data << " ]->";
			}
			else
			{
				cout << "->[ " << tmp->stringData << " " << tmp->data << " ]<-";
			}
			tmp = tmp->next;
		}
		
	}
	cout << endl;
}

bool LinkedList::find(string stringData)
{
	Node *tmp = head;

	while (tmp != nullptr) // Loops through until given string is found
	{
		if (tmp->stringData == stringData)
		{
			cout << "<-[ " << tmp->stringData << " " << tmp->data << " ]<-" << endl;
			return true;
		}
		tmp = tmp->next;
	}
	return false;
}

void LinkedList::length()
{
	int elapsedTime = 0;
	Node* tmp = head;
	while (tmp != nullptr) // Loops through, adding time to elapsedTime
	{
		elapsedTime += tmp->data;
		tmp = tmp->next;
	}
	cout << "Length: " << elapsedTime << endl;
}

bool LinkedList::insertBefore(string stringData, int data, string stringData2)
{
	Node* tmp = head; // Loops through every node
	while (tmp != nullptr)
	{
		if (tmp->stringData == stringData2) // Tries to find specific event
		{
			if (tmp == head)
			{
				prepend(stringData, data);
			}
			else
			{
				Node* tmpInsert = new Node(stringData, data);
				tmpInsert->prev = tmp->prev; // Set new node's next and previous pointers
				tmpInsert->next = tmp;

				tmp->prev->next = tmpInsert;
				tmp->prev = tmpInsert;
			}
			return true;
		}
		tmp = tmp->next;
	}
	return false;
}

bool LinkedList::insertAfter(string stringData, int data, string stringData2)
{
	Node* tmp = head;
	while (tmp != nullptr) // Loops through every node
	{
		if (tmp->stringData == stringData2) // Tries to find specific event
		{
			if (tmp == tail)
			{
				append(stringData, data);
			}
			else 
			{
				Node* tmpInsert = new Node(stringData, data);
				tmpInsert->next = tmp->next; // Set new node's next and previous pointers
				tmpInsert->prev = tmp;


				tmp->next->prev = tmpInsert;
				tmp->next = tmpInsert;
			}
			return true;
		}
		tmp = tmp->next;
	}
	return false;
}