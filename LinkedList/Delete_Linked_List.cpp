
/*
	Delete a Linked List
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
node *deleteLinkedList(node *start)
{
	if(start)
		deleteLinkedList(start->next);
	free(start);
	return NULL;
}
int main()
{
	node *start1=new node,*start2=new node,*start3=NULL;
	start1->data=5;
	start1->next=create(8);
	start1->next->next=create(10);
	start1->next->next->next=create(12);
	start1->next->next->next->next=create(13);
	start1->next->next->next->next->next=create(14);
	start1=deleteLinkedList(start1);	
}
