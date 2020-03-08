#include "stdafx.h"
#include <iostream>
#include "stack.h"





 // Create the Stack by pointing its top to NULL.
 void CreateStack(Stack *ps){
   ps->top=NULL;
   ps->size=0;
}

 //-------------------------------------------------
 //pushing an element on the top of the Stack
 void Push(Stack *ps , StackEntry e){
	//Step 1: Create new stacknode 
	 StackNode *pn = new StackNode(); //=(StackNode*)malloc(sizeof(StackNode));  //for C implementation
	//and put the element in the entry part of the new node 
	 pn->entry=e;
  //Step 2: insert the new stacknode on the top of the stack
  pn->next=ps->top;
  ps->top=pn;
 //increment the size by one
  ps->size++;
}

 //poping an element from the top of the Stack
 void Pop(Stack *ps , StackEntry *pe){
  
  //Step 1: get the element from the deleted node and return it to the user
  StackNode *pn;
  pn=ps->top;
  *pe=pn->entry;
  
  //Step 2: free the deleted node from the memory and get it out from the stack
  ps->top=pn->next;
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
  StackNode *pn;
	  pn=ps->top;

  while(ps->top){
    ps->top=pn->next;	
    free(pn);
    pn=ps->top;
  }
  ps->size=0;
}



//Displaying the data in the all nodes the Stack 
void TraverseStack(Stack *ps, void(*pf)(StackEntry)){
  StackNode *pn;

	for(pn=ps->top; pn; pn=pn->next)
		(*pf)(pn->entry);
   
  }

//returning the top element on the Stack without deleting it
void StackTop(Stack* ps, StackEntry* pe )
{
	*pe = ps->top->entry;
}
