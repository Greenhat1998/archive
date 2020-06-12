#include <bits/stdc++.h>
using namespace std;
struct canh{
	int x, y;
};
int a[1000][1000];		// a[][] ma tran ke
canh e[1000];			// e[] danh sach canh
vector<int> b[1000];	// vector v[] danh sach ke
int n, m;
void mtk_dsc(int a[][], canh e[])	// chuyen ma tran ke thanh danh sach canh
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
void dsc_mtk(canh e[], int a[][])	// chuyen danh sach canh thanh ma tran ke
{
	for(int i=1;i<=m;i++)	
	{
		int u=e[i].x, v=e[i].y;
		a[u][v]=a[v][u]=1;
	}
}
void mtk_dsk(int a[][], vector<int> b[])	// ma tran ke thanh danh sach ke
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)	
			if (a[i][j]==1)	b[i].push_back(j);
}
void dsk_mtk(vector<int> b[], int a[][])	// danh sach ke thanh ma tran ke
{
	for(int i=1;i<=n;i++)
		for(int j=0;j<b[i].size();j++)	a[i][b[i][j]]=1;
}
void dsc_dsk(canh e[], vector<int> b[])		// danh sach canh thanh danh sach ke
{
	for(int i=1;i<=m;i++)
	{
		int u=e[i].x, v=e[i].y;
		b[x].push_back(y);
		b[y].push_back(x);
	}
}
void dsk_dsc(vector<int> b, canh e[])		// danh sach ke thanh danh sach canh
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
	for(int i=1;i<=cnt/2;i++)	e[i]=tmp[i*2];
}
int main()
{
	cin>>n>>m;
	// nhap ma tran ke hoac danh sach canh
	// chuyen doi
	return 0;
}