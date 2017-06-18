
// Print Linked List in reverse order.

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

void printReverse(node *start)
{
	if(start->next)
		printReverse(start->next);
	cout<<"\n"<<start->data;
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
	start->next->next->next->next->next->next=create(11);
	printReverse(start);
}
