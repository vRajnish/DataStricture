#include<bits/stdc++.h>
using namespace std;
int main()
{
	stack<char> s1;
	string s="abcd";
	int i=0,j=s.length();
	while(i<j)
	{
		s1.push(s[i]);
		i++;
	}
	i=0;
	while(!s1.empty())
	{
		s[i]=s1.top();
		s1.pop();
		i++;
	}
	cout<<s;
}
