#include<bits/stdc++.h>
using namespace std;
struct queueArray
{
	int front,rear,capacity;
	int *array;
};
queueArray* createQueue(int size)
{
	queueArray *q=new queueArray;
	q->capacity=size;
	q->front=q->rear=-1;
	q->array=new int;
	return q;
}
int isEmptyQueue(queueArray *q)
{
	return q->front==-1;
}
int isFullQueue(queueArray *q)
{
	return (q->rear+1)%q->capacity==q->front;
}
void push(queueArray* q,int data)
{
	if(isFullQueue(q))
	{
		cout<<"\nOverFlow\n";
	}
	q->rear=(q->rear+1)%q->capacity;
	if(q->front==-1)	
		q->front=q->rear;

	q->array[q->rear]=data;
	
}
void pop(queueArray *q)
{
	if(isEmptyQueue(q))
		cout<<"\nUnderFlow";
	else
	{
		if(q->front==q->rear)
			q->front=q->rear=-1;
		else
			q->front=(q->front+1)%q->capacity;
	}
}
void display(queueArray *q)
{
	int i=q->front;
	cout<<q->array[q->front];
	while((i)%q->capacity!=q->rear)
	{
		
		cout<<q->array[(i+1)%q->capacity];
		i++;
	}
	
}
int main()
{
	queueArray *q=createQueue(5);
	push(q,1);
	push(q,2);
	push(q,3);
	push(q,4);
	push(q,5);
	pop(q);
	pop(q);
	push(q,6);
	display(q);
	pop(q);
	pop(q);
	pop(q);
}
