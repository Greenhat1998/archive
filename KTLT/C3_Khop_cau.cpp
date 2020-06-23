#include <iostream>
using namespace std;
int n, m, cnt, num[1000], low[1000], T[1000], a[1000][1000], C[1000], flag[1000];
void DFS(int u)
{
	cnt++;
	num[u]=cnt, low[u]=1001;
	for(int v=1;v<=n;v++)
		if (a[u][v]==1)
		{
			a[v][u]=0;
			if (T[v]==0)
			{
				T[v]=u;
				DFS(v);
				low[u]=min(low[u],low[v]);
			}
			else low[u]=min(low[u],num[v]);
		}
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u, v;
		cin>>u>>v;
		a[u][v]=a[v][u]=1;
	}
	for(int i=1;i<=n;i++)
		if (T[i]==0)
		{
			T[i]=-1;
			DFS(i);
		}
	cout<<"Cau: \n";
	for(int i=1;i<=n;i++)
		if (T[i]!=-1 && low[i]>=num[i])	cout<<T[i]<<' '<<i<<'\n';
	cout<<"Khop:\n";
	for(int i=1;i<=n;i++)
		if (T[i]!=-1)	C[T[i]]++;
	for(int i=1;i<=n;i++)
		if (T[i]==-1 && C[i]>=2)	flag[i]=1;
	for(int i=1;i<=n;i++)
		if (T[i]!=-1 && T[T[i]]!=-1 && low[i]>=num[T[i]])	flag[T[i]]=1;
	for(int i=1;i<=n;i++)
		if (flag[i]==1)	cout<<i<<' ';
	return 0;
}
