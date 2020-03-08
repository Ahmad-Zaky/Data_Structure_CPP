#include "stdafx.h"
#include <iostream>

using namespace std;


//define the entry data (Encapsulation)
typedef int StackEntry;

// Type Definition "Stack Node".
struct StackNode{
   StackEntry entry;
   StackNode *next;
};

// Type Definition "Stack".
 struct Stack{
   StackNode *top;
   int	size;

};

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



//getting the element from the top without freeing the node
void StackTop(Stack* ps, StackEntry* pe )
{
	*pe = ps->top->entry;
}



void display(StackEntry e)
{
	cout<<e<<endl;
}



int main()
{
	

	Stack s;
	StackEntry e;
	CreateStack(&s);

	int ch;
	while(1)
	{ 
		cout<< " \n\n Stack Operations\n";
		cout<< " 1- Push element into the stack \n 2- Pop element from the stack \n";
		cout<< " 3- Traverse Stack \n 4- Exit\n";
		cout<< "\nYour Choice: "; 
		cin>>ch;

		switch(ch)
		{ 
		case 1: 
			cout<< "\n Put element to Push in the stack: ";
		     cin>>e;
			 if(!StackFull(&s)){
				 Push(&s,e);
				 cout<<"\n The element ("<<e<<") is pushed into the stack";
			 }else
				 cout<<"\n The stack is full. \n";
			break;
		case 2: 
			if(!StackEmpty(&s)){
				Pop(&s,&e);
				cout<<"\n The element ("<<e<<") is poped from the stack \n";
			}else
				cout<<"\n The Stack is Empty. \n";
			break;
		case 3: 
			cout<< "\n Stack elements:\n";
			TraverseStack(&s,display); 
			break;
		case 4: 
			exit(0);
		} // end of switch
	} // end of while loop
	return 0;
}







