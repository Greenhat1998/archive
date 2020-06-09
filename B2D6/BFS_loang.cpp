#include <iostream>
#include <set>
using namespace std;
int T[1000], a[1000][1000], m, n, s, f, t, d[1000];
set<int> S;
void BFS(int u)
{
	T[u]=u;
	S.insert(u);
	do{
		set<int> P;
		for(int i=1;i<=n;i++)
			if (S.find(i)!=S.end())
			{
				cout<<i<<' ';
				for(int j=1;j<=n;j++)
					if (T[j]==0 && a[i][j]==1)
					{
						T[j]=i;
						P.insert(j);
					}
			}	
		S=P;
	}while (S.size()!=0); 
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
