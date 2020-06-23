#include <iostream>
using namespace std;
const int oo=1e9+7;
int m, n, res, a[1000][1000], d[1000], Free[1000], T[1000];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if (i!=j)	a[i][j]=oo;
	for(int i=1;i<=m;i++)
	{
		int u, v, w;
		cin>>u>>v>>w;
		a[u][v]=w,	a[v][u]=w;
	}
	d[1]=0, Free[1]=1;
	for(int i=2;i<=n;i++)	d[i]=oo,	Free[i]=1;
	for(int k=1;k<=n;k++)
	{
		int u=0, MIN=oo;
		for(int i=1;i<=n;i++)
			if (Free[i] && d[i]<MIN)	MIN=d[i],	u=i;
		if (u==0)
		{
			cout<<"Khong ton tai cay khung!";
			return 0;
		}
		Free[u]=0;
		for(int i=1;i<=n;i++)
			if (Free[i]==1 && d[i]>a[u][i])
			{
				d[i]=a[u][i];
				T[i]=u;
			}
	}
	cout<<"Cay khung nho nhat:\n";
	for(int i=2;i<=n;i++)
	{
		cout<<T[i]<<' '<<i<<' '<<a[T[i]][i]<<'\n';
		res=res+a[T[i]][i];
	}
	cout<<"Trong so cua cay khung nho nhat: "<<res;
	return 0;
}
