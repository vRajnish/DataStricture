
// Find the Middle of Linked List.

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

void middleOfLinkedList(node *start)
{
	/*
		1.	Brute Force-->For each node check how many nodes are there after that node
						No of Node should be equal to index of that node.
			Complexity O(square(n)), Space O(1) 
	
		2.	Traverse a Linked List and find length Lets say n.
			Again Traverse n/2 times to get Middle.
			Complexity O(n), Space O(1)
		
		3.	Hash Table-->Store all address of node in hash Table
			As we know the size of hash table one can easily find middle m/2 for even and m/2+1 for odd;
			
		4.Efficient Two Pointer
			First Pointer move one step at a time second pointer move two step at a time.
			As soon as second pointer move to end of list print first pointer.
	*/
	node *slowPointer=start,*fastPointer=start;
	while(fastPointer && fastPointer->next)
	{
		slowPointer=slowPointer->next;
		fastPointer=fastPointer->next->next;
	}
	cout<<"\nMiddle of Linked List \t "<<slowPointer->data;
	
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
	middleOfLinkedList(start);
}
