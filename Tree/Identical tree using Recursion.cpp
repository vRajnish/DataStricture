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

int identicalOrNotusingRecursion(tree *root1,tree *root2)
{
	
	if(!root1 && !root2)
		return 1;
	if((!root1 && root2) || (root1 && !root2))
		return 0;
	if (root1->data==root2->data) 
	{
		return identicalOrNotusingRecursion(root1->left,root2->left) && identicalOrNotusingRecursion(root1->right,root2->right);	
	} 
	else
		return 0;}

int main()
{
	tree *root=new tree;
	root->data=5;
	root->left=createTree(6);
	root->right=createTree(7);
	root->left->left=createTree(8);
	//root->left->right=createTree(9);
	root->right->left=createTree(10);
	root->right->right=createTree(11);	
	root->left->left->left=createTree(12);
	root->left->left->right=createTree(13);
	root->left->left->right->left=createTree(14);
	root->left->left->right->right=createTree(15);
	root->right->left->left=createTree(16);
	root->right->left->right=createTree(17);
	root->right->right->left=createTree(18);
	root->right->right->right=createTree(19);
	
	tree *root1=new tree;
	root1->data=5;
	root1->left=createTree(12);
	root1->right=createTree(7);
	root1->left->left=createTree(8);
	//root1->left->right=createTree(9);
	root1->right->left=createTree(10);
	root1->right->right=createTree(11);	
	root1->left->left->left=createTree(12);
	root1->left->left->right=createTree(13);
	root1->left->left->right->left=createTree(14);
	root1->left->left->right->right=createTree(15);
	root1->right->left->left=createTree(16);
	root1->right->left->right=createTree(17);
	root1->right->right->left=createTree(18);
	root1->right->right->right=createTree(19);
	int flag=identicalOrNotusingRecursion(root,root1);
	if(flag)
		cout<<"Identical\n";
	else
		cout<<"\nNot Identical";
	
}
