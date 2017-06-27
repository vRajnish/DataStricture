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
int searchElement(tree *root,int k)
{
	if(!root)
		return 0;
	queue<tree*> q;
	q.push(root);
	while(!q.empty())
	{
		tree *temp=q.front();
		q.pop();
		if(temp->data==k)
			return 1;
		if(temp->left)
			q.push(temp->left);
		if(temp->right)
			q.push(temp->right);
		
	}
	return 0;
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
	cout<<searchElement(root,12);
	
}
