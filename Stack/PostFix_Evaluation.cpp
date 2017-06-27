#include<bits/stdc++.h>
using namespace std;
int main()
{
	stack<int> s;
	string s1="123*+5-";
	int i=0,j=s1.length()-1;
	while(i<=j)
	{
		if(s1[i]>=48 && s1[i]<=58)
		{
				s.push(s1[i]-48);
		}
		else
		{
			int n1=s.top();s.pop();
			int n2=s.top();s.pop();
			if(s1[i]=='+')
			{
				s.push(n1+n2);
			}
			else
			if(s1[i]=='-')
			{
				s.push(n2-n1);
			}
			else
			if(s1[i]=='/')
			{
				s.push(n1/n2);
			}
			else
			if(s1[i]=='*')
			{
				s.push(n1*n2);
			}
		}
		i++;
	}
	cout<<s.top();
}
