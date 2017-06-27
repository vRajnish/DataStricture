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
}

int pathWithGivenSum(tree *root,int sum)
{
	if(root==NULL)
		return 0;
	else
	{
		sum-=root->data;
		if(sum==0)
			return 1;
		int temp=pathWithGivenSum(root->left,sum);
		if(temp!=0)
			return temp;
		else
		{
			pathWithGivenSum(root->right,sum);	
		}
		
	}	
}

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
	cout<<pathWithGivenSum(root,42);
	
}
