// Selection Sort-SO.cpp : Defines the entry point for the console application.
// Programmed by My Code School
//https://www.youtube.com/user/mycodeschool
// Edited By Somaia Osama

#include "stdafx.h"
#include<iostream>
using namespace std;
const int SIZE = 100;


void SelectionSort(int A[],int n)
{
   for(int i=0;i<n-1;i++)
   {
	   int iMin=i;
	   for(int j=i+1;j<n;j++)
	   {
		   if (A[j]< A[iMin])
			   iMin=j;
	   }
     
	 int temp=A[i];
     A[i]=A[iMin];
     A[iMin]=temp;
   } 
}


void main()
{ 
	int i,n,ch;
	int A[SIZE];
	cout<< "\n Selection Sort\n";
	cout<< "\n How many values are to process: "; 
	cin>>n;
	cout<< "\n Input "<<n<< " values\n";
	for( i=0; i< n; i++ ) 
		cin>> A[i] ;
	SelectionSort(A, n);
	cout<<"\n Sorted Array\n";
	for( i=0; i< n; i++ ) 
		cout<< A[i]<<"\t";
	cout<<endl;
}










