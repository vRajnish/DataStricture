#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node *next;
};
void insert_At_Front(node **start)
{
	node *p=new node,*curr=*start;
	cout<<"\n\nEnter Data \t";
	cin>>p->data;
	p->next=p;
	while(curr->next!=*start)
		curr=curr->next;
	p->next=*start;
	curr->next=p;
	*start=p;
	
}
void insert_At_End(node **start)
{
	node *curr=*start;
	while(curr->next!=*start)
	{
		curr=curr->next;
		
	}
	node *p=new node;
	cout<<"\nEnter Data\t";
	cin>>p->data;
	p->next=curr->next;
	curr->next=p;
}
void Traverse(node *start)
{
	node *curr=start;
	do
	{
		cout<<curr->data<<"\n";
		curr=curr->next;
	}while(curr!=start);
}
void delete_From_Front(node **start)
{
	node *temp=*start,*curr=*start;	
	while(curr->next!=*start)
		curr=curr->next;
	curr->next=temp->next;
	*start=temp->next;
	free(temp);
}
void delete_From_End(node **start)
{
	node *curr=*start,*prev=NULL;
	while(curr->next!=*start)
	{
		prev=curr;
		curr=curr->next;
	}
	prev->next=*start;
	free(curr);
}
int main()
{
	node *start=new node;
	start->data=5;
	//When only one node it should point to itself
	start->next=start;
	int ch;
	do
	{
		cout<<"\n\n1.Insert At Front"
			<<"\n\n2.Insert At End"
			<<"\n\n3.Delete From Front"
			<<"\n\n4.Delete From End\t";
		cin>>ch;
		if(ch==1)
		{
			insert_At_Front(&start);
		}
		if(ch==2)
		{
			insert_At_End(&start);
		}
		if(ch==3)
		{
			delete_From_Front(&start);
		}
		if(ch==4)
		{
			delete_From_End(&start);
		}
		
	}while(ch!=0);
	Traverse(start);
}
