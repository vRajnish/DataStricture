#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node *next;
	node *prev;
};
node* Insert(node *start,int data)
{
	node *p=new node;
	p->data=data;
	p->prev=NULL;
	p->next=start;
	start->prev=p;
	
	return p;
	
}
void Traverse(node *start)
{
	while(start!=NULL)
	{
		cout<<"\n"<<start->data;
		start=start->next;
	}
}
node *Delete_At_Begining(node *start)
{
	//After moving start pointer make its previous to point to NULL
	
	node *p=start;
	start=start->next;
	start->prev=NULL;
	free(p);
	return start;
}
node *Deletion_At_End(node *start)
{
	node *initial_start=start;
	while(start->next!=NULL)
	{
		start=start->next;
	}
	start->prev->next=NULL;
	free(start);
	return initial_start;
}
node *Deletion_At_kth(node *start)
{
	node *initial_start=start;
	int k;
	cout<<"\n\nEnter position\n";
	cin>>k;
	k=k-1;
	while(start!=NULL && k!=0)
	{
		start=start->next;
		k--;
	}
	if(start==NULL || k!=0)
	{
		cout<<"\nCannot be Deleted";
		return initial_start;
	}
	if(k==0)
	{
		start->prev->next=start->next;
		free(start);
	}
	return initial_start;
}
int main()
{
	node *start=new node;
	start->data=5;
	start->next=NULL;
	start->prev=NULL;
	start=Insert(start,4);
	start=Insert(start,3);
	start=Insert(start,2);
	start=Insert(start,1);
	cout<<"\n\nBefore Deletion\n";
	Traverse(start);
	int ch;
	do
	{
		cout<<"\n\n1.Deletion At Begining"
			<<"\n\n2.Deletion At End"
			<<"\n\n3.Delete Kth node\t";
		cin>>ch;
		if(ch==1)
		{
			start=Delete_At_Begining(start);
			
		}
		if(ch==2)
		{
			start=Deletion_At_End(start);
		}
		if(ch==3)
		{
			start=Deletion_At_kth(start);
		}
	}while(ch!=0);
	
	cout<<"\n\nAfter Deleteion\n\n";
	Traverse(start);
		
}
