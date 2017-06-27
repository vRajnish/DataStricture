#include<bits/stdc++.h>
using namespace std;
void reverse(queue<int> *Q,int k)
{
	stack<int> s;
	int i=0;
	while(!Q->empty() && i!=k)
	{
		s.push(Q->front());
		Q->pop();
		i--;
	}
	while(!s.empty())
	{
		Q->push(s.top());
		s.pop();
	}
	
	i=0;
	while(!Q->empty() && i!=Q->size()-k-1)
	{
		//cout<<"\nInserting\t"<<Q->front();
		Q->push(Q->front());
		Q->pop();
		i++;
	}
	
}
void display(queue<int> q)
{
	while(!q.empty())
	{
		cout<<q.front()<<"\n";
		q.pop();
	}
}
int main()
{
	queue<int> q;
	int k;
	cout<<"\nNo. of Elements to reverse\t";
	cin>>k;
	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);
	q.push(50);
	q.push(60);
	q.push(70);
	q.push(80);
	q.push(90);
	cout<<"\nElements in Queue\n";
	display(q);
	reverse(&q,k);
	cout<<"\nElements in Queue After reverse\n";
		display(q);
	
}
