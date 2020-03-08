// Stack_AYA_Array.cpp : Defines the entry point for the console application.
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
	
	Stack s;
	StackEntry e;
	CreateStack(&s);
	
	for(int i=0 ; i < 10 ; i++)
	{
	cin>>e;
	Push(&s,e);
	}
	TraverseStack(&s,display);

	return 0;
}


