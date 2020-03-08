#include "stdafx.h"
#include <iostream>
#include "list.h"

void CreatList(List *pl)
{
	pl->current = NULL;
	pl->currentpos = 0;
	pl->size = 0;
}

void InsertList(int pos, ListEntry e,List *pl)
{
	
	ListNode *p = new ListNode();
	
	p->entry=e;
	p->next=NULL;
	p->back=NULL;
	

		if(pos <= pl->currentpos)
		{
			
		//-------------------------------------------------------
			for(;pl->currentpos != pos ; pl->currentpos--)
				pl->current = pl->current->back;
			
			if(!pl->current){
				pl->current = p;
			}else{
				
				if(pos == 0){
				p->next = pl->current;
				pl->current->back = p;
				pl->current = p;
			
			}else{
			pl->current->back->next = p ;
			p->back = pl->current->back;
			p->next = pl->current;
			pl->current->back = p;
				}
			
			}
		//------------------------------------------------------------
			
		}else{

		//-------------------------------------------------------
		for( ; pl->currentpos != pos-1 ; pl->currentpos++ )
			pl->current = pl->current->next;
		if(pos == pl->size)
		{
			pl->current->next = p;
			p->back = pl->current;

		}else{
		
			pl->current->next = p ;
			p->back = pl->current;
			p->next = pl->current->next;
			pl->current->next->back = p;
		}
		//-------------------------------------------------------
		
		}

		
	pl->size++;
}

void DeleteList(int pos, ListEntry *pe, List *pl)
{
	if(pos <= pl->currentpos)
	{
		for(;pl->currentpos != pos ; pl->currentpos--)
			pl->current = pl->current->back;

		if(pos == 0)
		{
			*pe = pl->current->entry;
			pl->current = pl->current->next;
			free(pl->current);
		}else{
		*pe = pl->current->entry;
		pl->current->back->next = pl->current->next;
		pl->current->next->back = pl->current->back;
		free(pl->current);
		}

	}else{
		
		for(; pl->currentpos != pos-1 ; pl->currentpos++)
			pl->current = pl->current->next;
		

		*pe = pl->current->next->entry;
		if(pos = pl->size-1)
		{
			pl->current->next = NULL; //or pl->current->next = pl->current->next->next;
			free(pl->current->next);
		}else{
		pl->current->next = pl->current->next->next;
		pl->current->next->next->back = pl->current;
		free(pl->current->next);
		}
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
	ListNode *tmp;
	for(;pl->currentpos != 0 ; pl->currentpos--)
		pl->current = pl->current->back;

	while(pl->current){
		tmp = pl->current->next;
		free(pl->current);
		pl->current = tmp;
	}
	pl->size=0;
}

void TraverseList(List *pl,void(*Visit)(ListEntry))
{
	for(;pl->currentpos != 0 ; pl->currentpos--)
		pl->current = pl->current->back;

	ListNode *p = pl->current;
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
			for(;pl->currentpos != pos ; pl->currentpos--)
				pl->current = pl->current->back;
			
			*pe = pl->current->entry;
	}else{
		for(; pl->currentpos != pos ; pl->currentpos++)
			pl->current = pl->current->next;

		*pe = pl->current->entry;
	}
}

void ReplaceList(int pos, ListEntry e, List *pl)
{
	if(pos <= pl->currentpos)
		{
			for(;pl->currentpos != pos ; pl->currentpos--)
				pl->current = pl->current->back;
			
			 pl->current->entry = e;
	}else{
		for(; pl->currentpos != pos ; pl->currentpos++)
			pl->current = pl->current->next;

		 pl->current->entry = e;
	}
}