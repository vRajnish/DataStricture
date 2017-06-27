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
void inOrder(tree *root)
{	
	stack<tree*> s;
	while(1)
	{
		while(root)
		{
			s.push(root);
			root=root->left;
		}
		if(s.empty())
			break;
		root=s.top();
		s.pop();
		cout<<root->data<<"\n";
		root=root->right;
		
	}
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
	inOrder(root);
}
