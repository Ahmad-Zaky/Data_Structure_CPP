// LinkedList_SO.cpp : Defines the entry point for the console application.
// A Program that exercise the operations on Liked List
// Programed by SHAHID LONE

#include "stdafx.h"
#include<iostream>
using namespace std;


//Define the 'node' type
struct node
{
	int info;
	node *next;
};

//Define the head which piont to the first node in the list
struct node *Head=NULL;
//Define the Prev and Curr Pointers which we use it to insert and delete from the list 
struct node *Prev,*Curr;

//Inserting an element into the list
void AddNode(int ITEM)
{
	//Create a new node in the memory and return its address to 'NewNode' pionter 
	node *NewNode = new node;
	NewNode->info=ITEM; 
	NewNode->next=NULL;
	
	//Case 1: the List is empty
	if(Head==NULL) 
	{ 
		//we piont Head to the newnode
		Head=NewNode; 
		//get out from the AddNode function
		return; 
	}
	//Case 2: the List is not empty
	
	//insert at the first
	if(NewNode->info < Head->info)
	{ 
		NewNode->next = Head; 
		Head=NewNode; 
		return;
	}

	//we make a loop to reach the node which we insert after it
	Prev=Curr=NULL;
	for(Curr = Head ; Curr != NULL ; Curr = Curr ->next)
	{
		//break the for loop if the information (info) of the Curr is larger than the information (info) of the NewNode
		if( Curr ->info > NewNode->info) 
			break;
		else 
			Prev = Curr;
	}
	//insert at the middle or the end
	NewNode->next = Prev->next;
	Prev->next = NewNode;
} // end of AddNode function

void DeleteNode()
{ 
	int inf;
	
	//Case 1: the list is empty
	if(Head==NULL)
	{ 
		cout<< "\n\n Empty Linked List\n"; 
		return;
	}

	//case 2: the list is not empty
	cout<< "\n Put The Info to Delete: ";
	cin>>inf;
	
	//delete from the first
	if(inf == Head->info)
	{ 
		Head = Head->next; 
		return;
	}

	//we make a loop to reach the deleted node
	Prev = Curr = NULL;
	for(Curr = Head ; Curr != NULL ; Curr = Curr ->next )
	{
		if(Curr ->info == inf) 
			break;
		Prev = Curr;
	}

	//if Curr equal to NULL then info which the user was eneterd its value is not in the list
	if( Curr == NULL)
		cout<<inf<< " Not Found in List \n";
	//delete from the middle or the end
	else
	{ 
		Prev->next = Curr->next; 
	}
}// end of DeleteNode function


//Display the information (inf) from the list
void Traverse()
{
	for(Curr = Head; Curr != NULL ; Curr = Curr ->next )
		cout<< Curr ->info<<"\t";
} // end of Traverse function


//main function which are the test program to use the General List
int main()
{ 
	int inf, ch;
	while(1)
	{ 
		cout<< " \n\n Linked List Operations\n";
		cout<< " 1- Add Node \n 2- Delete Node \n";
		cout<< " 3- Traverse List \n 4- Exit\n";
		cout<< "\nYour Choice: "; 
		cin>>ch;
		switch(ch)
		{ 
		case 1: 
			cout<< "\n Put info/value to Add: ";
		     cin>>inf;
			AddNode(inf);
			break;
		case 2: 
			DeleteNode(); 
			break;
		case 3: 
			cout<< "\n Linked List Values:\n";
			Traverse(); 
			break;
		case 4: 
			exit(0);
		} // end of switch
	} // end of while loop
	return 0;
} // end of main ( ) function



