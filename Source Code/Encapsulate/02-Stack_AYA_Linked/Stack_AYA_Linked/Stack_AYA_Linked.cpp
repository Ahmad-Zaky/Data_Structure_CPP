// Stack_AYA_Linked.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "stack.h"


using namespace std;
void display(StackEntry e)
{
	cout<<e<<endl;
}

int main()
{
	
	/*Stack s;
	StackEntry e;
	CreateStack(&s);
	
	for(int i=0 ; i < 10 ; i++)
	{
	cout<<"Enter your element: ";
	cin>>e;
	Push(&s,e);
	}
	TraverseStack(&s,display);

	return 0;*/
	//-----------------------------------------------------------

	Stack s;
	StackEntry e;
	CreateStack(&s);

	int ch;
	while(1)
	{ 
		cout<< " \n\n Stack Operations\n";
		cout<< " 1- Push an element into the stack \n 2- Pop element from the stack \n";
		cout<< " 3- Traverse Stack \n 4- Exit\n";
		cout<< "\nYour Choice: "; 
		cin>>ch;

		switch(ch)
		{ 
		case 1: 
			 cout<< "\n Put element to Push it into the stack: ";
		     cin>>e;
			 if(!StackFull(&s)){
				 Push(&s,e);
				 cout<<"\n The element ("<<e<<") is pushed into the stack";
			 }else
				 cout<<"\n The stack is full. \n";
			break;
		case 2: 
			if(!StackEmpty(&s)){
				Pop(&s,&e);
				cout<<"\n The element ("<<e<<") is poped from the stack \n";
			}else
				cout<<"\n The Stack is Empty. \n";
			break;
		case 3: 
			cout<< "\n Stack elements:\n";
			TraverseStack(&s,display); 
			break;
		case 4: 
			exit(0);
		} // end of switch
	} // end of while loop
	return 0;
}

