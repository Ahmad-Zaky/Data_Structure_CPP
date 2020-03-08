// LinkedList_AYA.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


using namespace std;

//define the entry data (Encapsulation)
typedef int ListEntry;



// Type Definition "List Node".
struct ListNode
{
	ListEntry entry;
	ListNode *next;
};



// Type Definition "List".
struct List
{
	ListNode *head;
	int size;
};

// Creat the Queue by pointing its front and rear to NULL.
void CreateList(List *pl)
{
	pl->head = NULL;
	pl->size = 0;
}

//Appending a list to the end of another list
void JoinList(List *pl1, List *pl2)
{
	ListNode *pn = pl1->head;
	//Join if the list_2 is empty or not
	if(pn){

	while(pn->next)
		pn=pn->next;

	pn->next = pl2->head;
	}
	//Join if the list_1 is empty 
	if( (!pn) && (pl2->head) )
		*pl1 = *pl2;
}

//Inserting an element in the list according to its position
void InsertList(int pos, ListEntry e,List *pl)
{
	//Step 1: Create new listnode and put the element in the entry part of the new node 
	int i;
	ListNode *p = new ListNode() , *q ;
	
	p->entry=e;
	p->next=NULL;
	//Step 2: insert the new listnode in its position in the list

	//first case: inserting at the front of the list (pos == 0)
	if (pos == 0)
	{
		p->next = pl->head;
		pl->head = p;
	}
	//second case: inserting at the middle or the end of the list (pos = 'some other integer value between the boundry of the list')
	else{
		for(q=pl->head, i=0 ; i<pos-1 ; i++ )
			q=q->next;
		p->next = q->next;
		q->next = p;
		}
	pl->size++;
}


//Deleting an element from the list according to its position
void DeleteList(int pos, ListEntry *pe, List *pl)
{
	int i;
	ListNode *q,*tmp;

	//first case: delete from the front(pos == 0)
	if(pos == 0)
	{
		*pe = pl->head->entry;
		tmp = pl->head->next;
		free(pl->head);
		pl->head = tmp;
	}
	//second case: delete from the middle or the end(pos = 'some other integer value between the boundry of the list')
	else{
	for(q=pl->head , i=0 ; i<pos-1 ; i++)
		q=q->next;

	*pe = q->next->entry;
	tmp = q->next->next;
	free(q->next);
	q->next=tmp;
	}
	pl->size--;

}

//Returing the state of the List if its empty or not
int ListEmpty(List *pl)
{
	return (pl->size == 0);
}

//Returing the state of the List if its full or not
//and its always not empty because we are not limited with a specifiec size 
//except the size of memory
int ListFull(List *pl)
{
	return 0;
}
//Return the size of the List by counting the number of nodes in List
int ListSize(List *pl)
{
	return pl->size;
}
//-----------------------------------------------------
//freeing the all nodes in the Queue to be available for the memory 
void DestroyList(List *pl)
{
	ListNode *q;
	while(pl->head){
		q=pl->head->next;
		free(pl->head);
		pl->head=q;
	}
	pl->size=0;
}/*Moving with two pointers,
   Exactly as in Linked Stack and Queue*/


//Displaying the data in the all nodes in List
void TraverseList(List *pl,void(*Visit)(ListEntry))
{
	ListNode *p = pl->head;
	while(p)
	{
		(*Visit)(p->entry);
		p=p->next;
	}
}
//Returning an element from the List by its position
void RetrieveList(int pos, ListEntry *pe, List *pl)
{
	int i;
	ListNode *q;
	for(q=pl->head , i=0 ; i<pos ; i++)
		q=q->next;
	*pe = q->entry;
}

//Replacing an element from the List by another element using its position
void ReplaceList(int pos, ListEntry e, List *pl)
{
	int i;
	ListNode *q;
	for(q=pl->head , i=0 ; i<pos ; i++)
		q=q->next;
	q->entry = e;
}


//-----------------------------------------------------------------


static int i =0;

void display(ListEntry e)
{
	
	cout<<i<<setw(15)<<e<<endl;
	i++;
}


void main()
{
	List l;
	ListEntry e ;
	int pos;
	CreateList(&l);
	
	for(int i=0 ; i < 5 ; i++){
		cout<<"Enter your element:";
		cin>>e;
		cout<<"Enter your pos:";
		cin>>pos;
		
		if( pos > (ListSize(&l)) ){
			cout<<"This position is out of boundary. \nEnter another position: ";
			cin>>pos;
			}
			InsertList(pos,e,&l);;
	}
			
		cout<<"Position"<<setw(15)<<"element\n\n";
		TraverseList(&l,display);
			
		cout<<"Enter the pos of Deleted Node: ";
		cin>>pos;
		if( pos > (ListSize(&l)) ){
			cout<<"This position is not exist to be deleted \n Enter another postion to delete: ";
			cin>>pos;
		}
		DeleteList(pos,&e,&l);
			
	
	cout<<"\n\nThe List contain Now ("<<ListSize(&l)<<") elements.\n";
	//-------------------------------------------------------
	////Example program to test JoinList Function
	//List l1;
	//List l2;
	//CreateList(&l1);
	//CreateList(&l2);
	//
	//ListEntry e;

	//e=1;
	////InsertList(0,e,&l1);
	//
	//e=2;
	//InsertList(0,e,&l2);

	//JoinList(&l1,&l2);

	//TraverseList(&l1, display);


}

