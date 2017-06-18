
// Program to find Linked List is of Even or Odd length.

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
void findLengthEvenOrOdd(node *start)
{
	/* 1. Count No of Node in List.	if N%2==0 even else Odd.
		
	   2. Use  Pointer moving 2 step each time. Efficient one
	   		if Even then it will point to NULL.
	   		if Odd then it will point to Last node.
	*/
	node *ptr=start;
	while(ptr && ptr->next )
	{
		ptr=ptr->next->next;
	}
	if(!ptr)
		cout<<"\nEven";
	else
		cout<<"\nOdd";
}
int main()
{
	node *start=new node;
	start->data=5;
	start->next=create(6);
	start->next->next=create(7);
	start->next->next->next=create(8);
	start->next->next->next->next=create(9);
	start->next->next->next->next->next=create(10);
	start->next->next->next->next->next->next=create(11);
	findLengthEvenOrOdd(start);
}
