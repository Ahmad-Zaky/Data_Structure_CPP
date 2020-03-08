#include "stdafx.h"
#include <iostream>
#include "binary.h"

void CreateTree(Tree* pt)
{
	*pt= NULL;
}

int EmptyTree(Tree* pt)
{
	return ( !(*pt) );
}

int FullTree(Tree* pt)
{
	return 0;
}

void Inorder(Tree* pt, void (*pvisit)(TreeEntry))
{
	if(*pt){
		Inorder(&(*pt)->left, pvisit);
		(*pvisit)((*pt)->entry);
		Inorder(&(*pt)->right, pvisit);
	}
}

void InsertTree(Tree* pt, TreeEntry *pe)
{
	TreeNode *prev, *curr;
	
	TreeNode *pn = new TreeNode();
	pn->entry = *pe;
	pn->left = NULL;
	pn->right= NULL;

	if(!*pt)
		*pt = pn;
	else{
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

int TreeSize(Tree* pt)
{
	if(!*pt)
		return 0;
	return 1+TreeSize(&(*pt)->left)+TreeSize(&(*pt)->right);
}

int TreeDepth(Tree* pt)
{
	if(!*pt)
		return 0;
	int a = TreeDepth(&(*pt)->left);
	int b = TreeDepth(&(*pt)->right);
	return (a>b)? a+1 : b+1;
}



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
		if(!prev)
			DeleteNodeTree(pt);
		else if( LT(k, curr->entry.key) )
			DeleteNodeTree(&prev->left);
		else
			DeleteNodeTree(&prev->right);
	}
	return found;
}

void DeleteNodeTree(Tree* pt)
{
	TreeNode* curr = *pt, * prev = NULL;
	if(!(*pt)->left)
		*pt = (*pt)->right;
	else if(!(*pt)->right)
		*pt = (*pt)->left;
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