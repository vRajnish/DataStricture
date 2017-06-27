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

void deleteTreeWithoutRecursion(tree *root)
{
	if(!root)
		return ;
	queue<tree *>q;
	q.push(root);
	stack<tree*> s;
	while(!q.empty())
	{
		tree *temp=q.front();
		s.push(q.front());
		q.pop();
		if(temp->left)
			q.push(temp->left);
		if(temp->right)
			q.push(temp->right);
	}
	while(!s.empty())
	{
		tree *temp=s.top();
		s.pop();
		free(temp);
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
	cout<<root->data<<"\n";
	deleteTreeWithoutRecursion(root);
	cout<<root->data;
}
