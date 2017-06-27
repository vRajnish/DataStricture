#include<bits/stdc++.h>
using namespace std;
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
int searchElement(tree *root,int k)
{
	int temp;
	if(root==NULL)
		return 0;

	if(root->data==k)
		return 1;
	else
	{
		temp=searchElement(root->left,k);
		if(temp!=0)
			return temp;
		else
			return searchElement(root->right,k);
	}
	
	return 0;
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
	cout<<searchElement(root,5);
	
}
