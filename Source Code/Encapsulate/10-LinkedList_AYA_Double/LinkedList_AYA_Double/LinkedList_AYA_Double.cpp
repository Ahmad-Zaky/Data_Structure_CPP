// LinkedList_AYA_Double.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <iostream>
#include "list.h"

using namespace std;
void display(ListEntry e)
{
	cout<<e<<endl;
}


int main()
{
	List l;
	ListEntry e ;
	int pos;
	CreatList(&l);
	
		for(int i=0 ; i < 10 ; i++){
			cout<<"Enter your element:";
			cin>>e;
			cout<<"Enter your pos:";
			cin>>pos;
			InsertList(pos,e,&l);
			
		} 
	DestroyList(&l);
		e = 1;
		InsertList(0,e,&l);

	TraverseList(&l,display);
	return 0;
}


