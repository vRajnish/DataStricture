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
int findMaxElement(tree *root)
{
	int  max_element=INT_MIN;
	queue<tree*> q;
	q.push(root);
	while(!q.empty())
	{
		tree *temp=q.front();
		q.pop();
		if(max_element<temp->data)
			max_element=temp->data;
		if(temp->left)
			q.push(temp->left);
		if(temp->right)
			q.push(temp->right);
	}
	return max_element;
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
	root->left->left->left=insertInTree(12);
	cout<<findMaxElement(root);
	
}
