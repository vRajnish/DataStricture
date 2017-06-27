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
tree *insertInTree(tree* root,int data)
{
	tree *p=new tree,*root1=root;
	p->data=data;
	p->left=NULL;
	p->right=NULL;
	queue<tree*> q;
	q.push(root);
	if(!root)
	{
		root=p;
		return root1;
	}
	while(!q.empty())
	{
		tree *temp=q.front();
		q.pop();
		if(temp->left)
			q.push(temp->left);
		else
		{
			temp->left=p;
			return root1;
		}
		if(temp->right)
			q.push(temp->right);
		else
		{
			temp->right=p;
			return root1;
		}
	}
}
void preOrder(tree *root)
{
	if(root)
	{
		cout<<root->data<<"\n";
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
	cout<<"\nTree before Insertion\n";
	preOrder(root);
	root=insertInTree(root,12);
	root=insertInTree(root,13);
	cout<<"\nTree After Insertion\n";
	preOrder(root);
}
