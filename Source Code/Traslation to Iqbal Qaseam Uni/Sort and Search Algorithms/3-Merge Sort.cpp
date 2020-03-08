// Merge Sort.cpp : Defines the entry point for the console application.
// Edited By Ahmed Fouad

#include "stdafx.h"
#include<iostream>
#include <conio.h>
using namespace std;

const int SIZE = 100;



void merge(int *,int, int , int );

void mergesort(int *a, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,high,mid);
    }
    return;
}

void merge(int *a, int low, int high, int mid)
{
    int i, j, k, c[50];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            c[k] = a[i];
            k++;
            i++;
        }
        else
        {
            c[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        c[k] = a[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        c[k] = a[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)
    {
        a[i] = c[i];
    }
}

void main()
{ 
	int i,n,ch;
	int A[SIZE];
	cout<< "\n Merging Sort\n";
	cout<< "\n How many values are to process: "; 
	cin>>n;
	cout<< "\n Input "<<n<< " values\n";
	for( i=0; i< n; i++ ) 
		cin>> A[i] ;
	
	mergesort(A, 0, n-1);

	cout<<"\n Sorted Array\n";
	for( i=0; i< n; i++ ) 
		cout<< A[i]<<"\t";
	cout<<endl;
}










