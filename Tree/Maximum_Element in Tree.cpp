#include<bits/stdc++.h>
using namespace std;
int max1=INT_MIN;
struct tree
{
	int data;
	tree *left;
	tree *right;
};
tree *insertInTree(int data)
{
	tree *p=new tree;
	p->data=data;
	p->left=NULL;
	p->right=NULL;
	return p;
}

/* Recursively finding max height in left subtree and right subtree and comparing with root.
int findMax(tree *root)
{
	int max=INT_MIN,left,right,root_value;
	if(root)
	{
		root_value=root->data;
		left=findMax(root->left);
		right=findMax(root->right);
		if(left>right)
			max=left;
		else
			max=right;
		if(max<root_value)
			max=root_value;
	}
	return max;
}*/

/* using preOrder traversal Method */

void preOrder(tree *root)
{
	if(root)
	{
		if(root->data>max1)
			max1=root->data;
		preOrder(root->left);
		preOrder(root->right);
	}
	
}
int main()
{
	tree *root=new tree;
	root->data=5;
	root->left=insertInTree(6);
	root->right=insertInTree(7);
	root->left->left=insertInTree(8);
	root->right->left=insertInTree(9);
	root->left->right=insertInTree(10);
	root->right->right=insertInTree(11);
	root->left->left->left=insertInTree(12);
	cout<<findMax(root);
	preOrder(root);
	cout<<"\n\n"<<max1;
}
