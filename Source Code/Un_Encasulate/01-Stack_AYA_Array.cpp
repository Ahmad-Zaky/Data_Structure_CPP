// Stack_AYA_Array.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;


//define the max size for the Queue
#define MAXSTACK 100

//define the entry type
typedef int StackEntry;

// Type Definition "Stack".
struct Stack{
   int top;
   StackEntry entry[MAXSTACK];
};

//-------------------------------------------
//-------------------------------------------


// Create the Stack by pointing its top to 0(index).
void CreateStack(Stack *s){
   s->top=0;
}

//-------------------------------------------------
 //pushing an element on the top of the Stack
void Push(Stack *ps, StackEntry e){
	//insert the new stack_entry on the top of the stack
	ps->entry[ps->top]=e;   //we can minimize the code in one line like thisi:
							//ps->entry[ps->top++]=e;
	//increment the top by one
	ps->top++;
}

//poping an element from the top of the Stack
void Pop(Stack *ps, StackEntry *pe){
 
	//minimize the top by one indicating deletion but actual its not deleted
	ps->top--; 				//we can minimize the code in one line like this:
							//  *pe=ps->entry[--ps->top];
  
  //get the element from the deleted stack_entry and return it to the user
  *pe=ps->entry[ps->top];	

}

//-----------------------------------------------------------
//Returing the state of the Stack if its full or not
int StackFull(Stack *ps){
	return ps->top >= MAXSTACK;
}

//Returing the state of the Stack ir its empty or not
int StackEmpty(Stack *ps){
	return !ps->top;
}


//getting the element from the top without freeing the node
void StackTop(Stack *ps, StackEntry *pe){
	*pe=ps->entry[ps->top-1];
}


//Return the size of the Stack by retuning the top index which refere to the no. of element in the Stack
int StackSize(Stack *ps){
   return ps->top;
}

//Clearing the stack by pointing the top to 0(index)
void ClearStack(Stack *ps){
   ps->top=0;
}

//Displaying the data from the Stack element by element
void TraverseStack(Stack *ps, void(*pf)(StackEntry)){
   for(int i=ps->top; i>0; i--)
      (*pf)(ps->entry[i-1]);

}

//-------------------------------------------
//-------------------------------------------
void display(StackEntry e)
{
	cout<<e<<endl;
}

int main()
{
	
	Stack s;
	StackEntry e;
	CreateStack(&s);
	
	for(int i=0 ; i < 10 ; i++)
	{
	cin>>e;
	Push(&s,e);
	}
	TraverseStack(&s,display);

	return 0;
}


