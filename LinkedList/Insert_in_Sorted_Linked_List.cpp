
// Program to insert Node  in sorted Linked List.

#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node *next;
};
void insertInSortedLinkedList(node ** start,int data)
{
	node *curr=*start,*newNode=new node;
	newNode->data=data;
	newNode->next=NULL;
	
	//	Case when start data is greater then data.
	
	if(curr->data>data)
	{
		newNode->next=*start;
		*start=newNode;
	}
	else
	{
		node *prev=NULL;
		while(curr!=NULL && curr->data<data)
		{
			prev=curr;
			curr=curr->next;
		}
		
		//	Case when number is greatest among all node in List
		
		if(curr==NULL)
			prev->next=newNode;
		else
		{
			newNode->next=curr;
			prev->next=newNode;
		}
	
	}
}
void traverse(node *start)
{
	while(start!=NULL)
	{
		cout<<"\n"<<start->data;
		start=start->next;
	}
}
int main()
{
	node *start=new node;
	start->data=5;
	start->next=NULL;
	insertInSortedLinkedList(&start,6);
	insertInSortedLinkedList(&start,1);
	insertInSortedLinkedList(&start,3);
	insertInSortedLinkedList(&start,8);
	insertInSortedLinkedList(&start,4);
	insertInSortedLinkedList(&start,7);
	insertInSortedLinkedList(&start,10);
	insertInSortedLinkedList(&start,9);
	traverse(start);
}
