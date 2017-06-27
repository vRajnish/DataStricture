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

int heightWithoutRecursion(tree *root)
{
    int height=0;
    if(root==NULL)
        return 0;
    queue<tree*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        tree *temp=q.front();
        q.pop();
        if(temp==NULL)
        {
            if(!q.empty())
                q.push(NULL);
            height++;

        }
        else
        {
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
    return height;
}

int main()
{
    tree *root=new tree;
    root->data=5;
    root->left=createTree(6);
   // root->right=createTree(7);
    root->left->left=createTree(8);
   // root->left->left->left=createTree(9);
  //  root->left->right=createTree(10);
   // root->right->right=createTree(11);
    //root->right->right->right=createTree(12);
    cout<<"\nHeight of Tree\t"<<heightWithoutRecursion(root);
   
}
