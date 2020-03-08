#include "stdafx.h"
#include <iostream>
#include "queue.h"


// Creat the Queue by pointing its font and rear to NULL.
void CreateQueue(Queue *pq){
   pq->front=NULL;
   pq->rear=NULL;
   pq->size=0;
}


//-------------------------------------------------
//Appending an element in the rear of the Queue
void Append(QueueEntry e, Queue* pq){  //function name can be also EnQueue 
  
	QueueNode* pn= new QueueNode();
  pn->next=NULL;
  pn->entry=e; 			
  if (!pq->rear)
    pq->front=pn; 
  else
    pq->rear->next=pn;//run time error for empty queue
  pq->rear=pn;
  pq->size++;
}

//serving an element from the front of the Queue
void Serve(QueueEntry *pe, Queue* pq){ //function name can be also DeQueue 
	QueueNode *pn;
		pn=pq->front;
	*pe=pn->entry;
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

//Returing the state of the Stack ir its full or not
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
	QueueNode *pn);
	for(pn=pq->front; pn; pn=pn->next)
		(*pf)(pn->entry);
}

