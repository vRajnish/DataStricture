/*
	Rotate a Linked List counter Clock wise or AntiClock wise after K nodes.
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
node* clockWise(node *start,int k)
{
	node *initialStart=start,*temp;
	int count=0;
	while(start && count<k)
	{
		temp=start;
		start=start->next;
		count++;
	}
	if(!start)
		return initialStart;
	while(start->next)
	{
		start=start->next;
	}
	
	start->next=initialStart;
	initialStart=temp->next;
	temp->next=NULL;
	return initialStart;
}
node *antiClockWise(node *start,int k)
{
	node *initialStart=start,*temp;
	int diff=0;
	while(start && diff!=k)
	{
		start=start->next;
		diff++;
	}
	temp=initialStart;
	while(start->next)
	{
		temp=temp->next;
		start=start->next;
	}
	start->next=initialStart;
	initialStart=temp->next;
	temp->next=NULL;
	return initialStart;
	
}
int main()
{
	node *start1=new node;
	start1->data=1;
	start1->next=create(2);
	start1->next->next=create(3);
	start1->next->next->next=create(4);
	start1->next->next->next->next=create(5);
	start1->next->next->next->next->next=create(6);
	start1->next->next->next->next->next->next=create(7);
	start1->next->next->next->next->next->next->next=create(8);
	start1->next->next->next->next->next->next->next->next=create(9);
	start1->next->next->next->next->next->next->next->next->next=create(10);
	cout<<"\n\nAntiClockWise Rotation\n";
	start1=antiClockWise(start1,4);
	traverse(start1);
	cout<<"\n\nClockWise Rotation\n";
	start1=clockWise(start1,4);
	traverse(start1);

}
