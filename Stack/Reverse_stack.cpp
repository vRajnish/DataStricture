#include<bits/stdc++.h>
using namespace std;

void display(stack<int> s)
{
	while(!s.empty())
	{
		cout<<s.top();
		s.pop();
	}
}
void insert(stack<int> *s,int data)
{
	int temp;
	if(s->empty())
	{
			s->push(data);
			return ;
	}
	temp=s->top();
	s->pop();
	insert(s,data);
	s->push(temp);
}
void reverse(stack<int> *s)
{
	int data;
	if(s->empty())
		return ;
	data=s->top();
	s->pop();
	reverse(s);
	insert(s,data);

	
}
int main()
{
	stack<int> s;
	s.push(5);
	s.push(4);
	s.push(3);
	s.push(2);
	s.push(1);
	display(s);
	cout<<"\nReverse\n";
	reverse(&s);
	display(s);
	
	
}
