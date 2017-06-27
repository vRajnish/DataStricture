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
void postOrder(tree *root)
{	
	stack<tree*> s1,s2;
	s1.push(root);
	while(!s1.empty())
	{
		tree *p=s1.top();
		s1.pop();
		s2.push(p);
		if(p->left)
			s1.push(p->left);
		if(p->right)
			s1.push(p->right);
	}
	while(!s2.empty())
	{
		cout<<s2.top()->data<<"\n";
		s2.pop();
	}
	
	/*
		Alternate Method for Post Order.
	stack<tree*> s;
	while(1)
	{
		while(root)
		{
			s.push(root);
			if(root->right)
			{
				root->right->data=-root->right->data;
				s.push(root->right);
			}
			root=root->left;
		}
		
		root=s.top();
		s.pop();
        while(!s.empty() && root->data>0 )
        {
        	
            cout<<root->data<<"\n";
            root=s.top();
           s.pop();
            
        }
        if(s.empty())
		{
			cout<<root->data<<"\n";
			break;
		}
		if(root->data<0)
		{
			root->data=-root->data;
		}
		
	}*/
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
	postOrder(root);
}
