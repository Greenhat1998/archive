#include <bits/stdc++.h>
using namespace std; 
int n, cnt, res[100001], col[100001];
vector<pair<int,int>> a[100001];
void dfs(int u, int p, int front)
{
	int now=0;
	for(int i=0;i<a[u].size();i++)
	{
		int v=a[u][i].first, id=a[u][i].second;
		if (v!=p)
		{
			now++;
			if (now==front) now++;
			dfs(v,u,now);
			col[id]=now;
		}
	}
	cnt=max(cnt,now);
}
int main()
{      
	cin>>n;
	for(int i=1;i<=n-1;i++)
	{
		int u, v;
		cin>>u>>v;
		a[u].push_back({v,i});
		a[v].push_back({u,i});
	}
	dfs(1,-1,-1);          
	cout<<cnt<<'\n';
	for(int i=1;i<=n-1;i++)	cout<<col[i]<<'\n';
	return 0;
}
