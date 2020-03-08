#include "stdafx.h"
#define MAXSTACK 100

typedef int StackEntry;


struct Stack{
   int top;
   StackEntry entry[MAXSTACK];
};


void	Push			(Stack *, StackEntry);
void	Pop				(Stack *, StackEntry *);
int		StackEmpty		(Stack *);
int		StackFull		(Stack *);
void	CreateStack		(Stack *);
void	StackTop		(Stack *, StackEntry *);
int		StackSize		(Stack *);
void	ClearStack		(Stack *);
void	TraverseStack	(Stack *, void (*)(StackEntry));
