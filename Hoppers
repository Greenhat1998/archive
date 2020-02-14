#include <iostream>
#include <queue>
#define MAX 1000100
using namespace std;
vector<int> a[MAX];
int n, m, Free[MAX], res;
void BFS(int s) 
{
    Free[s] = 0;
    queue<int> q; 
	q.push(s);
    while (!q.empty()) 
	{
        int u = q.front(); 
		q.pop();
        for(int k=0;k<a[u].size();k++)
			if (Free[a[u][k]] < 0) 
			{
				Free[a[u][k]] = Free[u] ^ 1;
            	q.push(a[u][k]);
        	}
    }
}
int main() 
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u, v;
		    cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for(int i=0;i<=n;i++)	Free[i]=-1;
    for(int i=1;i<=n;i++) 
		if (Free[i]<0) 
		{
        res++;
        BFS(i);
    }
    bool flag=true;
    for(int u=1;u<=n;u++)
		for(int i=0;i<a[u].size();i++)
			if (Free[u]==Free[a[u][i]]) flag=false;
	if (flag)	cout<<res<<'\n';
	else cout<<res-1<<'\n';
    return 0;
}
