#include<bits/stdc++.h>
using namespace std;
int main()
{
	stack<int> s;
	int arr[7]={5,3,6,7,2,1,2},s1[7];
	s1[0]=1;
	s.push(0);
	for(int i=1;i<7;i++)
	{
		while(!s.empty() && arr[i]>=arr[s.top()])
			s.pop();
		if(s.empty())
			s1[i]=i+1;
		else
			s1[i]=i-s.top();
		s.push(i);
	}
	for(int i=0;i<7;i++)
		cout<<s1[i];
	
}
