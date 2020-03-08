// BinaryTree_AYA_Linked.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "binary.h"

using namespace std;

void display(TreeEntry e)
{
	cout<<e.key<<"-\t"<<e.entry<<endl;
}

int main()
{
	Tree t;
	TreeEntry e;
	CreateTree(&t);

	for(int i = 0 ; i < 5 ; i++)
	{
		cout<<"Enter the key: ";
		cin>>e.key;

		cout<<"Enter the Element: ";
		cin>>e.entry;

		InsertTree(&t, &e);
	}

	Inorder( &t, display);

	return 0;
}

