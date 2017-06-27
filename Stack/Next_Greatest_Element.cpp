#include<bits/stdc++.h>
using namespace std;
int main()
{
	int arr[4]={11,13,21,3},s1[4];
	stack<int> s;
	for(int i=0;i<4;i++)
	{
		if(s.empty())
			s.push(i);
		else
		if(arr[i]<arr[s.top()])
		{
			s.push(i);
		}
		else
		{
			while(!s.empty() && arr[i]>arr[s.top()])
			{
				s1[s.top()]=arr[i];
				s.pop();
			}		
			s.push(i);
		}
		
	}
	while(!s.empty())
	{
		s1[s.top()]=-1;
		s.pop();
	}
	for(int i=0;i<4;i++)
		cout<<s1[i]<<"\n";
}
