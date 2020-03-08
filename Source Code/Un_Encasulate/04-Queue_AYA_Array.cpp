// Queue_AYA_Array.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

//define the max size for the Queue
#define MAXQUEUE 100
//define the entry type
typedef int QueueEntry;

// Type Definition "Queue".
struct Queue{
   int front;
   int rear;
   int size;
   QueueEntry entry[MAXQUEUE];
};
//-----------------------------------------------
//-----------------------------------------------



// Create the Queue by pointing its top to 0(index).
void CreateQueue(Queue *pq){
	pq->front= 0;
	pq->rear = -1;
	pq->size = 0; 
}


//Appending an element on the top of the Queue
void Append(Queue* pq, QueueEntry e){
	//getting the rear index (we use this expression to get the rear becase its circular)
	pq->rear = (pq->rear + 1) % MAXQUEUE;
	//insert the new queue_entry on the top of the stack
	pq->entry[pq->rear] = e;
	//increment the size by one
	pq->size++;
}


//serving an element from the front of the queue
void Serve(Queue* pq, QueueEntry *pe){
  
	//get the element from the deleted queue_entry and return it to the user
	*pe = pq->entry[pq->front];
	//getting the fornt index (we use this expression to get the rear becase its circular)
	pq->front = (pq->front + 1) % MAXQUEUE;
	//minimize the size by one
	pq->size--;
}

//Returing the state of the queue ir its empty or not
int QueueEmpty(Queue* pq){
	return !pq->size;
}

//Returing the state of the queue ir its full or not
int QueueFull(Queue* pq){
	return (pq->size == MAXQUEUE);
}

//Return the size of the queue
int QueueSize(Queue* pq){
	return pq->size;
}

//Clearing the queue by initializing the index of (front = 0) & (rear = -1) & (size = 0) of the queue
void ClearQueue(Queue* pq){
	pq->front = 0;
	pq->rear  = -1;
	pq->size  = 0; 
}//same as CreateQueue. No nodes to free.

//Displaying the data from the queue element by element
void TraverseQueue(Queue* pq, void (*pf)(QueueEntry)){
	int pos, s;
	for(pos=pq->front, s=0; s<pq->size; s++){
		(*pf)(pq->entry[pos]);
		pos=(pos+1)%MAXQUEUE;
	}
}




//-----------------------------------------------
//-----------------------------------------------

void display(QueueEntry e)
{
	cout<<e<<endl;
}

int main()
{
	Queue q;
	int j = 0;
	QueueEntry e = 10;
	CreateQueue(&q);
	
	for(int i=0 ; i < 10 ; i++)
	{
	cin>>e;
	Append(&q,e);
	}

	TraverseQueue(&q,display);

	return 0;
}

