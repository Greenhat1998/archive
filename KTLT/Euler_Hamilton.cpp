#include <iostream>
using namespace std;
int n, m, a[1000][1000], deg[1000];
int euler()
{
	for(int i=1;i<=n;i++)
		if (deg[i]%2==1)	return 0;
	return 1;
}
int hamilton()
{
	if (n==1)	return 1;
	if (n==2)	return 0;
	for(int i=1;i<=n;i++)
		if (deg[i]*2<n)	return 0;	//DL Dirak - 1952
	return 1;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u, v;
		cin>>u>>v;
		a[u][v]=a[v][u]=1;
		deg[u]++; deg[v]++;
	}
	if (euler())	cout<<"Do thi Euler\n";
	else cout<<"Do thi phi Euler\n";
	if (hamilton())	cout<<"Do thi Hamilton\n";
	else cout<<"Do thi phi Hamilton\n";
	return 0;
}
