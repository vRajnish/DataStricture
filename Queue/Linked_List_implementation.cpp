#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node *next;
}*start=NULL;
struct Queue
{
	node *front;
	node *rear;
};
Queue *createQueue()
{
	Queue *q=new Queue;
	q->front=q->rear=NULL;
	return q;
}
void Enqueue(Queue *q,int data)
{
	node *p=new node;
	p->data=data;
	p->next=NULL;
	if(q->rear)
		q->rear->next=p;
	q->rear=p;
	if(q->front==NULL)
		q->front=q->rear;
	
}
int isEmptyQueue(Queue *q)
{
	return q->front==NULL;
}
void Dequeue(Queue *q)
{
	if(isEmptyQueue(q))
		cout<<"\nUnderFlow\n";
	else
	{
		node *temp=q->front;
		q->front=q->front->next;
		free(temp);
	}
}
void display(Queue *q)
{
	Queue *q1=createQueue();
	q1->front=q->front;
	q1->rear=q->rear;
	while(q1->front!=q1->rear->next)
	{
		cout<<q1->front->data;
		q1->front=q1->front->next;
	}
}
int main()
{
	Queue *q=createQueue();
	Enqueue(q,1);
	Enqueue(q,2);
	Enqueue(q,3);
	Enqueue(q,4);
	display(q);
	

	Dequeue(q);
}
