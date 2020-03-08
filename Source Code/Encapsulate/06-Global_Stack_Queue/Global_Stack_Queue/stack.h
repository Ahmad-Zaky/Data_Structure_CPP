#include "stdafx.h"
#include "global.h"

// Type Definition "Stack Node & Stack".
struct StackNode{
   StackEntry entry;
   StackNode *next;
};

 struct Stack{
   StackNode *top;
   int	size;

};


void	CreateStack(Stack *);
void	Push(StackEntry, Stack *);
void	Pop(StackEntry *, Stack *);
int	StackEmpty(Stack *);
int	StackFull(Stack *);
int	StackSize(Stack *);
void	ClearStack(Stack *);
void	TraverseStack(Stack *, void (*)(int));
void	StackTop(int *, Stack *);