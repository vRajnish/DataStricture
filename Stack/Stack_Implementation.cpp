
/* 
	Linked List based stack Implementation
	It is front insertion of linked list.
*/

#include<bits/stdc++.h>
using namespace std;
struct stackNode
{
	int data;
	stackNode *next;	
};
stackNode* push(stackNode *top,int data)
{
	stackNode *newNode=new stackNode;
	newNode->data=data;
	newNode->next=NULL;
	if(top==NULL)
		top=newNode;
	else
	{
		newNode->next=top;
		top=newNode;
	}
	return top;
}
stackNode *pop(stackNode* top)
{
	if(top==NULL)
		return NULL;
	else
	{
		stackNode *temp=top;
		top=top->next;
		free(temp);
	}
	return top;
}
void display(stackNode* top)
{
	while(top!=NULL)
	{
		cout<<"\n"<<top->data;
		top=top->next;
	}
}
int main()
{
	stackNode *top=NULL;
	top=push(top,5);
	top=push(top,4);
	top=push(top,3);
	top=pop(top);
	top=pop(top);
	top=pop(top);
	top=pop(top);
	top=push(top,2);
	top=push(top,1);
	top=pop(top);
	top=pop(top);
	top=pop(top);
	display(top);
}
