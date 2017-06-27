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

int printAllAncestor(tree *root,tree *node)
{
	if(!root)	
		return 0;
	if(root->left==node || root->right==node || printAllAncestor(root->left,node) || printAllAncestor(root->right,node))
	{
		cout<<"\n"<<root->data;	
		return 1;
	}
	return 0;
}

int main()
{
	tree *root=new tree;
	root->data=5;
	root->left=createTree(6);	
	root->right=createTree(7);
	root->left->left=createTree(8);
	root->left->right=createTree(9);
	cout<<"\n"<<printAllAncestor(root,root->left->right);
}

