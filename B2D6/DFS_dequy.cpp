#include <iostream>
using namespace std;
int T[1000], a[1000][1000], m, n, s, f;
string res="";
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
		res=to_string(f)+" "+res;
		f=T[f];
	}	
	cout<<s<<' '<<res;
	return 0;
}
