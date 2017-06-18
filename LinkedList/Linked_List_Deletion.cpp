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
node *Delete_At_Begining(node *start)
{
	/*
		It is very Simple just need to move head pointer. 
		But keep in mind moving head pointer will not actually delete the node
		So before moving hold that node in some temperary node then move head pointer
		After that free the temporary node;
	*/
	node *p=start;
	start=start->next;
	free(p);
	return start;
	
}
node *Deletion_At_End(node *start)
{
	/*
		One Extra pointer lets say Prev pointer pointing to one node prev 
		of current.
	*/
	node *prev=NULL,*initial_start=start;
	while(start->next!=NULL)
	{
		prev=start;
		start=start->next;
	}
	prev->next=NULL;
	free(start);
	return initial_start;
}
node *Deletion_At_kth(node *start)
{
	/*
		It is same as Deletion At end.
		Traverse till Given Pointer K.
	*/
	int k;
	cout<<"\n\nEnter Position\t";
	cin>>k;
	k=k-1;
	node *initial_start=start,*prev=NULL;
	while(start!=NULL && k!=0)
	{
		prev=start;
		start=start->next;
		k--;
	}
	if(start==NULL || k!=0)
		cout<<"\n\nCannot be Deleted";
	if(k==0)
	{
		prev->next=start->next;
		free(start);
	}
	return initial_start;
}
void Traverse(node *start)
{
	while(start!=NULL)
	{
		cout<<start->data<<"\t";
		start=start->next;
	}
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
