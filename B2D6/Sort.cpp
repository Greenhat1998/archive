#include <iostream>
using namespace std;
int n, a[1000];
void select_sort()
{
	for(int i=1;i<n;i++)
	{
		int vt=i;
		for(int j=i+1;j<=n;j++)
			if(a[j]<a[vt])	vt=j;
		if(vt!=i)
		{
			int tg=a[i];
			a[i]=a[vt];
			a[vt]=tg;
		}
	}
}
void insert_sort()
{
	for(int i=2;i<=n;i++)
	{
		int tg=a[i], vt=i-1;
		while(vt>0 && a[vt]>tg)
		{
			a[vt+1]=a[vt];
			vt--;
		}
		a[vt+1]=tg;
	}
}
void bubble_sort()
{
	for(int i=1;i<n;i++)
		for(int j=n;j>i;j--)
			if(a[j]<a[j-1])
			{
				int tg=a[j];
				a[j]=a[j-1];
				a[j-1]=tg;
			}
}
void quick_sort(int l, int r)
{
	int i=l, j=r, mid=a[(l+r)/2];
	do{
		while (a[i]<mid)	i++;
		while (a[j]>mid)	j--;
		if (i<=j)
		{
			int tmp=a[i];
			a[i]=a[j];
			a[j]=tmp;
			i++;
			j--;
		}
	}while (i<=j);
	if (l<j)	quick_sort(l,j);
	if (i<r)	quick_sort(i,r);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)	cin>>a[i];
//	select();
//	insert();
//	bubble();
	quick_sort(1,n);
	for(int i=1;i<=n;i++)	cout<<a[i]<<' ';
	return 0;
}
