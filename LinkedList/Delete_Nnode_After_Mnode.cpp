/*
	Given M and N
	W.A.P to delete N node After M node untill list is not NULL.
	Ex:
		1->2->3->4->5->6->NULL	M=2 , N=2
		1->2->5->6->NULL
*/
#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node *next;
};
node * create(int data)
{
	node *p=new node;
	p->data=data;
	p->next=NULL;
	return p;
}
node *deleteNnodeAfterMnode(node *start,int m,int n)
{
	node *initialStart=start;
	while(start)
	{
		int count=0;
		node *p;
		while(start && count<m )
		{
			p=start;
			start=start->next;
			count++;	
		}
		count=0;
		while(start && count<n)
		{
			/*
				Here We have to delete node not skip the node
				That is why I have first taken node in temporary and then moving pointer.
			*/
			node *temp=start;
			start=start->next;
			free(temp);
			count++;
		}
		p->next=start;
	}
	return initialStart;
}

void traverse(node *start)
{
	while(start!=NULL)
	{
		cout<<"\n"<<start->data;
		start=start->next;
	}
}
int main()
{
	node *start1=new node;
	start1->data=1;
	start1->next=create(2);
	start1->next->next=create(3);
	start1->next->next->next=create(4);
	start1->next->next->next->next=create(5);
	start1->next->next->next->next->next=create(6);
	start1->next->next->next->next->next->next=create(7);
	start1->next->next->next->next->next->next->next=create(8);
	start1->next->next->next->next->next->next->next->next=create(9);
	start1->next->next->next->next->next->next->next->next->next=create(10);
	cout<<"\nLinked List Before Deletion\n";
	traverse(start1);
	start1=deleteNnodeAfterMnode(start1,1,1);
	cout<<"\nLinked List After Deletion\n";	
	traverse(start1);
}
