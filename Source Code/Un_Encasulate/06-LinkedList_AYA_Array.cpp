// LinkedList_AYA_Array.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"	
#include <iostream>

using namespace std;


#define MAXLIST 100
typedef int ListEntry;

struct List{
	ListEntry entry[MAXLIST];
	int size;
};
//-------------------------------------------
//-------------------------------------------



void CreateList(List *pl){
	pl->size=0;
}


/*0 <= p <= size*/
void InsertList(int p, ListEntry e, List *pl){
	int i;
	/*The loop shifts up all the elements in 	the range [p, size-1] to free the pth 	location*/
	for(i=pl->size-1; i>=p; i--)
		pl->entry[i+1]=pl->entry[i];
	pl->entry[p]=e;
	pl->size++;
}


/*0<= p <= size-1 and List not empty*/
void DeleteList(int p, ListEntry *pe, List *pl){
	int i;
	*pe=pl->entry[p];
	/*The loop shifts down all the elements in 	the range [p+1, size-1] to free the pth 	location*/
	for(i=p+1; i<=pl->size-1; i++)
		pl->entry[i-1]=pl->entry[i];
	pl->size--;
}




int ListEmpty(List *pl){
	return !pl->size;
}


int ListFull(List *pl){
	return pl->size==MAXLIST;
}

int ListSize(List *pl){
	return pl->size;
} 

void DestroyList(List *pl){
	pl->size=0;
} 

void RetrieveList(int p, ListEntry *pe, List *pl){
	*pe=pl->entry[p];
} 


/* 0<= p <= size-1*/
void ReplaceList(int p, ListEntry e, List *pl){
	pl->entry[p]=e;
} 


void TraverseList(List* pl, void (*Visit)(ListEntry)){
	int i;
	for(i=0; i<pl->size; i++)
		(*Visit)(pl->entry[i]);
}


//-------------------------------------------
//-------------------------------------------

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

