// Queue_AYA_Linked.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "queue.h"

using namespace std;

void display(QueueEntry e)
{
	cout<<e<<endl;
}

int main()
{
	/*Queue q;
	int j = 0;
	QueueEntry e = 10;
	CreateQueue(&q);
	
	for(int i=0 ; i < 10 ; i++)
	{
	cout<<"Enter your element: ";
	cin>>e;
	Append(&q,e);
	}

	TraverseQueue(&q,display);

	return 0;*/

	//-----------------------------------------------------

		Queue q;
		QueueEntry e ;
		CreateQueue(&q);

		int ch;
		while(1)
		{ 
			cout<< " \n\n Queue Operations\n";
			cout<< " 1- Append element into the queue \n 2- Serve element from the queue \n";
			cout<< " 3- Traverse queue \n 4- Exit\n";
			cout<< "\nYour Choice: "; 
			cin>>ch;

			switch(ch)
			{ 
			case 1: 
				cout<< "\n Put an element to Append it into the queue: ";
				 cin>>e;
				 if(!QueueFull(&q)){
					 Append(&q,e);
					 cout<<"\n The element ("<<e<<") is Appended into the queue";
				 }else
					 cout<<"\n The queue is full. \n";
				break;
			case 2: 
				if(!QueueEmpty(&q)){
					Serve(&q,&e);
					cout<<"\n The element ("<<e<<") is Served from the queue \n";
				}else
					cout<<"\n The Queue is Empty. \n";
				break;
			case 3: 
				cout<< "\n Queue elements:\n";
				TraverseQueue(&q,display); 
				break;
			case 4: 
				exit(0);
			} // end of switch
		} // end of while loop

		return 0;


}

