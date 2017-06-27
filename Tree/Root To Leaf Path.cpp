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

void printNode(vector<int> v)
{
	for(vector<int>::iterator i=v.begin();i<v.end();i++)
		cout<<*i<<"\t";
	cout<<"\n";
}
void rootToLeafPath(tree *root,vector<int> v)
{
	if(root==NULL)
		return ;
	else
	{
		v.push_back(root->data);
		if(!root->left && !root->right)
			printNode(v);
		rootToLeafPath(root->left,v);
		rootToLeafPath(root->right,v);
	}
}

int main()
{
	tree *root=new tree;
	root->data=5;
	root->left=createTree(6);
	root->right=createTree(7);
	root->left->left=createTree(8);
	//root->left->right=createTree(9);
	root->right->left=createTree(10);
	root->right->right=createTree(11);	
	root->left->left->left=createTree(12);
	root->left->left->right=createTree(13);
	root->left->left->right->left=createTree(14);
	root->left->left->right->right=createTree(15);
	root->right->left->left=createTree(16);
	root->right->left->right=createTree(17);
	root->right->right->left=createTree(18);
	root->right->right->right=createTree(19);
	vector<int> v;	
	rootToLeafPath(root,v);
}
