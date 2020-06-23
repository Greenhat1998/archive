// Tim duong di ngan nhat
#include <iostream>
#define MAX 100
#define oo 10000
using namespace std;
int m, n, s, f, a[MAX][MAX], d[MAX], Free[MAX], T[MAX];
void Dijkstra()
{
	while (1)
	{
		int u=0,	MIN=oo;
		for(int i=1;i<=n;i++)
			if (Free[i] && d[i]<MIN)	MIN=d[i],	u=i;
		if (u==0) 	break;
		Free[u]=0;
		for(int v=1;v<=n;v++)
			if (Free[v] && d[v]>d[u]+a[u][v])
			{
				d[v]=d[u]+a[u][v];
				T[v]=u;
			}
	} 
}
int main()
{
	cin>>n>>m;
	s=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if (i!=j)	a[i][j]=oo;
	for(int i=1;i<=m;i++)
	{
		int u, v, w;
		cin>>u>>v>>w;
		a[u][v]=w,	a[v][u]=w;
	}
	for(int i=1;i<=n;i++)	d[i]=a[s][i],	T[i]=s,	Free[i]=1;
	Dijkstra();
	for(int i=1;i<=n;i++)
	{
		cout<<i<<": \n\t";
		f=i;
		if (d[f]==oo)	cout<<"Khong ton tai duong di tu "<<s<<" den "<<i;
		else{
			cout<<"Do dai duong di ngan nhat: "<<d[f]<<"\n\t";
			while (f!=s)
			{
				cout<<f<<' ';
				f=T[f];
			}
			cout<<s;
		}
		cout<<'\n';
	}
	return 0;
}
