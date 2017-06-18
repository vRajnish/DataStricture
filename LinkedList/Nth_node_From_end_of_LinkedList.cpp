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
void traverse(node *start)
{
	while(start!=NULL)
	{
		cout<<"\n"<<start->data;
		start=start->next;
	}
}
int nthNode(node * start,int n)
{
	// The code I have written is Efficient one
	
	//Here I am assuming that n is less then  total node in Linked List
	
	//There are many ways to solve.
	/*
		1. Count the total node in linked list. Subtract the total from the N and then traverse (total-N).
		2. Using Hash Table 
			Ex:  map<int,node*> m;
				 where int is representing position of node and node is holding address to that node.
				 Finally you can get nth node by m-n+1. where m is size of map.
				 
		3.	Use Two pointer. Below is the code.
	*/
	node *diffPointer=start,*ptr=start;
	n=n-1;
	while(n!=0)
	{
		diffPointer=diffPointer->next;
		n--;
	}
		
	while(diffPointer->next!=NULL)
	{
		diffPointer=diffPointer->next;
		ptr=ptr->next;
	}
	return ptr->data;
	
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
	cout<<"\n\nNth node From End is\t"<<nthNode(start,4);
	
}
