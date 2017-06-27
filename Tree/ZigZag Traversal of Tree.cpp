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

void zigZagTraversal(tree *root)
{
	if(root==NULL)
		return ;
	stack<tree *> s1,s2;
	s1.push(root);
	int direction=1;
	while(!s1.empty())
	{
		tree *temp=s1.top();
		s1.pop();
		if(temp)
		{
			cout<<temp->data<<"\t";
			if(direction)
			{
				s2.push(temp->left);
				s2.push(temp->right);
			}
			else
			{
				s2.push(temp->right);
				s2.push(temp->left);
			}
		}
		if(s1.empty())
		{
			direction=direction^1;
			swap(s1,s2);
		}
	}
}

int main()
{
	tree *root=new tree;
	root->data=1;
	root->left=createTree(2);	
	root->right=createTree(3);
	root->left->left=createTree(4);
	root->left->right=createTree(5);
	root->right->left=createTree(6);
	root->right->right=createTree(7);
	zigZagTraversal(root);
}
