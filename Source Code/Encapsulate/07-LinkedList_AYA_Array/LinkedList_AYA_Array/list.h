#include "stdafx.h"

#define MAXLIST 100
typedef int ListEntry;

struct List{
	ListEntry entry[MAXLIST];
	int size;
};


void CreateList		(List* );
void InsertList		(int , ListEntry ,List *);
void DeleteList		(int , ListEntry *, List *);
int	 ListEmpty		(List *);
int  ListFull		(List *);
int  ListSize		(List *);
void DestroyList	(List *);
void TraverseList	(List *,void(*)(ListEntry));
void RetrieveList	(int , ListEntry *, List *);
void ReplaceList	(int , ListEntry , List *);