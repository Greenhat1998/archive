#include <iostream>
#include <queue>
using namespace std;
int T[1000], a[1000][1000], m, n, s, f, t, d[1000];
queue <int> Q;
void BFS(int u)
{
	T[u]=u;
	Q.push(u);
	while (Q.size())
	{
		int k=Q.front();
		cout<<k<<' ';
		Q.pop();
		for(int i=1;i<=n;i++)
			if (T[i]==0 && a[k][i]==1)
			{
				Q.push(i);
				T[i]=k;
			}
	}
}
int main()
{	
	cin>>n>>m>>s>>f;
	for(int i=1;i<=m;i++)	
	{
		int x, y;
		cin>>x>>y;
		a[x][y]=a[y][x]=1;
	}
	BFS(s);
	cout<<'\n';
	while (f!=s)
	{
		d[t]=f;
		t++;
		f=T[f];
	}
	cout<<s<<' ';
	for(int i=t-1;i>=0;i--)	cout<<d[i]<<' ';
	return 0;
}
