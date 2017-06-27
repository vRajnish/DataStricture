#include<bits/stdc++.h>
using namespace std;
int main()
{
	// In this input should only be of {[()]} in any order it should not include operator and operand.
	string s="[(())]()";
	int i=0,j=s.length()-1;
	while(i<j)
	{
		
		if(s[i]=='(' && s[j]!=')')
		{
			cout<<"\nNot balance";
			break;
		}
		else
		if(s[i]=='{' && s[j]!='}')
		{
			cout<<"\nNot balance";
			break;
		}
		else
		if(s[i]=='[' && s[j]!=']')
		{
			cout<<"\nNot balance";
			break;
		}
		else
		{
			i++;
			j--;
		}
	}/*
	if(i==j)
	{
		cout<<"\nNot balance";
	}*/
	if(i>=j)
		cout<<"balance";	
}
