#include<bits/stdc++.h>
using namespace std;
int main()
{
	stack<char> s;
	string s1="((A+B)+[C-D])";
	int i=0,j=s1.length()-1;
	while(i<=j)
	{
	
		if(s1[i]=='(')
			s.push('(');
		else
		if(s1[i]=='{')
			s.push('{');
		else
		if(s1[i]=='[')
			s.push('[');
		else
		if(s1[i]==')' || s1[i]==']' || s1[i]=='}')
		{
		
			char c=s.top();
			if(s1[i]==')' && c!='(')
			{
			
				break;
			}
			else
			if(s1[i]==']' && c!='[')
			{
			
				break;
			}
			else
			if(s1[i]=='}' && c!='{')
			{
			
				break;
			}
			s.pop();
		}
		i++;
	}
	if(s.empty())
		cout<<"\nBalaced";
	else
	{
		cout<<"\nNot Balanced";
	}
}
