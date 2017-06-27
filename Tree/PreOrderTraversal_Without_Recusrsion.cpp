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
void preOrder(tree *root)
{	
	int count=0;
	stack<tree*> s;
	while(1)
	{
		while(root)
		{
			cout<<root->data<<"\n";
			if(root->right || root->left)
			{
				count++;
				s.push(root->right);
			}
			root=root->left;
			
		}
		if(s.empty())
			break;
		root=s.top();
		s.pop();
	}
	cout<<"\nHeight\t"<<count<<"\n\n";
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
	root->right->right->right=insertInTree(13);
	root->right->right->left=insertInTree(12);
	root->right->right->left->right=insertInTree(14);
	
	
	preOrder(root);
}
