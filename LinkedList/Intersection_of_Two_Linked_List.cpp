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
void intersectOfLinkedList(node *start1,node *start2)
{
	/*
		1.Brute Force	Compare every node of second List with first List	Matching node Pointer 
						will give you Intersection.	O(square(n))
		2.Hashing
			Take any List and store all its address in hash Table.
			Now Traverse other List and check same pointer exist in hash tables
			The very first match will give you Intersection
			Complexity O(n), Space O(n).
		3. Stack (Two Stack)
			Traverse First List and store all address in First Stack
			Traverse Second List and store all address in Second  Stack.
			Now pop the element from both stack until both stack have same address.
			Complexity O(m+n),Space O(m+n)
		4. Efficient one.
			Find length of both List (L1 & L2). Take difference d=|(L1-L2)|.
			Move d step in Longest List.
			Now move head of Both list until next node matches.
	*/
	int L1=0,L2=0,diff;
	node *temp1=start1,*temp2=start2;
	while(temp1!=NULL)
	{
			L1++;
			temp1=temp1->next;
	}
	while(temp2!=NULL)
	{
			L2++;
			temp2=temp2->next;
	}
	if(L1>L2)
	{
		diff=L1-L2;
		temp1=start1;
		temp2=start2;
	}
	else
	{
		diff=L2-L1;
		temp1=start2;
		temp2=start1;
	}
	while(diff!=0)
	{
		temp1=temp1->next;
		diff--;
	}
	while(temp1!=NULL && temp2!=NULL)
	{
		if(temp1==temp2)
		{
			cout<<"\n\nIntersection Of LinkedList"<<temp1->data;
			break;
		}
		temp1=temp1->next;
		temp2=temp2->next;
	}
}
int main()
{
	node *start1=new node,*start2=new node;
	start1->data=5;
	start1->next=create(6);
	start1->next->next=create(7);
	start2->data=8;
	start2->next=create(9);
	start2->next->next=create(10);
	start2->next->next->next=create(11);
	start2->next->next->next->next=create(12);
	start2->next->next->next->next->next=create(13);	
	start1->next->next->next=start2->next->next->next->next;
	cout<<"\n\nList One\n";
	traverse(start1);
	cout<<"\n\nList Two\n";
	traverse(start2);	
	intersectOfLinkedList(start1,start2);
}
