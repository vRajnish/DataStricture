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

int isMirror(tree *root1,tree *root2)
{
	if(root1==NULL && root2==NULL)
		return 1;
	if((!root1 && root2) || (root1 && !root2))
		return 0;
	else
		return root1->data==root2->data && isMirror(root1->left,root2->right) && isMirror(root1->right,root2->left);
}

int main()
{
	tree *root1=new tree;
	root1->data=5;
	root1->left=createTree(6);	
	root1->right=createTree(7);
	root1->left->left=createTree(8);
	root1->left->right=createTree(9);
	
	tree *root2=new tree;
	root2->data=5;
	root2->left=createTree(7);	
	root2->right=createTree(6);
	root2->right->left=createTree(9);
	root2->right->right=createTree(10);
	cout<<"\nIs Mirror or Not\t"<<isMirror(root1,root2);
}
