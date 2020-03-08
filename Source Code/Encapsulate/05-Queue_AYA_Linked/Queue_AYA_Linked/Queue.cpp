#include "stdafx.h"
#include <iostream>
#include "queue.h"

#include "stdafx.h"
#include <iostream>

using namespace std;

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
