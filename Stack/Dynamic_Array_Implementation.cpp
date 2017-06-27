
/* Dynamic Implementation of stack
	In this no overflow condition because as I get the true for full stack I am doubling stack capacity.
*/

#include<bits/stdc++.h>
using namespace std;
struct stackNode
{
	int top;
	int capacity;
	int *array;
};
stackNode *createStack()
{
	stackNode *s=new stackNode;
	s->capacity=1;
	s->top=-1;
	s->array=new int;
	return s;
}
int isEmptyStack(stackNode *s)
{
	return (s->top==-1);
}
int isFullStack(stackNode *s)
{
	return (s->top==s->capacity-1);
}
void increaseSize(stackNode *s)
{
	cout<<"\nSize Increased";
	s->capacity*=2;
}
void push(stackNode *s,int data)
{
	if(isFullStack(s))
		increaseSize(s);
	s->array[++s->top]=data;
}
void pop(stackNode *s)
{
	if(isEmptyStack(s))
		cout<<"\nUnderFlow";
	else
	{
		s->array[s->top--];
	}
}
void print(stackNode *s)
{
	while(s->top!=-1)
	{
		cout<<"\n"<<s->array[s->top--];
	}
}
int main()
{
	stackNode *s=createStack();	
	push(s,5);
	push(s,4);
	push(s,3);
	push(s,2);
	push(s,1);

	
	cout<<"\n\nElements is stack\n";
	print(s);
}

