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
};

void convertToMirror(tree *root)
{
	if(!root)
		return;
	else
	{
		convertToMirror(root->left);
		convertToMirror(root->right);
		
			tree *temp=root->left;
			root->left=root->right;
			root->right=temp;
	}
}

void preOrder(tree *root)
{
	if(root)
	{
		cout<<"\n"<<root->data;
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
	root->left->right=createTree(9);
	preOrder(root);
	convertToMirror(root);
	cout<<"\n\n";
	preOrder(root);
}
