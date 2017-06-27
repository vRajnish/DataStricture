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

int maximumSumLevel(tree *root)
{
	int maxSum=0,sum=0,level=0,maxLevel=0;
	if(!root)
		return 0;
	queue<tree *> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty())
	{
		tree *temp=q.front();
		q.pop();
	
		if(temp==NULL)
		{
			
			if(maxSum<sum)
			{
				maxSum=sum;
				maxLevel=level;
			}
			sum=0;
			level++;
			if(!q.empty())
				q.push(NULL);
		
		}
		else
		{
			sum+=temp->data;
			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
		}
		
	}
	return maxLevel;
}

int main()
{
	tree *root=new tree;
	root->data=200;
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
	cout<<maximumSumLevel(root);			
}
