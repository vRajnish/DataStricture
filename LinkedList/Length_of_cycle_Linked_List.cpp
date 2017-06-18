
/*
	Program to find Start Node of Loop.
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
void findLengthOfCycle(node *slowPtr,node *fastPtr)
{
	/*
		The idea is that whenever the two pointer meet in loop
		make any of the two pointer to point one node ahead of meeting point.
		
		And Finally take count varible and increment until again both pointer meet.
	*/
	int count=0;
	while(slowPtr!=fastPtr)
	{
		fastPtr=fastPtr->next;
		count++;
	}
	cout<<count;
}
void checkLoopExistOrNot(node *start)
{

	node *fastPtr=start,*slowPtr=start;
	while(fastPtr->next && fastPtr)
	{
		
		slowPtr=slowPtr->next;
		fastPtr=fastPtr->next->next;
		if(slowPtr==fastPtr)
		{
			cout<<"\nLinked List Contain Loop\t\t";
			findLengthOfCycle(slowPtr,fastPtr->next);
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
