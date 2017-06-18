/*
	Identical Linked List
	When both Linked List have same data and dtructure arangement.

*/
#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node *next;
};

node * create(int data)
{
	node *p=new node;
	p->data=data;
	p->next=NULL;
	return p;
}
int checkIdentical(node *start1,node *start2)
{
	//Recusive Way
	/*if(start1==NULL && start2==NULL)
		return 1;
	if(start1!=NULL && start2!=NULL)
	{
		return (start1->data==start2->data) && checkIdentical(start1->next,start2->next);
	}
	return 0;*/
	
	int i=0;
	//Non Recursive way
	while(start1 && start2)
	{
		if(start1->data!= start2->data)
		{
			return 0;
		}
		start1=start1->next;
		start2=start2->next;
	}
	if(start1==NULL && start2==NULL)
		return 1;
	else
		return 0;
}
int main()
{
	node *start1=new node,*start2=new node;
	start1->data=5;
	start1->next=create(8);
	start1->next->next=create(10);
	start2->data=5;
	start2->next=create(8);
	start2->next->next=create(10);
//	start2->next->next->next=create(12);
	int i=checkIdentical(start1,start2);
	if(i)
		cout<<"\nIdentical";
	else
		cout<<"\nNot Identical";
}
