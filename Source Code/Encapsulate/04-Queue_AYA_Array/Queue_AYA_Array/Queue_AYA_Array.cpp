// Queue_AYA_Array.cpp : Defines the entry point for the console application.
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
	Queue q;
	int j = 0;
	QueueEntry e = 10;
	CreateQueue(&q);
	
	for(int i=0 ; i < 10 ; i++)
	{
	cin>>e;
	Append(&q,e);
	}

	TraverseQueue(&q,display);

	return 0;
}

