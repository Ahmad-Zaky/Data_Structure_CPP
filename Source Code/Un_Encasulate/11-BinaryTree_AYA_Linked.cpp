// BinaryTree_AYA_Linked.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


using namespace std;

//Macro rules for the comparision operation
//for int or double or float or char data types
#define EQ(a, b) ((a)==(b))
#define LT(a, b) ((a)<(b))
#define LE(a, b) ((a)<=(b))
#define GT(a, b) ((a)>(b))
#define GE(a, b) ((a)>=(b))

//for string data type
//#define EQ(a, b) (!strcmp((a), (b)))
//#define LT(a, b) (strcmp((a), (b))<0)
//#define LE(a, b) (strcmp((a), (b))<=0)
//#define GT(a, b) (strcmp((a), (b))>0)
//#define GE(a, b) (strcmp((a), (b))>=0)

//define the entry data (Encapsulation) and here we have key for each entry to help us during searching
struct TreeEntry{

	int key;
	int entry;
};

// Type Definition "BinaryNode" 
struct TreeNode{

	TreeEntry entry;
	TreeNode* left,* right;
};

// Type Definition "Binary" but here its only pointer to treenode not struct as all previous structures.
typedef TreeNode *Tree;


//----------------------------------------------------------------

// Creat the Binary by pointing the pointer which refering to the root to null.
void CreateTree(Tree* pt)
{
	*pt= NULL;
}

//Returing the state of the Binary Tree if its empty or not
int EmptyTree(Tree* pt)
{
	return ( !(*pt) );
}

//Returing the state of the Queue if its full or not
//and its always not empty because we are not limited with a specifiec size 
//except the size of memory
int FullTree(Tree* pt)
{
	return 0;
}


//Display the tree inorder (LVR)
void Inorder(Tree* pt, void (*pvisit)(TreeEntry))
{
	if(*pt){
		Inorder(&(*pt)->left, pvisit);
		(*pvisit)((*pt)->entry);
		Inorder(&(*pt)->right, pvisit);
	}
}


//Insertin an element in the tree
void InsertTree(Tree* pt, TreeEntry *pe)
{
	//Declare the two pointers which help us to insert the element
	TreeNode *prev, *curr;
	
	//Step 1: Creating the treenode and putting the element in the node
	TreeNode *pn = new TreeNode();
	pn->entry = *pe;
	pn->left = NULL;
	pn->right= NULL;
	
	//case 1: if the tree is empty then the new node will be the root
	if(!*pt)
		*pt = pn;
	else{
		//case 2: if the tree is not empty we going in to the tree to find where the new node must be inserted using its key
		curr = *pt;
		while(curr){
			prev = curr;
			if( LT( pe->key, curr->entry.key ) )
				curr = curr->left;
			else
				curr = curr->right;
		}
		if( LT( pe->key, prev->entry.key ) )
			prev->left = pn;
		else
			prev->right= pn;
	}
}

//freeing the all nodes in the Binary Tree to be available for the memory by recursion algorithm
void ClearTree(Tree* pt)
{
	if(*pt)
	{
		ClearTree(&(*pt)->left);
		ClearTree(&(*pt)->right);
		free(*pt);
		*pt = NULL;
	}
}
//Return the size of the Binary Tree by counting the number of nodes in Binary Tree by recursion algorithm
int TreeSize(Tree* pt)
{
	if(!*pt)
		return 0;
	return 1+TreeSize(&(*pt)->left)+TreeSize(&(*pt)->right);
}

//Getting how number of levels are in the Binary Tree by getting the depth of the left and the right and returning the bigger using recursion algorithm
int TreeDepth(Tree* pt)
{
	if(!*pt)
		return 0;
	int a = TreeDepth(&(*pt)->left);
	int b = TreeDepth(&(*pt)->right);
	return (a>b)? a+1 : b+1;
}


//Finding an element in the Binary Tree by iterative algorithm 
int FindTree(Tree* pt, TreeEntry* pe, int k)
{
	int found = 0;
	TreeNode* pn = *pt;

	while(pn && !( found = EQ(pn->entry.key, k) ) )
		if( LT(k,pn->entry.key) )
			pn = pn->left;
		else
			pn = pn->right;
	if(found)
		*pe = pn->entry;
	return found;
}


//Deleting an element from the Binary Tree using two functions
//here we only finding the element which must be deleted
int DeleteTree(Tree* pt, TreeEntry* pe, int k)
{
	int found = 0;
	TreeNode* curr = *pt, * prev = NULL;

	while(curr && !( found = EQ(k ,curr->entry.key) ) )
	{	
		prev = curr;
		if( LT(k, curr->entry.key) )
			curr = curr->left;
		else
			curr = curr->right;
	}
	if(found)
	{
		*pe = curr->entry;
		//deleting the root
		if(!prev)
			DeleteNodeTree(pt);
		//deleting from the the left or the right hand side of the Binary Tree
		else if( LT(k, prev->entry.key) )
			DeleteNodeTree(&prev->left);
		else
			DeleteNodeTree(&prev->right);
	}
	return found;
}
//Here we get from the previous function( DeleteTree ) the node which must be deleted and we freeing it in the all three cases 
void DeleteNodeTree(Tree* pt)
{
	TreeNode* curr = *pt, * prev = NULL;
	//case 1: if the deleted node have node at the left hand side
	if(!(*pt)->left)
		*pt = (*pt)->right;
	//case 2: if the deleted node have node at the right hand side
	else if(!(*pt)->right)
		*pt = (*pt)->left;
	//case 3: if the deleted node have node at the left and the right hand side 
	else{
		curr = (*pt)->left;
		if(!curr->right)
		{
			(*pt)->entry = curr->entry;
			(*pt)->left = curr->left;
		}
		else{
			do{
				prev = curr;
				curr = curr->right;
			}while(curr->right);

			(*pt)->entry = curr->entry;
			prev->right = curr->left;
		}
	}
	free(curr);
}

//----------------------------------------------------------------

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

