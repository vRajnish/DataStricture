#include<bits/stdc++.h>
using namespace std;

int getConsecutive(stack<int> s)
{
	queue<int> q;
	int pair=1;
	while(!s.empty())
	{
		q.push(s.top());
		s.pop();
	}
	while(!q.empty())
	{
		s.push(q.front());
		q.pop();
	}
	while(!s.empty())
	{
		int n=s.top();
		s.pop();
		q.push(n);
		if(!s.empty())
		{
			int m=s.top();
			s.pop();
			q.push(m);
			if(abs(n-m)!=1)
				pair=0;
		}
	
	}
	while(!q.empty())
	{
		s.push(q.front());
		q.pop();
	}
	return pair;
}
int main()
{
	stack<int> s;
	s.push(4);
	s.push(5);
	s.push(-2);
	s.push(-3);
	s.push(11);
	s.push(10);
	s.push(5);
	s.push(6);
	s.push(20);
	s.push(21);
	int consecutiveTrue=getConsecutive(s);
	if(consecutiveTrue)
		cout<<"\nPair are consecutive\n";
	else
		cout<<"\nPair are not consecutive\n";
}
