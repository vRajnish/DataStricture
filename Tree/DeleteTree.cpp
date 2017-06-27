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

void deleteTree(tree *root)
{
	if(root==NULL)
		return;
	
	deleteTree(root->left);
	deleteTree(root->right);
	free(root);
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
	root->right->right->right=createTree(11); 
	cout<<root->data<<"\n";
	deleteTree(root);
	cout<<root->data<<"\n";

}
