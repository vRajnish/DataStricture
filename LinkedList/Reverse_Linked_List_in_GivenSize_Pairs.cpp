
/*Reverse a Linked List in given size of Pairs n=2.
	Input=	1->2->3->4->NULL;
	Output=	2->1->4->3-NULL;

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
void traverse(node *start)
{
	while(start!=NULL)
	{
		cout<<"\n"<<start->data;
		start=start->next;
	}
}

node * reverseInGivenPair(node *head,int k)
{
	node *curr=head,*prev=NULL,*next=NULL;
	int count=0;
	while(curr!=NULL && count<k)
	{
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
		count++;
	}
	if(next!=NULL)
		head->next=reverseInGivenPair(next,k);
	return prev;
}
int main()
{
	node *start1=new node;
	start1->data=5;
	start1->next=create(8);
	start1->next->next=create(10);
	start1->next->next->next=create(12);
	start1->next->next->next->next=create(13);
	start1->next->next->next->next->next=create(14);
	traverse(reverseInGivenPair(start1,3));
	
}
