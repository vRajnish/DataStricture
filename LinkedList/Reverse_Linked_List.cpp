
// Reverse a Given Linked List

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

//Non Recursive Method

node *reverse(node *start)
{
	node *prev=NULL,*curr=start,*next1;
	next1=curr->next;
	curr->next=prev;
	prev=curr;
	curr=next1;
	while(curr!=NULL)
	{
			next1=curr->next;
			curr->next=prev;
			prev=curr;
			curr=next1;
	}
	return prev;
}

//Recursion Method

node *recurReverse(node *p,node *prev)
{
	node *temp=p->next;
	p->next=prev;
	if(temp!=NULL)
	{
		return recurReverse(temp,p);
	}
	return p;
	
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
	start->next=create(6);
	start->next->next=create(7);
	start->next->next->next=create(8);
	start->next->next->next->next=create(9);
	start->next->next->next->next->next=create(10);
	cout<<"\nReverse LinkedList without Recusion\n";
	start=reverse(start);
	traverse(start);
	cout<<"\nReverse LinkedList with Recusion\n";
	start=recurReverse(start,NULL);
	traverse(start);
	
}
