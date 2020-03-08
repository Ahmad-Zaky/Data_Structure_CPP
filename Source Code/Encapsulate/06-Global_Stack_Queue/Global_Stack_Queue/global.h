#include "stdafx.h"


#ifndef GLOBAL H
#define GLOBAL H

struct ElementType{
	//these attributes (year, age) are only for example
	short int  etype; 
   union{
     int  courseNo;
     char degree;
   }info;

};

typedef ElementType QueueEntry;
typedef ElementType StackEntry;

#endif