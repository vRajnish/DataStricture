#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node *next;
};
node *create(int data)
{
	node *p=new node;
	p->data=data;;
	p->next=NULL;
	return p;
}
void Traverse(node *start)
{
	while(start!=NULL)
	{
		cout<<start->data<<"\t";
		start=start->next;
	}
}

//Insertion At Begining
node *Insert_At_Begining(node *start)
{
	//In this insertion is in O(1) time.
	
	cout<<"\nInsertion At Beginging";
	node *p=new node;
	cout<<"\nEnter data";
	cin>>p->data;
	p->next=start;
	start=p;
	return start;
}
node *Insertion_At_End(node *start)
{
	//In this insertion is in O(n).	where n is number of nodes.
	cout<<"\nInsertion At End";
	node *p=new node,*Initial_start=start;
	cout<<"\nEnter Data";
	cin>>p->data;
	p->next=NULL;
	while(start->next!=NULL)
	{
		start=start->next;
	}
	start->next=p;
	return Initial_start;
	
}
node *Insertion_At_kth(node *start)
{
	int k;
	//Insertion At given Position
	cout<<"\nEnter Position";
	cin>>k;
	k=k-1;
	node *initial_start=start,*p=new node;
	while(start!=NULL && k!=0)
	{
		start=start->next;
		k--;
	}
	if(start==NULL || k!=0)
		cout<<"\nCannot be insert";
	if(k==0)
	{
		cout<<"\nEnter data";
		cin>>p->data;
		p->next=start->next;
		start->next=p;	
	}	
	return initial_start;
}
int main()
{
	//Creating a Linked List
	
	//Initially I have 5->6->7->8	in my List;
	
	node *start=NULL;
	node *p=new node;
	p->data=5;
	p->next=create(6);
	p->next->next=create(7);
	p->next->next->next=create(8);
	start=p;
	cout<<"\n\nList Before Insertion\n\n";
	Traverse(start);
	
	//Now Insertion in List
	int ch;
	do
	{
		cout<<"\n\n1.Insertion At Begining"
			<<"\n\n2.Insertion At End"
			<<"\n\n3.Insertion at Kth position\t";
		cin>>ch;
		if(ch==1)
		{
			start=Insert_At_Begining(start);
			
		}
		if(ch==2)
		{
			start=Insertion_At_End(start);
		}
		if(ch==3)
		{
			start=Insertion_At_kth(start);
		}
	}while(ch!=0);
	
	cout<<"\n\nAfter Insertion\n\n";
	Traverse(start);
	
			
}
