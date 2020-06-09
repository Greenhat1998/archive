#include <iostream>
#include <queue>
using namespace std;
int T[1000], a[1000][1000], m, n, s, f;
int main()
{	
	cin>>n>>m>>s>>f;
	for(int i=1;i<=m;i++)	
	{
		int x, y;
		cin>>x>>y;
		a[x][y]=a[y][x]=1;
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				a[i][j]=a[i][j] or a[i][k] and a[k][j];
	for(int i=1;i<=n;i++)
		if (T[i]==0)
		{
			for(int j=1;j<=n;j++)
				if (a[i][j]==1)	
				{
					cout<<j<<' ';
					T[j]=1;
				}
			cout<<'\n';
		}
	return 0;
}
