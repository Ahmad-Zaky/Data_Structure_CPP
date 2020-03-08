#include "stdafx.h"



//Define the element type as struct because we want to use the stack two times 
//with diffrent type for the entry at eack time
struct ElementType{
//short int  etype; 
   
     char character;
     double number;
};

typedef ElementType StackEntry;

// Type Definition "Stack Node & Stack".
struct StackNode{
   StackEntry entry;
   StackNode *next;
};

 struct Stack{
   StackNode *top;
   int	size;

};


void	CreateStack		(Stack* );
void	Push			(Stack* , StackEntry ) ;
void	Pop				(Stack* , StackEntry* );
int		StackEmpty		(Stack* );
int		StackFull		(Stack* );
int		StackSize		(Stack* );
void	ClearStack		(Stack* );
void	TraverseStack	(Stack* , void (*)(int) );
void	StackTop		(Stack* , StackEntry* );



//struct ElementType{
//short int  etype; 
//   union{
//     char c;
//     double d;
//   }info;
//};
