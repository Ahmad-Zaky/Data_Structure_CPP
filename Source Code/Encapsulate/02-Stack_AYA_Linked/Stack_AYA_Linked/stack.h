#include "stdafx.h"

typedef int StackEntry;

// Type Definition "Stack Node & Stack".
struct StackNode{
   StackEntry entry;
   StackNode *next;
};

 struct Stack{
   StackNode *top;
   int	size;

};


void	CreateStack		(Stack *);
void	Push			(Stack *, StackEntry);
void	Pop				(Stack *, StackEntry *);
int		StackEmpty		(Stack *);
int		StackFull		(Stack *);
int		StackSize		(Stack *);
void	ClearStack		(Stack *);
void	TraverseStack	(Stack *, void (*)(int));
void	StackTop		(Stack *, StackEntry *);