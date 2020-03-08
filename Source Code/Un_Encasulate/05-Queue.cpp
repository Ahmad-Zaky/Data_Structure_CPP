#include "stdafx.h"
#include <iostream>

using namespace std;

//define the entry data (Encapsulation)
typedef int QueueEntry;

// Type Definition "Queue Node".
struct QueueNode{
	QueueEntry entry;
	QueueNode *next;
};


// Type Definition "Queue".
 struct Queue{
	QueueNode *front;
	QueueNode *rear;
	int	size;	//old trick
};

// Creat the Queue by pointing its front and rear to NULL.
void CreateQueue(Queue *pq){
   pq->front=NULL;
   pq->rear=NULL;
   pq->size=0;
}


//-------------------------------------------------
//Appending an element in the rear of the Queue
void Append( Queue* pq, QueueEntry e){  //function name can be also EnQueue 
  //Step 1:Create new queuenode and put the element in the entry part of the new node 
  QueueNode* pn= new QueueNode();
  pn->next=NULL;
  pn->entry=e;
  
  //Step 2: insert the new queuenode on the top of the queue
  if (!pq->rear)
    pq->front=pn; 
  else
    pq->rear->next=pn;//run time error for empty queue
  pq->rear=pn;
  pq->size++;
}

//serving an element from the front of the Queue
void Serve(Queue* pq, QueueEntry *pe){ //function name can be also DeQueue 
	//Step 1: get the element from the deleted node and return it to the user
	QueueNode *pn;
		pn=pq->front;
	*pe=pn->entry;

	//Step 2: free the deleted node from the memory and get it out from the queue
	pq->front=pn->next;
	free(pn);
	if (!pq->front)
		pq->rear=NULL;

	pq->size--;
}
//-----------------------------------------------------------
//Returing the state of the Queue if its empty or not
int QueueEmpty(Queue* pq){
	return !pq->front;
}

//Returing the state of the Queue if its full or not
//and its always not empty because we are not limited with a specifiec size 
//except the size of memory
int QueueFull(Queue* pq){
	return 0;
}


//Return the size of the Queue by counting the number of nodes in Queue
int QueueSize(Queue* pq){
	return pq->size;
}

//-----------------------------------------------------
//freeing the all nodes in the Queue to be available for the memory 
void ClearQueue(Queue* pq){
	while(pq->front){
		pq->rear=pq->front->next;
		free(pq->front);
		pq->front=pq->rear;
	}
	pq->size  = 0; 
}/*Moving with two pointers,
   Exactly as in LinkedStacks*/



//Displaying the data in the all nodes in Queue 
void TraverseQueue(Queue* pq, void(*pf)(QueueEntry)){
	QueueNode *pn ;
	for(pn=pq->front; pn; pn=pn->next)
		(*pf)(pn->entry);
}




void display(QueueEntry e)
{
	cout<<e<<endl;
}

int main()
{
	/*Queue q;
	QueueEntry e ;
	CreateQueue(&q);
	
	for(int i=0 ; i < 10 ; i++)
	{
	cin>>e;
	Append(&q,e);
	}

	TraverseQueue(&q,display);
*/

		Queue q;
		QueueEntry e ;
		CreateQueue(&q);

		int ch;
		while(1)
		{ 
			cout<< " \n\n Queue Operations\n";
			cout<< " 1- Append element into the queue \n 2- Serve element from the queue \n";
			cout<< " 3- Traverse queue \n 4- Exit\n";
			cout<< "\nYour Choice: "; 
			cin>>ch;

			switch(ch)
			{ 
			case 1: 
				cout<< "\n Put element to Append in the queue: ";
				 cin>>e;
				 if(!QueueFull(&q)){
					 Append(&q,e);
					 cout<<"\n The element("<<e<<") is Appended into the queue";
				 }else
					 cout<<"\n The queue is full. \n";
				break;
			case 2: 
				if(!QueueEmpty(&q)){
					Serve(&q,&e);
					cout<<"\n The element ("<<e<<") is Served from the queue \n";
				}else
					cout<<"\n The Queue is Empty. \n";
				break;
			case 3: 
				cout<< "\n Queue elements:\n";
				TraverseQueue(&q,display); 
				break;
			case 4: 
				exit(0);
			} // end of switch
		} // end of while loop

		return 0;
}

