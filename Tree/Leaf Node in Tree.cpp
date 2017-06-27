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

void leafNodeinTree(tree *root)
{
	if(root==NULL)
		return;
	else
	{
		if(!root->left && !root->right)
			cout<<root->data<<"\n";
		leafNodeinTree(root->left);
		leafNodeinTree(root->right);
	}
}

void levelOrderTraversal(tree *root)
{
	if(root==NULL)
		return ;
	queue<tree *> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty())
	{
		tree *temp=q.front();
		q.pop();
		if(temp==NULL)
		{
			cout<<"\n\n";
			if(!q.empty())
				q.push(NULL);
		}
		else
		{
			
		cout<<temp->data<<"\t";
		if(temp->left)	
			q.push(temp->left);
		if(temp->right)
			q.push(temp->right);
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
	root->left->right=createTree(9);
	root->right->left=createTree(10);
	root->right->right=createTree(11);	
	root->left->left->left=createTree(12);
	root->left->left->right=createTree(13);
	root->left->right->left=createTree(14);
	root->left->right->right=createTree(15);
	root->right->left->left=createTree(16);
	root->right->left->right=createTree(17);
	root->right->right->left=createTree(18);
	root->right->right->right=createTree(19);
	cout<<"\nLevel Order Traversal\n";
	levelOrderTraversal(root);
	
	cout<<"\n\nLeaf node in tree\n";
	leafNodeinTree(root);
		
}
