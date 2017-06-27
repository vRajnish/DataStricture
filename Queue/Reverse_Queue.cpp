#include<bits/stdc++.h>
using namespace std;
void reverse(queue<int> *q)
{
	stack<int> s;
	while(!q->empty())
	{
		s.push(q->front());
		q->pop();		
	}
	while(!s.empty())
	{
		q->push(s.top());
		s.pop();
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
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	cout<<"\nElement before Reverse\n";
	display(q);
	reverse(&q);
	cout<<"\nElement After Reverse\n";
	display(q);
}
