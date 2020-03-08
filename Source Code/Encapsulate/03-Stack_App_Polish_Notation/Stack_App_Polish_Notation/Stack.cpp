#include "stdafx.h"
#include <iostream>
#include "stack.h"




 // Creat the Stack by pointing its top to NULL.
 void CreateStack(Stack *ps){
   ps->top=NULL;
   ps->size=0;
}

 //-------------------------------------------------
 //pushing an element in the top of the Stack
 void Push(Stack *ps, StackEntry e){
	StackNode *pn = new StackNode();  //=(StackNode*)malloc(sizeof(StackNode));  //for C implementation
	pn->entry=e;
  pn->next=ps->top;
  ps->top=pn;
  ps->size++;
}

 //poping an element from the top of the Stack
 void Pop(Stack *ps, StackEntry *pe){
  StackNode *pn= new StackNode();
  *pe=ps->top->entry;
  pn=ps->top;
  ps->top=ps->top->next;
  free(pn);
  ps->size--;
 }
 
//-----------------------------------------------------------
//Returing the state of the Stack if its empty or not
int StackEmpty(Stack *ps){
	return ps->top==NULL;
}
//Returing the state of the Stack ir its full or not
//and its always not empty because we are not limited with a specifiec size 
//except the size of memory
int StackFull(Stack *ps){
	return 0;
}


//Return the size of the Stack by counting the number nodes in the Stack
int StackSize(Stack *ps){
  return ps->size;
}

//-----------------------------------------------------
//freeing the all nodes in the Stack to be available for the memory 
void ClearStack(Stack *ps){
  StackNode *pn= new StackNode();
	  pn=ps->top;

  while(pn){
    pn=pn->next;	
    free(ps->top);
    ps->top=pn;
  }
  ps->size=0;
}



//Displaying the data in the all nodes in Stack 
void TraverseStack(Stack *ps, void(*pf)(StackEntry)){
  StackNode *pn = new StackNode();

	for(pn=ps->top; pn; pn=pn->next)
		(*pf)(pn->entry);
   
  }




void StackTop(Stack *ps, StackEntry *pe)
{
	*pe = ps->top->entry;
}
