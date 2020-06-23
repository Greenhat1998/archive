// Tim cay khung nho nhat
#include <iostream>
#include <algorithm>
using namespace std;
struct edge{
	int u, v, w;
};
edge a[1000000];
int n, m, res, T[1000000];
int cmp(edge &X, edge &Y)
{
	return X.w<=Y.w;
}
int root(int p) 
{
    	if (T[p]==p)	return p;
    	else return T[p]=root(T[p]);
}
void join(int p, int q)
{ 
	T[root(p)]=root(q);
}
int main() 
{
    	cin>>n>>m;
    	for(int i=1;i<=n;i++)	T[i]=i;
    	for(int i=1;i<=m;i++)	cin>>a[i].u>>a[i].v>>a[i].w;
    	sort(a+1,a+m+1,cmp);
    	for(int i=1;i<=m;i++) 
        	if (root(a[i].u) != root(a[i].v)) 
		{
            		join(a[i].u,a[i].v);
            		cout<<a[i].u<<' '<<a[i].v<<'\n';
            		res=res+a[i].w;
        	}
    	if (res==0)	cout<<"Khong ton tai cay khung!";
    	else cout<<"Trong so cua cay khung nho nhat: "<<res;
    	return 0;
}
