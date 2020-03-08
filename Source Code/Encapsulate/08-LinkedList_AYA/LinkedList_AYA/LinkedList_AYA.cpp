// LinkedList_AYA.cpp : Defines the entry point for the console application.
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
	/*List l;
	ListEntry e ;
	int pos;
	CreatList(&l);
	
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
	return 0;*/
	//-------------------------------------------------------
	////Example program to test JoinList Function
	List l1;
	List l2;
	CreatList(&l1);
	CreatList(&l2);
	
	ListEntry e;

	e=1;
	//InsertList(0,e,&l1);
	
	e=2;
	InsertList(0,e,&l2);

	JoinList(&l1,&l2);

	TraverseList(&l1, display);

}

