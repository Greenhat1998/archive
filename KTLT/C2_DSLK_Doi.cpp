#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *next;
	node *prev;
};
struct List
{
	node *head;
	node *tail;
};
List L;
int n, x;
void init(List &L)
{
	L.head=NULL;
	L.tail=NULL;
}
node* make(int x)
{
	node *tmp=new node;
	tmp->data=x;
	tmp->next=NULL;
	tmp->prev=NULL;
	return tmp;
}
void insert_last(List &L, int x)
{
	node *tmp=make(x);
	if (L.head==NULL && L.tail==NULL) L.head=L.tail=tmp;
	else{
		L.tail->next=tmp;
		tmp->prev=L.tail;
		L.tail=tmp;
	}
}
void insert(List &L, int x, int p)
{
	node *tmp=make(x);
	if (p==1)
	{
		tmp->next=L.head;
		L.head->prev=tmp;
		L.head=tmp;
	}
	else{
		node *q=L.head;
		for(int i=1;i<=p-2;i++)	q=q->next;
		tmp->next=q->next;
		tmp->prev=q;
		q->next=tmp;
	}
}
void del(List &L, int p)
{
	if (p==1)
	{
		L.head=L.head->next;
		L.head->prev=NULL;
	}
	else{
		node *q=L.head;
		for(int i=1;i<=p-2;i++)	q=q->next;
		node *tmp=q->next;
		q->next=tmp->next;
		tmp->next=NULL;
	}
}
void input(List &L)
{
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		insert_last(L,x);
	}
}
void output(List L)
{
	for(node* q=L.head;q!=NULL;q=q->next)	cout<<q->data<<' ';
	cout<<'\n';
}
int main()
{
	init(L);
	cin>>n;
	input(L);
	output(L);
	insert(L,7,3);
	output(L);
	del(L,2);
	output(L);
	return 0;
}
