#include<bits/stdc++.h>
using namespace std;
int main()
{
	stack<int> s;
	int min=INT_MAX,n;
	cout<<"\nEnter no. of Element in stack\t";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		if(min>x)
			min=x;
		s.push(x);
		
	}
	cout<<"\nMin is\t"<<min;
}
