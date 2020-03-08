// Stack_App_Polish_Notation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>



using namespace std;

//Define the element type as struct because we want to use the stack two times 
//with diffrent type for the entry at eack time
struct ElementType{
//short int  etype; 
   
     char character;
     double number;
};

typedef ElementType StackEntry;


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
	//Step 1: Create new stacknode and put the element in the entry part of the new node 
	 StackNode *pn = new StackNode(); 
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
  *pe=ps->top->entry;
  //Step 2: free the deleted node from the memory and get it out from the stack
  StackNode *pn;
  pn=ps->top;
 
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






//------------------------
//------------------------
//Application on Stack
//Polish Notation
//------------------------
//------------------------


//function to check if the character is digit or not
int IsDigit(char c){
   return(c>='0' && c<='9');
}


//-------------------------------------------------------------
//-------------------------------------------------------------

//function to check the precedence for the operators in the expression if we evaluate postfix
int Precedent(char op1, char op2){
    //if the op1 which is saved in the stack is ^ (Power) then return 1 
	//because it the highest priority
	if (op1=='^') return 1;
	
	//if op1 = * or \ then we return 0 only if op2 equal to ^
	//because it the only operator which is more precedence than * and \
	
	if ((op1=='*') || (op1=='/'))
		return (op2!='^');
	// in the last case it return 1 only if its from the same precedence
	// becase in the case the operators are the same precedence 
	//then the first comoing must be rvaluated first
    if ((op1=='+') || (op1=='-')) 
		return ( (op2!='^')&&(op2!='*')&&(op2!='/') );

   return 0;
}



//-------------------------------------------------------------
//-------------------------------------------------------------

//function to check the precedence for the operators in the expression if we evaluate prefix
int Priority(char op1, char op2){
   	
	//the only diffrence here is that if two operators have the same precedence 
	//the last one must be evaluated at the first
	if (op1==op2) return 0;
	else{
		if(op1=='^') return 1;

		if ((op1=='*') || (op1=='/'))
			return (op2!='^')&&(op2!='*')&&(op2!='/');
		}
   return 0;
}


//-------------------------------------------------------------
//-------------------------------------------------------------

//function get the two operands and its operator to evaluate it
double Oper(char c, double op1, double op2){
   switch(c){
	case '+': return(op1+op2);
	case '-': return(op1-op2);
	case '*': return(op1*op2);
	case '/': return(op1/op2);
	case '^': return(pow(op1,op2));
   }
}


//-------------------------------------------------------------
//-------------------------------------------------------------

//function to reverse the expression which is saved in array
//used in infix to prefix convertion
char* ReverseExpr(char expr[])
{
	int i = 0, j = 0;
	char tmp;

	while(expr[i] != '\0')
		i++;

	i--;
	while(i>j)
	{
		tmp = expr[j];
		expr[j] = expr[i];
		expr[i] = tmp;
		i--; j++;
	}
	return expr;
}




//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//Evaluate Postfix expresion without '(' and ')' operators "parenthesis"
double EvaluatePostfix(char expr[]){
	
	//and Declare our operands and the result variables
	int i = 0;
    StackEntry c, num, op1, op2, val;
   
	//Declare the stack and initialize it using CreateStack function 
	Stack s;
	CreateStack(&s);
   
   //visiting the postfix expression element by element and evaluating it to get the result
   for(i=0; (c.character=expr[i])!='\0'; i++){
	  
	   //checking the character if its Digit or not
	   if(IsDigit(c.character)){
		  
		  //push the number into the stack
		  num.number = c.character-'0';
		  Push(&s,num );
	  
	     //if its not number then it is an operator
	   }else{
            
		//we apply the operator on the last two numbers pushed into the stack
		//we pop twice the first number poped is the first operand 
		//and the second number poped is the second operand
		  Pop(&s, &op2);
          Pop(&s, &op1);
		//apply the operation by calling Oper function and passing the operator and its two operands
		  val.number=Oper(c.character, op1.number, op2.number);
          //pushing result back into the stack 
		  Push(&s, val);
      }
   }
   //poping the result and returning it to main function
    Pop(&s, &val);
	return val.number;
}



//-------------------------------------------------------------
//-------------------------------------------------------------

// Convert from Infix to Postfix
double InfixToPostfix(char infix[]){
   
int i, j;
//Declare the postfix array which get the converted expression later
char postfix[100];

//Declare the stack entry for the digits and the operators
StackEntry c,op;

//Declare the stack and initialize it using CreateStack function
Stack s;
CreateStack(&s);
for(i=0, j=0;    (c.character=infix[i])!='\0'     ; i++){


//checking the character if its Digit or not
	if(IsDigit(c.character))
		//putting the digit into the (postfix array) --> which will be the last result of this function
		postfix[j++]=c.character;
	
	else{
		//checking if the stack is empty or not 
	   if(!StackEmpty(&s)){
			//getting the top operator and comparing it with the operator from the expression 
			//to know which has more priority than the other
			StackTop(&s, &op);
			
			//if the operator from the stack has more priority than or equal to the operator from the expression 
			//then the operator from the stack must be evaluated first 
			//so we pop it from the stack and putting it into the postfix array
			while(!StackEmpty(&s) && Precedent(op.character, c.character)){
		  
				Pop(&s, &op);
				postfix[j++]=op.character;
				
				//The Increment part for the while loop gettin the top of the stack untill the stack become empty 
				//or the operator from the expression has more priority than the operator in the stack 
				if(!StackEmpty(&s)) 
					StackTop(&s, &op);
	      }
	   }
	   //pushing the operator from the expression into the stack 
	   //if it has priority than the operator from the stack or if the stack is empty
	   Push(&s, c);
	}
}

//poping the rest operators in the stack to the postfix array to finish the conversion
while(!StackEmpty(&s)){
	Pop(&s, &op);
	postfix[j++]=op.character;
}
//putting NULL == '\0' into the end of the postfix array to indicate the end of the expression
postfix[j]='\0';


//display the expression in the prefix form
cout<<"\n\nThe Experssion in postfix form: ";
for(j=0; postfix[j] != '\0'; j++)
	cout<<postfix[j];
cout<<endl;

//passing the postfix array to EavluatePostfix function to evaluating the expression 
//and getting the result form EvaluatePostfix and returing to the main function
return EvaluatePostfix(postfix);

}



//-------------------------------------------------------------
//-------------------------------------------------------------


////-----------------------------------------------------------
////Evaluate Postfix expresion with '(' and ')' operators "parenthesis"
//double EvaluatePostfix(char expr[]){
//   int i;
//   
//   Stack s;
//   StackEntry c, num, op1, op2, val;
//   
//   CreateStack(&s);
//   
//   for(i=0; (c.character=expr[i])!='\0'; i++){
//	  
//	   if(IsDigit(c.character)){
//
//		  num.number = c.character-'0';
//		  Push(&s,num );
//	  
//	   }else{
//         
//		  Pop(&s, &op2);
//          Pop(&s,&op1 );
//		  val.number=Oper(c.character, op1.number, op2.number);
//          Push(&s, val);
//      }
//   }
//    Pop(&s, &val);
//	return val.number;
//}
//
//
////-------------------------------------------------------------
////-------------------------------------------------------------
//
//// Convert from Infix to Postfix
//double InfixToPostfix(char infix[] ){
//   int i, j;
//   char postfix[100];
//StackEntry c,op;
//Stack s;
//CreateStack(&s);
//for(i=0, j=0;    (c.character=infix[i])!='\0'     ; i++){
//	if(IsDigit(c.character))
//		postfix[j++]=c.character;
//	else if(c.character == '(')
//			Push(&s, c);
//		else if(c.character == ')'){
//			
//			StackTop(&s, &c);
//			while(c.character != '('){
//				Pop(&s, &c);
//				postfix[j++] = c.character;
//				StackTop(&s, &c); 
//			}
//			Pop(&s, &c);
//
//		}else{ if(!StackEmpty(&s)){
//	      
//		   StackTop(&s, &op);
//
//		   while(!StackEmpty(&s) && Precedent(op.character, c.character)){
//		  
//			  Pop(&s, &op);
//			  postfix[j++]=op.character;
//		  
//			  if(!StackEmpty(&s)) 
//				StackTop(&s, &op);
//	      }
//	   }
//		Push(&s, c);	
//	}
//}
//
//while(!StackEmpty(&s)){
//	Pop(&s, &op);
//	postfix[j++]=op.character;
//}
//postfix[j]='\0';
//
//
////display the expression in the prefix form
//cout<<"\n\nThe Experssion in postfix form: ";
//for(j=0; postfix[j] != '\0'; j++)
//	cout<<postfix[j];
//cout<<endl;
//
//return EvaluatePostfix(postfix);
//
//}



//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//Evaluate Prefix expresion without '(' and ')' operators "parenthesis"

double EvaluatePrefix(char expr[]){
	
	//and Declare our operands and the result variables
	int i = 0;
    StackEntry c, num, op1, op2, val;
   
	//Declare the stack and initialize it using CreateStack function 
	Stack s;
	CreateStack(&s);
   
   //visiting the prefix expression element by element and evaluating it to get the result
   for(i=0; (c.character=expr[i])!='\0'; i++){
	  
	   //checking the character if its Digit or not
	   if(IsDigit(c.character)){
		  
		  //push the number into the stack
		  num.number = c.character-'0';
		  Push(&s,num );
	  
	     //if its not number then it is an operator
	   }else{
            
		//we apply the operator on the last two numbers pushed into the stack
		//we pop twice the first number poped is the first operand 
		//and the second number poped is the second operand
		  Pop(&s, &op1);
          Pop(&s, &op2);
		//apply the operation by calling Oper function and passing the operator and its two operands
		  val.number=Oper(c.character, op1.number, op2.number);
          //pushing result back into the stack 
		  Push(&s, val);
      }
   }
   //poping the result and returning it to main function
    Pop(&s, &val);
	return val.number;
}


//-------------------------------------------------------------
//-------------------------------------------------------------

//Convert from Infix to Prefix
double InfixToPrefix(char infix[] )
{
	
int i, j;
//Declare the postfix array which get the converted expression later
char prefix[100];

//Declare the stack entry for the digits and the operators
StackEntry c,op;

//Declare the stack and initialize it using CreateStack function
Stack s;
CreateStack(&s);


//reversing the expression allowing  us converting infix to prefix
ReverseExpr(infix);

//visiting the expression element by element and converting it into prefix form
for(i=0, j=0;    (c.character=infix[i])!='\0'     ; i++){
	
	//checking the character if its Digit or not
	if(IsDigit(c.character))
		//putting the digit into the (prefix array) --> which will be the last result of this function
		prefix[j++]=c.character;
	else{
		//checking if the stack is empty or not 
	   if(!StackEmpty(&s)){
	      
		   //getting the top operator and comparing it with the operator from the expression 
		   //to know which has more priority than the other
		   StackTop(&s, &op);

		   //if the operator from the stack has more priority than the operator from the expression 
		   //then the operator from the stack must be evaluated first 
		   //so we pop it from the stack and putting it into the postfix array
		   while(!StackEmpty(&s) && Priority(op.character, c.character)){
		  
			  Pop(&s, &op);
		      prefix[j++]=op.character;
		  
			  if(!StackEmpty(&s)) 
				StackTop(&s, &op);
	      }
	   }
	   //pushing the operator from the expression into the stack 
	   //if it has priority than the operator from the stack or if the stack is empty
	   Push(&s, c);
	}
}

//poping the rest operators in the stack to the prefix array to finish the conversion
while(!StackEmpty(&s)){
	Pop(&s, &op);
	prefix[j++]=op.character;
}

//putting NULL == '\0' into the end of the prefix array to indicate the end of the expression
prefix[j]='\0';


//display the expression in the prefix form so we start from the end of the array
//which contains the prefix expression
cout<<"\n\nThe Experssion in prefix form: ";

for( j-- ;j != -1 ;j--)
	cout<<prefix[j];
cout<<endl;

//passing the prefix array to EavluatePrefix function to evaluating the expression 
//and getting the result form EvaluatePrefix and returing to the main function
return EvaluatePrefix(prefix);
}




////----------------------------------------------------------------------------------------------------
////----------------------------------------------------------------------------------------------------
////Evaluate Prefix expresion with '(' and ')' operators "parenthesis"
//double EvaluatePrefix(char expr[]){
//   int i = 0;
//   
//   
//   Stack s;
//   StackEntry c, num, op1, op2, val;
//   
//   CreateStack(&s);
//   
//   for(i=0; (c.character=expr[i])!='\0'; i++){
//	  
//	   if(IsDigit(c.character)){
//
//		  num.number = c.character-'0';
//		  Push(&s,num );
//	  
//	   }else{ 
//         
//		  Pop(&s, &op1);
//          Pop(&s, &op2);
//		  val.number=Oper(c.character, op1.number, op2.number);
//          Push(&s, val);
//      }
//   }
//    Pop(&s, &val);
//	return val.number;
//}
//
//
//double InfixToPrefix(char infix[] )
//{
//	int i, j;
//char prefix[100];
//StackEntry c,op;
//Stack s;
//CreateStack(&s);
//
//ReverseExpr(infix);
//
//for(i=0, j=0;    (c.character=infix[i])!='\0'     ; i++){
//	
//	if(IsDigit(c.character))
//		prefix[j++]=c.character;
//	else if(c.character == ')')
//			Push(&s, c);
//		else if(c.character == '('){
//			
//			StackTop(&s, &c);
//			while(c.character != ')'){
//				Pop(&s, &c);
//				prefix[j++] = c.character;
//				StackTop(&s, &c); 
//			}
//			Pop(&s, &c);
//
//		}else{ if(!StackEmpty(&s)){
//	      
//		   StackTop(&s, &op);
//
//		   while(!StackEmpty(&s) && Priority(op.character, c.character)){
//		  
//			  Pop(&s, &op);
//		      prefix[j++]=op.character;
//		  
//			  if(!StackEmpty(&s)) 
//				StackTop(&s, &op);
//	      }
//	   }
//	   Push(&s, c);
//		
//	}
//}
//
//while(!StackEmpty(&s)){
//	Pop(&s, &op);
//	prefix[j++]=op.character;
//}
//prefix[j]='\0';
//
//
////display the expression in the prefix form
//cout<<"\n\nThe Experssion in prefix form: ";
//
//for( j-- ;j != -1 ;j--)
//	cout<<prefix[j];
//cout<<endl;
//
//return EvaluatePrefix(prefix);
//}

//-----------------------------------------------------

//-----------------------------------------------------


//Simple  Test
int main()
{
	/*char expr [] = {'1','+','3','\0'};
	char postfix [4];
	cout<<InfixToPostfix(expr,postfix);*/
	
	//------------------------------------------------
	
	
	/*char expr [100] = {'\0'};
	char postfix [100];
	int i = 0;
	cout<<"write your expresion : ";
	cin>>expr[i];
	do{
	i++;
	cin>>expr[i];
	}while(expr[i] != 'e');
	expr[i] = '\0';
	cout<<endl<<InfixToPostfix(expr,postfix)<<endl;*/
	
	
	//-------------------------------------------------------
	/*string str;
	char expr [100] = {'\0'};
	char prefix [100];
	cout<<"write your expresion : ";
	cin>>str;
	int i=0;

	expr [i] = str[i];
	do{
		
		i++;
	    expr [i] = str[i];
	 
	}while(str[i] != 'e');

	expr [i] = '\0';

	cout<<endl<<InfixToPostfix(expr,prefix)<<endl;
	return 0;*/

	//---------------------------------------------------

	string str;
	char c1,c2;
	char expr [100] = {'\0'};
	
	do{
	
	cout<<"\n\nwrite your expresion : ";
	cin>>str;
	

	int i = str.size();
	i+=2;
	str.resize(i); 
	i-=2;
	str[i]= 'e';

	i=0;
	expr [i] = str[i];

	
	do{
		
		i++;
	    expr [i] = str[i];
	 
	}while(str[i] != 'e');

	expr [i] = '\0';

	cout<<"\n+---------------------------------+";
	cout<<"\n1-Evaluate Infix to postfix.\n2-Evaluate Infix to prefix.";
	cout<<"\n+---------------------------------+";
	cout<<"\n\nEnter your choice: ";
	cin>>c1;
	
	
	if(c1 == '1')
		cout<<"The result is: "<<InfixToPostfix(expr)<<endl;
	else{
		cout<<"The result is: "<<InfixToPrefix(expr)<<endl;
		
	}
	
	cout<<"\n+======================+\n"<<"     Main Menue !!!\n"<<"+======================+\n";
	cout<<"\n\n 1-continue \n 2-Exit\n";
	cout<<"\n\n\nEnter your choice:";
	cin>>c2;
	}while(c2 == '1');

	return 0;
}

