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

void printLevelOrderInReverseOrder(tree *root)
{
	queue<tree*> q;
	stack<int> s; 
	if(root==NULL)
		return ;
	q.push(root);
	while(!q.empty())
	{
		tree *temp=q.front();
		q.pop();
		s.push(temp->data);
		if(temp->right)
			q.push(temp->right);
		if(temp->left)
			q.push(temp->left);
		
		
	}
	while(!s.empty())
	{
		cout<<s.top()<<"\n";
		s.pop();
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
	root->right->right->right=createTree(12); 
	printLevelOrderInReverseOrder(root);
}
