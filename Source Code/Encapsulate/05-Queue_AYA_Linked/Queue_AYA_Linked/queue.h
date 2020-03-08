#include "stdafx.h"

typedef int QueueEntry;

struct QueueNode{
	QueueEntry entry;
	QueueNode *next;
};

 struct Queue{
	QueueNode *front;
	QueueNode *rear;
	int	size;	//old trick
};

 void	CreateQueue		(Queue*);
 void	Append			(Queue*, QueueEntry );
 void	Serve			(Queue*, QueueEntry* );
 int	QueueEmpty		(Queue*);
 int	QueueFull		(Queue*);
 int	QueueSize		(Queue*);
 void	ClearQueue		(Queue*);
 void	TraverseQueue	(Queue*, void(*)(QueueEntry));




