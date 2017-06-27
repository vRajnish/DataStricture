#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s="ababXbaba";
	stack<char> s1;
	int i=0,j=s.length();
	while(i<j)
	{
		if(s[i]=='X')
		{
			break;
		}
		s1.push(s[i]);
		i++;
	}
	i+=1;
	while(i<j)
	{
		if(s[i]!=s1.top())
		{
				cout<<"\nNot palindrome";
				break;
		}
		s1.pop();
		i++;
	}
	if(i==j)
		cout<<"\nPalindrome";
}
