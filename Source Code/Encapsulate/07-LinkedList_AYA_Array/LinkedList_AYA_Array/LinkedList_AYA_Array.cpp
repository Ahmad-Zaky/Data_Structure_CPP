// LinkedList_AYA_Array.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"	
#include <iostream>
#include "list.h"

using namespace std;

void display(ListEntry e)
{
	cout<<e<<endl;
}


void main()
{
	List l;
	ListEntry e ;
	int pos;
	CreateList(&l);
	
		for(int i=0 ; i < 10 ; i++){
			cout<<"Enter your element:";
			cin>>e;
			cout<<"Enter your pos:";
			cin>>pos;
			InsertList(pos,e,&l);
			DeleteList(pos,&e,&l);
		}

	e = 0;
	InsertList(0,e,&l);
	TraverseList(&l,display);

}

