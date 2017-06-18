
/*
	Program to Check Whether Linked List is Null terminated or End in Loop.
	Also called as check Whether Linked List is snake or snail.
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
void checkLoopExistOrNot(node *start)
{
	/* 	1.	Brute Force start with first node and check whether there is node 
			whose next pointer point to current node.	complexity O(n) ,space O(1)
		2.	Hashing	
			Traverse List and check one by one whether the address is present in hash table or not
			complexity O(n), space O(n)
		3.	Efficient one by using Two pointer
			complexity O(n), space O(1)
			
	*/
	node *fastPtr=start,*slowPtr=start;
	while(fastPtr->next && fastPtr)
	{
		
		slowPtr=slowPtr->next;
		fastPtr=fastPtr->next->next;
		if(slowPtr==fastPtr)
		{
			cout<<"\nLinked List Contain Loop";
			break;
		}
	}
	if(!fastPtr->next)
		cout<<"\nLinked List is NULL Terminated";
	
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
	start->next->next->next->next->next->next->next=create(12);
	start->next->next->next->next->next->next->next->next=create(13);
	
	//	Checking when Linked List is NULL terminated
	
	checkLoopExistOrNot(start);
	
	//Creating Loop from given index	
	
	node *indexptr=start,*temp=start;
	int index=3;
	index--;
	while(temp->next!=NULL)
	{
		temp=temp->next;
		if(index!=0)
		{
			indexptr=indexptr->next;
			index--;
		}	
	}
	temp->next=indexptr;
	
	//	Checking when Linked List End in Loop
	
	checkLoopExistOrNot(start);
 }
