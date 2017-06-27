#include<bits/stdc++.h>
using namespace std;
int main()
{
		int arr[7]={100,80,60,70,60,75,85},s[7];
	s[0]=1;
	for(int i=1;i<7;i++)
	{
		int j=0;
		while(j<i && arr[i]>arr[i-j-1])
		{
			j+=1;
		}
		s[i]=j+1;
	}
	for(int i=0;i<7;i++)
		cout<<s[i];
}
