
// 	Implementing Stack Using LinkedList

//	It is also called as Linked List insertion from Front.

#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node *next;
};
void push(node **start)
{
	node *p=new node;
	cout<<"\nEnter Data\t";
	cin>>p->data;
	p->next=*start;
	*start=p;
}
void pop(node **start)
{
	node *p=*start;
	*start=p->next;
	free(p);
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
	push(&start);
	push(&start);
	push(&start);
	pop(&start);
	push(&start);
	pop(&start);
	push(&start);
	traverse(start);
}
