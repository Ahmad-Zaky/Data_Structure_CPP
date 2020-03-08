// LinkedList_AYA_Enhanced.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>

typedef int ListEntry;

struct ListNode
{
	ListEntry entry;
	ListNode *next;
};

struct List
{
	ListNode *head, *current;
	int size, currentpos;
};



void CreatList(List *pl)
{
	pl->head = NULL;
	pl->size = 0;
}

void InsertList(int pos, ListEntry e,List *pl)
{
	
	ListNode *p = new ListNode();
	
	p->entry=e;
	p->next=NULL;

	if (pos == 0)
	{
		p->next = pl->head;
		pl->head = p;
		pl->currentpos = 0;//new
		pl->current = pl->head; //new
	}else{
		if(pos <= pl->currentpos)
		{
		pl->currentpos = 0;//new
		pl->current = pl->head; //new
		}
		
		for( ; pl->currentpos < pos-1 ; pl->currentpos++ )
			pl->current = pl->current->next;
		p->next = pl->current->next;
		pl->current->next = p;
	}
	pl->size++;
}

void DeleteList(int pos, ListEntry *pe, List *pl)
{
	
	ListNode *tmp;

	if(pos == 0)
	{
		*pe = pl->head->entry;
		pl->current = pl->head->next;
		free(pl->head);
		pl->head = pl->current;
		pl->currentpos = 0;
	}else{
		if(pos <= pl->currentpos)
		{
		pl->currentpos = 0;//new
		pl->current = pl->head; //new
		}
		for(; pl->currentpos<pos-1 ; pl->currentpos++)
			pl->current = pl->current->next;
		

		*pe = pl->current->next->entry;
		tmp = pl->current->next->next;
		free(pl->current->next);
		pl->current->next = tmp;
	}
	pl->size--;

}


int ListEmpty(List *pl)
{
	return (pl->size == 0);
}

int ListFull(List *pl)
{
	return 0;
}

int ListSize(List *pl)
{
	return pl->size;
}

void DestroyList(List *pl)
{
	ListNode *q;
	while(pl->head){
		q=pl->head->next;
		free(pl->head);
		pl->head=q;
	}
	pl->size=0;
}

void TraverseList(List *pl,void(*Visit)(ListEntry))
{
	ListNode *p = pl->head;
	while(p)
	{
		(*Visit)(p->entry);
		p=p->next;
	}
}

void RetrieveList(int pos, ListEntry *pe, List *pl)
{
	
	
	if(pos <= pl->currentpos)
		{
		pl->currentpos = 0;//new
		pl->current = pl->head; //new
		}
	for(; pl->currentpos < pos ; pl->currentpos++)
		pl->current = pl->current->next;

	*pe = pl->current->entry;
}

void ReplaceList(int pos, ListEntry e, List *pl)
{
	
	if(pos <= pl->currentpos)
		{
		pl->currentpos = 0;//new
		pl->current = pl->head; //new
		}
	for(; pl->currentpos < pos ; pl->currentpos++)
		pl->current = pl->current->next;

	pl->current->entry = e ;
	
}

//--------------------------------------------------------


using namespace std;
//void display(ListEntry e)
//{
//	cout<<e<<endl;
//}


int main()
{
	///*List l;
	//ListEntry e ;
	//int pos;
	//CreatList(&l);
	//
	//	for(int i=0 ; i < 10 ; i++){
	//		cout<<"Enter your element:";
	//		cin>>e;
	//		cout<<"Enter your pos:";
	//		cin>>pos;
	//		InsertList(pos,e,&l);
	//		DeleteList(pos,&e,&l);
	//	} 
	//e = 0;
	//InsertList(0,e,&l);
	//TraverseList(&l,display);
	//return 0;*/
}


