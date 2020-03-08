// Tree-SO.cpp : Defines the entry point for the console application.
// Programmed by My Code School
// https://www.youtube.com/user/mycodeschool
// Edited By Somaia Osama

#include "stdafx.h"
#include<iostream>
using namespace std;


struct Node 
{
	int data;
	Node *left;
	Node *right;
};

// Function to Insert Node in a Binary Search Tree
Node* Insert(Node *root,int data) 
{
	if(root == NULL) {
		root = new Node();
		root->data = data;
		root->left = root->right = NULL;
	}
	else if(data <= root->data)
		root->left = Insert(root->left,data);
	else 
		root->right = Insert(root->right,data);
	return root;
}


//Function to find minimum in a tree. 
Node* FindMin(Node* root)
{
	while(root->left != NULL) 
		root = root->left;
	return root;
}
 
// Function to search a delete a value from tree.
Node* Delete(Node *root, int data) 
{
	if(root == NULL) return root; 
	else if(data < root->data) root->left = Delete(root->left,data);
	else if (data > root->data) root->right = Delete(root->right,data);
	// Wohoo... I found you, Get ready to be deleted	
	else {
		// Case 1:  No child
		if(root->left == NULL && root->right == NULL) { 
			delete root;
			root = NULL;
		}
		//Case 2: One child 
		else if(root->left == NULL) {
			Node *temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == NULL) {
			Node *temp = root;
			root = root->left;
			delete temp;
		}
		// case 3: 2 children
		else { 
			Node *temp = FindMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right,temp->data);
		}
	}
	return root;
}
 
//Function to visit nodes in Inorder
void Inorder(Node *root) 
{
	if(root == NULL) 
		return;
 
	Inorder(root->left);       //Visit left subtree
	cout<<root->data;          //Print data
	Inorder(root->right);      //Visit right subtree
}

//Function to visit nodes in Preorder
void Preorder(Node *root) 
{
	if(root == NULL) 
		return; // base condition for recursion
	             // if tree/sub-tree is empty, return and exit
    cout<<root->data;           //Print data
	Preorder(root->left);       //Visit left subtree	
	Preorder(root->right);      //Visit right subtree
}

//Function to visit nodes in Postorder
void Postorder(Node *root) 
{
	if(root == NULL) 
		return;
 
	Postorder(root->left);       //Visit left subtree	
	Postorder(root->right);      //Visit right subtree
	cout<<root->data;            //Print data
}


//To search an element in BST, returns true if element is found
bool Search(Node* root,int data) 
{
	if(root == NULL) 
	{
		return false;
	}
	else if(root->data == data) 
	{
		return true;
	}
	else if(data <= root->data) 
	{
		return Search(root->left,data);
	}
	else 
	{
		return Search(root->right,data);
	}
}

 
void main()
{
	int ch, item;
	Node* root = NULL;
	while( 1 )
	{ 
		cout<<"\n Binary Search Tree Functions\n";
		cout<<"\n1. Insert a New Node";
		cout<<"\n2. Delete Existing Node";
		cout<<"\n3. In-Order Traverse (Ascending Order)";
		cout<<"\n4. Pre-Order Traverse ";
		cout<<"\n5. Post-Order Traverse ";
		cout<<"\n6. Search";
		cout<<"\n7. Exit";
		cout<<"\nEnter you choice: ";
		cin>>ch;
		switch(ch)
		{
		case 1:
			cout<<"\n\n Put a number: "; 
			cin>>item;
		     root = Insert(root,item);
		     break;
		case 2:
			int number;
	          cout<<"Enter number be deleted\n";
               cin>>number;
               root = Delete(root,number);
			break;
		case 3:
			cout<<"\n\n\n In-Order Traverse (ASCENDING ORDER)\n";
			Inorder(root);
			cout<<"\n\n";
			break;
		case 4:
			cout<<"\n\n\n Pre-Order Traverse \n";
			Preorder(root);
			cout<<"\n\n";
			break;
		case 5:
			cout<<"\n\n\n Post-Order Traverse \n";
			Postorder(root);
			cout<<"\n\n";
			break;
		case 6: 
	          int num;
	          cout<<"Enter number be searched\n";
               cin>>num;
	          //If number is found, print "FOUND"
	          if(Search(root,num) == true) 
				cout<<"Found\n";
			else 
				cout<<"Not Found\n";
			break;
		case 7:
			exit(0);
		default:
			cout<<"\n\nInvalid Input";
		} // end of switch
	} // end of while loop
} // end of main( ) function








