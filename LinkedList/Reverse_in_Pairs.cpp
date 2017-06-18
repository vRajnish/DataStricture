
/*Reverse a Linked List in Pairs.
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
node *reversePair(node *head)
{
	node *temp;
	if(head==NULL || head->next==NULL)
		return head;
	else
	{
		temp=head->next;
		head->next=temp->next;
		temp->next=head;
		head=temp;
		head->next->next=reversePair(head->next->next);
		return head;
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
void revrsePair(node *start1)
{
	if(start1==NULL || start1->next==NULL)
		return ;
	node *prev=start1,*curr=start1->next;
	start1=curr;
	while(1)
	{
		node *next=curr->next;
		curr->next=prev;
		if(next==NULL ||  next->next==NULL)
		{
			prev->next=next;
			break;
		}
		prev->next=next->next;
		prev=next;
		curr=prev->next;
	}
	traverse(start1);
}
int main()
{
	node *start1=new node;
	start1->data=5;
	start1->next=create(8);
	start1->next->next=create(10);
	start1->next->next->next=create(12);
	start1->next->next->next->next=create(13);
	//start1=reversePair(start1);
	//traverse(start1);
	revrsePair(start1);
}
