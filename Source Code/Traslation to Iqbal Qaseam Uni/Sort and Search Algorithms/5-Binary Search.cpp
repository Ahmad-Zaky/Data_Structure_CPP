// Binary Search.cpp : Defines the entry point for the console application.
// Programmed by SHAHID LONE
// Edited By Ahmed Fouad
#include "stdafx.h"
#include "iostream"

using namespace std;


const int SIZE = 100;


int IsSorted(int a[] , int size){
	int i;
	for( i = 0 ; i < size-1 && a[i] <= a[i+1] ; i++);

	if( i != size-1) return 0;
	else return 1;
		
}


int BinarySearch(int a[] , int size, int key){
	int middle, bottom = 0, top = size-1;
   
	while(bottom <= top){

	middle=(bottom+top)/2;
	
	if (key == a[middle])
	   return middle;
	if (key < a[middle]) 
	   top=middle-1;
	else
	   bottom=middle+1;
   }
   return -1;

}
int main()
{
	

	int i,n,ch,k;
	int A[SIZE];
	
	cout<<"\n Binary Search\n";
	cout<< "\n How many values are to process: ";
	cin>> n;
	cout<<"\n Input "<<n<<" values in a sorted manner:\n";
	for( i=0; i< n ; i++ ) 
		cin>>A[i];


	if(IsSorted(A,n)){

		cout<<"Enter the value to Search: ";
		cin>>k;
	

		if(BinarySearch(A,n,k) != -1) 
			cout <<"The Index of the value is: "<<BinarySearch(A,n,k)+1<<endl;
		else
			cout <<"Not found !!!\n";
	}else
		cout<<"The elements in the array are not sorted !!!\n";
	return 0;
}

