/*
	Add Number represented by Linked List
	Ex:		Input 1->9->-9->9->NULL;
			Output	2->0->0->0->NULL;
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
node *reverse(node *p,node *prev)
{
	node *temp=p->next;
	p->next=prev;
	if(temp!=NULL)
	{
		return reverse(temp,p);
	}
	return p;
	
}
node *addOneToNumber(node *start)
{
	start=reverse(start,NULL);
	traverse(start);
	node *initialStart=start;
	int carry=1,sum;
	node *temp;
	while(start && carry)
	{
	
		sum=start->data+carry;
		if(sum>9)
		{
			start->data=sum%10;
			carry=sum/10;
		}
		else
		{
			start->data=sum;
			carry=sum/10;
		}
		temp=start;
		start=start->next;
	}
	if(carry && !start)
	{
		node *p=new node;
		p->data=carry;
		p->next=NULL;
		temp->next=p;
	}
	initialStart=reverse(initialStart,NULL);
	traverse(initialStart);
}
int main()
{
	node *start1=new node;
	start1->data=9;
	start1->next=create(9);
	start1->next->next=create(9);
	start1->next->next->next=create(9);
	start1=addOneToNumber(start1);
}
