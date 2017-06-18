#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node *prev;
	node *next;
};
node *Insert_At_Beg(node *start)
{
	/*
		Create new node
		Assign its next Pointer to start
		Point start prev pointer to new node
		Finally assign start to new node
	*/
	node *newnode=new node;
	cout<<"\n\nEnter data\n";
	cin>>newnode->data;
	newnode->next=start;
	start->prev=newnode;
	start=newnode;
	return start;
}
void Traverse(node *start)
{
	while(start!=NULL)
	{
		cout<<"\n"<<start->data;
		start=start->next;
	}
}
node *Insert_At_End(node *start)
{
	node *initial_start=start;
	while(start->next!=NULL)
	{
		start=start->next;
	}
	node *newnode=new node;
	cout<<"\nEnter data\n";
	cin>>newnode->data;
	newnode->next=NULL;
	start->next=newnode;
	newnode->prev=start;
	return initial_start;
}
node *Insert_At_Mid(node *start)
{
	int k;
	node *initial_start=start;
	cout<<"\nEnter Position\n";
	cin>>k;
	k=k-1;
	while(start!=NULL && k!=0)
	{
		start=start->next;
		k--;
	}
	if(start==NULL || k!=0)
	{
		cout<<"\nCannot be insert\n";
		return initial_start;
	}
	if(k==0)
	{
		node *newnode=new node;
		cout<<"\nEnter data\n";
		cin>>newnode->data;
		newnode->next=start->next;
		start->next->prev=newnode;
		start->next=newnode;
		newnode->prev=start;
	}
	return initial_start;
}
int main()
{
	node *start=new node;
	start->data=5;
	start->next=NULL;
	start->prev=NULL;
	int ch;
	do
	{
		cout<<"\n\n1.Insertion At begining"
			<<"\n\n2.Insertion At End"
			<<"\n\n3.Insertion At Middle";
		cin>>ch;
		if(ch==1)
		{
			start=Insert_At_Beg(start);
		}
		if(ch==2)
		{
			start=Insert_At_End(start);
		}
		if(ch==3)
		{
			start=Insert_At_Mid(start);
		}
			
	}while(ch!=0);
	cout<<"\n\nAfter Insertion\n";
	Traverse(start);
	
}
