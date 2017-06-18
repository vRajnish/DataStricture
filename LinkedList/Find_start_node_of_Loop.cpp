
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
void findStartNode(node *start,node *fastPtr)
{
	/*
		Whenever there is loop in linked list It follows the property of 
		tortise and hare. They will always meet at mid of Loop
		So when you traverse one pointer from start and other pointer 
		from the point where they meet they always end up meeting at starting point.
		
		This is what I did in below code.
	*/
	while(start!=fastPtr)
	{
		start=start->next;
		fastPtr=fastPtr->next;
	}
	cout<<start->data;
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
			findStartNode(start,fastPtr);
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
