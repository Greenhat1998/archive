#include <iostream>
#include <stack>
using namespace std;
stack <int> S;
int T[1000], a[1000][1000], m, n, s, f, t, d[1000];
string res="";
void DFS(int s)
{
	cout<<s<<' ';
	T[s]=s;
	S.push(s);
	do{
		int u=S.top();
		S.pop();
		for(int i=1;i<=n;i++)	
			if (T[i]==0 && a[u][i]==1)	
			{
				cout<<i<<' ';
				T[i]=u;
				S.push(u);
				S.push(i);
				break;
			}
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
	for(int i=t-1;i>=0;i--)	cout<<d[i]<<' ';
	return 0;
}
