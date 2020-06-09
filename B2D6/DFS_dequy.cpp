#include <iostream>
using namespace std;
int T[1000], a[1000][1000], m, n, s, f, t, d[1000];
void DFS(int u)
{
	cout<<u<<' ';
	for(int i=1;i<=n;i++)
		if (T[i]==0 && a[u][i]==1)
		{
			T[i]=u;
			DFS(i);
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
	T[s]=s;
	DFS(s);
	cout<<'\n';
	while (f!=s)
	{
		d[t]=f;
		t++;
		f=T[f];
	}
	cout<<s<<' ';
	for(int i=t-1;i>=0;i--) cout<<d[i]<<' ';
	return 0;
}
