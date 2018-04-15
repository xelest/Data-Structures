//Practice Singly Linked List
//Created by: Mark Anthony Hernandez
//Create, Insert, Add, Delete, View, Traversal

#include <stdio.h>
#include <iostream>
#include <string>
#include <iomanip> // for presentation formatting
#include <conio.h>

using namespace std;

struct Node
{
	Node *next;
	Node *prev;
	string location;
	string name;
	int distance;

}*newNode, *head = NULL, *tail, *current;

void getdata() // lets create a function to get data whenever we initialize an instance
{
	cout << "\n\t enter name: ";
	cin >> newNode->name;
	cout << "\t enter distance: ";
	cin >> newNode->distance;
}

void inserttail() // we created a function so that we can adjust later what kind of manner will the insertion be
{
	current = tail;
	newNode = new Node;
	newNode->next = NULL;
	newNode->prev = NULL;
	current->next = newNode;
	newNode->prev = current;
	current = newNode;
	tail = newNode;
	getdata();
}

void inserthead() // it will just be the same with tail only this time we move the head
{
	current = head;
	newNode = new Node;
	newNode->next = NULL;
	newNode->prev = NULL;
	current->prev = newNode;
	newNode->next = current;
	current = newNode;
	head = newNode;
	getdata();
}

void addnewdata() // this function creates a new instance 
{
	if (head == NULL) // lets check first if the list is empty or not , if empty the first data will go to head
	{
		newNode = new Node;
		newNode->next = NULL;
		newNode->prev = NULL;
		head = newNode;
		tail = newNode;
		current = newNode;
		current->next = NULL; //safety precaution to make certain that the current next and previous are set NULL
		current->prev = NULL;
		getdata();
	}
	else // if not, insertion is made at the end of the list
	{
		inserttail();
	}

}

void viewlist() //lets try to create a function to view our list
{
	current = head;
	if (head == NULL)
	{
		cout << "\t list is empty. try to create new entry. thank you" << endl;
		cout << "\n\t Console Message: "; system("pause");
	}
	else
	{
		while (current != NULL)
		{
			cout << endl << "\t " << current->name << setw(5) << " " << "\t " << setw(3) << current->distance;
			current = current->next; //forward manner of moving the pointer
		}
	}
}

void reverseview() // to ensure that all nodes are connected safely lets use this reverse view list
{					// but this time lets start from the tail to head
	current = tail;
	if (head == NULL)
	{
		cout << "\t list is empty. try to create new entry. thank you" << endl;
		cout << "\n\t Console Message: "; system("pause");
	}
	else
	{
		while (current != NULL)
		{
			cout << endl << "\t " << current->name << setw(5) << " " << "\t " << setw(3) << current->distance;
			current = current->prev; // reversed manner of moving
		}
	}
}

void delend() // basically if youre deleting at the end or at the front just move head or tail
{
	tail = tail->prev;
}

void delfront()
{
	head = head->next;
}

void moveto(string loc)
{

	while (current)
	{
		if (current->location == loc)
		{

		}
		else
		{
			current = current->next;
		}
	}


}

void menu() // lets display a menu of choices for our user
{
	system("cls");
	cout << "\n\t [1]. add a new entry";
	cout << "\n\t [2]. insert to the start of the list. head.";
	cout << "\n\t [3]. insert to the end of the list. tail.";
	cout << "\n\t [4]. delete at the end of the list. tail.";
	cout << "\n\t [5]. delete at the front of the list. head.";
	cout << "\n\t [6]. view - head to tail";
	cout << "\n\t [7]. view - tail to head (revese)";
	cout << "\n\t [0]. exit";

	cout << "\n\n\t choice: ";
}


int main() // now that we're done with that lets test our doubly linked list
{
	int choice;
	do
	{
		system("cls");
		menu();
		cin >> choice;

		if (choice == 1)
		{
			addnewdata();
		}
		else if (choice == 2)
		{
			inserthead();
		}
		else if (choice == 3)
		{
			inserttail();
		}
		else if (choice == 4)
		{
			delend();
		}
		else if (choice == 5)
		{
			delfront();
		}
		else if (choice == 6)
		{
			viewlist(); cout << endl << "\t"; system("pause");
		}
		else if (choice == 7)
		{
			reverseview(); cout << endl << "\t"; system("pause");
		}
		else // last else. if the answer is none of the above
		{
			cout << "\t invalid choice. please try again." << endl;
			cout << "\t "; system("pause");
		}

		cout << "thank you. bye"; // lets leave this message to tell the user that he is already exiting
	} while (choice != 0);


	_getche();
}
