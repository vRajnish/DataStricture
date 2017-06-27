#include<bits/stdc++.h>
using namespace std;
struct tree
{
	int data;
	tree *left;
	tree *right;
};
tree *node(int data)
{
	tree *q=new tree;
	q->data=data;
	q->left=NULL;q->right=NULL;
	return q;
}
int findMax(tree *root)
{
	if(root->right)
		return root->right->data;
	else
		root->data;
}
int main()
{
	int arr[]={12,1,78,90,57,89,56};
	int n=sizeof(arr)/sizeof(arr[0]),k=3;
	for(int i=0;i<=n-k;i++)
	{
		cout<<max(arr[i],max(arr[i+1],arr[i+2]))<<"\n";
	}
	
	//Creating a BST of three node.
	
	cout<<"\nFrom BST\n";
	tree *root=new tree;
	root->left=NULL;
	root->right=NULL;	
	for(int i=0;i<=n-k;i++)
	{
		root->data=arr[i];
		if(arr[i+1]>root->data)	
			root->right=node(arr[i+1]);
		else
			root->left=node(arr[i+1]);
		if(arr[i+2]>root->data)	
			root->right=node(arr[i+2]);
		else
			root->left=node(arr[i+2]);
			
		cout<<findMax(root)<<"\n";
	}
	
	
}
