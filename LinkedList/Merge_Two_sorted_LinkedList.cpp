
// Program to merge two sorted in third list.

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
node *insert(node *start3,node *start2)
{
	node *p=new node,*start=start3;
	p->data=start2->data;
	p->next=NULL;
	if(start3==NULL)
	{
		start3=p;
		return start3;
	}
	else
	{
		node *q=start3;
		while(q->next!=NULL)
		{
			q=q->next;		
		}
		q->next=p;
	}
	return 	start;
	
}

void traverse(node *start)
{
	while(start!=NULL)
	{
		cout<<"\n"<<start->data;
		start=start->next;
	}
}
void mergeTomakeThirdList(node *start1,node *start2,node *start3)
{
	while(start1 && start2)
	{
		if(start1->data >start2->data)
		{
				start3=insert(start3,start2);
				start2=start2->next;
		}
		if(start1->data<start2->data)
		{
			start3=insert(start3,start1);
			start1=start1->next;
		}
	}
	while(start1!=NULL)
	{
		start3=insert(start3,start1);
		start1=start1->next;
	}
	while(start2!=NULL)
	{
		start3=insert(start3,start2);
		start2=start2->next;
	}
	cout<<"\nMerge List\n";
	traverse(start3);
}

int main()
{
	node *start1=new node,*start2=new node,*start3=NULL;
	
	//	Linked List First
	
	start1->data=5;
	start1->next=create(8);
	start1->next->next=create(10);
	start1->next->next->next=create(12);
	start1->next->next->next->next=create(13);
		
	traverse(start1);	
	//	Linked List Second
	
	start2->data=1;
	start2->next=create(3);
	start2->next->next=create(9);
	start2->next->next->next=create(11);
	start2->next->next->next->next=create(14);
	traverse(start2);
	mergeTomakeThirdList(start1,start2,start3);	
}

