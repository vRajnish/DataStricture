#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s="(A+(B*C+D)*D)";
    int i=0,j=s.length()-1;
    stack<char> s1;
    while(i<=j)
    {
        if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            s1.push(s[i]);
        else
        if(s[i]>=65 && s[i] <=92)
            cout<<s[i];
        else
        {
            if(s[i]=='+' || s[i]=='-')
            {
                if(s1.empty())
                    s1.push(s[i]);
                else
                {
                    char c=s1.top();
                    while(c=='*' || c=='/' || c=='+' || c=='-')
                    {
                        cout<<c;
                        s1.pop();
                        c=s1.top();
                    }
                    s1.push(s[i]);
                }
            }
            if(s[i]=='*' || s[i]=='/')
            {

                if(s1.empty())
                    s1.push(s[i]);
                else
                {
                    char c=s1.top();
                    while(c=='*' || c=='/')
                    {
                        cout<<c;
                        s1.pop();
                        c=s1.top();
                    }
                    s1.push(s[i]);
                }
            }
            if(s[i]==')' || s[i]=='}' || s[i]==']')
            {

                while(s1.top()!='(')
                {
                    if(s1.top()!='(')
                    {
                        cout<<s1.top();
                        s1.pop();
                    }
                }
                s1.pop();
            }

        }
        i++;
    }
    if(!s1.empty())
    {
    	cout<<s1.top();
    	s1.pop();
	}
}
