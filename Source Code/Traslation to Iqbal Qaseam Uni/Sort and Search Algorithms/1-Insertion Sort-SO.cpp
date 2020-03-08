// Insertion Sort-SO.cpp : Defines the entry point for the console application.
// Programmed by SHAHID LONE
// Edited By Somaia Osama

#include "stdafx.h"
#include<iostream>
using namespace std;
const int SIZE = 100;


void InsertionSort( int x[SIZE], int n )
{ 
	int i, k, temp;
	for( k=1; k< n; k++ )
	{ 
		temp = x[k];
		for( i=k-1; i>=0 && temp<x[i]; i-- ) 
			x[i+1] = x[i];
		x[i+1] = temp;
	}
}

void main()
{ 
	int i,n,ch;
	int A[SIZE];
	
	cout<<"\n Insertion Sort\n";
	cout<< "\n How many value are to process: ";
	cin>> n;
	cout<<"\n Input "<<n<<" values:\n";
	for( i=0; i< n ; i++ ) 
		cin>>A[i];
	InsertionSort(A,n);
	cout<<"\n Sorted Array\n";
	for( i=0; i < n; i++ ) 
		cout<<A[i]<<'\t';
	cout<<endl;
}









