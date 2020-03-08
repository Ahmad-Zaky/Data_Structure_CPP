#include "stdafx.h"

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

void CreatList(List* );
void InsertList(int , ListEntry ,List *);
void DeleteList(int , ListEntry *, List *);
int ListEmpty(List *);
int ListFull(List *);
int ListSize(List *);
void DestroyList(List *);
void TraverseList(List *,void(*)(ListEntry));
void RetrieveList(int , ListEntry *, List *);
void ReplaceList(int , ListEntry , List *);
