#include "stdafx.h"

#define MAXQUEUE 100

typedef int QueueEntry;

struct Queue{
   int front;
   int rear;
   int size;
   QueueEntry entry[MAXQUEUE];
};

void	CreateQueue		(Queue*);
 void	Append			(Queue*, QueueEntry );
 void	Serve			(Queue*, QueueEntry* );
 int	QueueEmpty		(Queue*);
 int	QueueFull		(Queue*);
 int	QueueSize		(Queue*);
 void	ClearQueue		(Queue*);
 void	TraverseQueue	(Queue*, void(*)(QueueEntry));