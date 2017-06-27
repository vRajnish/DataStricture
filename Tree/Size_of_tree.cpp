#include<bits/stdc++.h>
using namespace std;
struct tree
{
	int data;
	tree *left;
	tree *right;
};

tree *createTree(int data)
{
	tree *p=new tree;
	p->data=data;
	p->left=NULL;
	p->right=NULL;
	return p;
}
int sizeOfTree(tree *root)
{
	if(root==NULL)
		return 0;
	else
		return 1+sizeOfTree(root->left)+sizeOfTree(root->right);
}

// Alternate way of calculating size;
int count1=0;
void preOrder(tree *root)
{
	if(root)
	{
		count1++;
		preOrder(root->left);
		preOrder(root->right);
	}
}
int main()
{
	tree *root=new tree;
	root->data=5;
	root->left=createTree(6);
	root->right=createTree(7);
	root->left->left=createTree(8);
	root->right->left=createTree(9);
	root->left->right=createTree(10);
	root->right->right=createTree(11); 
	preOrder(root);	
	cout<<"\nSize of Tree is\t"<<count1 ;// sizeOfTree(root);
}
