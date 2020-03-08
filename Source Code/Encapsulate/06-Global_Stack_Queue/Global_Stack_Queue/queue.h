#include "stdafx.h"
#include "global.h"


struct QueueNode{
	QueueEntry entry;
	QueueNode *next;
};

 struct Queue{
	QueueNode *front;
	QueueNode *rear;
	int	size;	//old trick
};

 void CreateQueue(Queue*);
 void Append(QueueEntry, Queue*);
 void Serve(QueueEntry*, Queue*);
 int QueueEmpty(Queue*);
 int QueueFull(Queue*);
 int QueueSize(Queue*);
 void ClearQueue(Queue*);
 void TraverseQueue(Queue*, void(*)(QueueEntry));




