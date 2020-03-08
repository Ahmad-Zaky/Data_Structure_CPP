// Bubble Sort-SO.cpp : Defines the entry point for the console application.
// Programmed by SHAHID LONE
// Edited By Somaia Osama

#include "stdafx.h"
#include <iostream>
using namespace std;

	int const SIZE = 6;

	void BubbleSort(int A[],int N)
	{
		int temp;
		for(int pass=1; pass<N ; pass++)
		{
			for(int i=0; i<SIZE-pass ;i++)
			{
				if(A[i]>A[i+1])
				{
					temp=A[i];
					A[i]=A[i+1];
					A[i+1]=temp;
				}
			}
		}
	}

	int main()
	{
		int i;
		int a[SIZE];

		cout<<"\n Bubble Sort\n";
		cout<< "\n How many values are to process: ";
		cin>> n;
		cout<<"\n Input "<<n<<" values:\n";
		for( i=0; i< n ; i++ ) 
			cin>>A[i];

		
		cout<< "The Elements Of The Array Before Sorting\n";
		for (i=0; i< SIZE ; i++) 
			cout<< a[i]<<"\t";

		BubbleSort(a, SIZE);
		
		cout<< "\n\nThe Elements Of The Array After Sorting\n";
		for (i=0; i< SIZE ; i++) 
			cout<< a[i]<<"\t";
		cout<<endl;
		return 0;
	}

