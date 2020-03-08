// Linear Search.cpp : Defines the entry point for the console application.
// Programmed by SHAHID LONE
// Edited By Ahmed Fouad
#include "stdafx.h"
#include "iostream"

using namespace std;


const int SIZE = 100;

int LinearSearch(int a[] , int size, int key){

	

	for( int i = 0 ; i < size ; i++)
		if(key == a[i]) return i;
	return -1;

}


int main()
{
	int i,n,ch,k;
	int A[SIZE];
	
	cout<<"\n Linear Search\n";
	cout<< "\n How many values are to process: ";
	cin>> n;
	cout<<"\n Input "<<n<<" values:\n";
	for( i=0; i< n ; i++ ) 
		cin>>A[i];

	cout<<"Enter the value to Search: ";
	cin>>k;


	if(LinearSearch(A,n,k) != -1) 
		cout <<"The Index of the value is: "<<LinearSearch(A,n,k)+1<<endl;
	else
		cout <<"Not found !!!\n";

	return 0;
}

