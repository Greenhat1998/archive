#include <bits/stdc++.h>
using namespace std;
struct canh{
	int x, y;
};
int a[1000][1000];		// a[][] ma tran ke
canh e[1000];			// e[] danh sach canh
vector<int> b[1000];	// vector v[] danh sach ke
int n, m;
void mtk_dsc(int a[1000][1000], canh e[1000])	// chuyen ma tran ke thanh danh sach canh
{
	m=0;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if (a[i][j]==1)	
			{
				m++;
				e[m].x=i, e[m].y=j;
			}
}
void dsc_mtk(canh e[1000], int a[1000][1000])	// chuyen danh sach canh thanh ma tran ke
{
	for(int i=1;i<=m;i++)	
	{
		int u=e[i].x, v=e[i].y;
		a[u][v]=a[v][u]=1;
	}
}
void mtk_dsk(int a[1000][1000], vector<int> b[1000])	// ma tran ke thanh danh sach ke
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)	
			if (a[i][j]==1)	b[i].push_back(j);
}
void dsk_mtk(vector<int> b[1000], int a[1000][1000])	// danh sach ke thanh ma tran ke
{
	for(int i=1;i<=n;i++)
		for(int j=0;j<b[i].size();j++)	a[i][b[i][j]]=1;
}
void dsc_dsk(canh e[1000], vector<int> b[1000])		// danh sach canh thanh danh sach ke
{
	for(int i=1;i<=m;i++)
	{
		int u=e[i].x, v=e[i].y;
		b[u].push_back(v);
		b[v].push_back(u);
	}
}
int cmp(canh &X, canh &Y)
{
	if (X.x<Y.x)	return 1;
	if (X.x==Y.x && X.y<Y.y)	return 1;
	return 0;
}
void dsk_dsc(vector<int> b[1000], canh e[1000])		// danh sach ke thanh danh sach canh
{
	canh tmp[1000];
	int cnt=0;
	for(int i=1;i<=n;i++)
		for(int j=0;j<b[i].size();j++)	
		{
			cnt++;
			tmp[cnt].x=min(i,b[i][j]);
			tmp[cnt].y=max(i,b[i][j]);
		}
	sort(tmp+1,tmp+cnt+1,cmp);
	for(int i=1;i<=cnt/2;i++)	e[i]=tmp[i*2];
}
int main()
{
	cin>>n>>m;
	// nhap ma tran ke hoac danh sach canh
	// chuyen doi
	return 0;
}
