#include <iostream>
using namespace std;
int n, x, a[1000];
int tk_tt(int x)	// ap dung cho day khong can sap xep
{
	for(int i=1;i<=n;i++)
		if (a[i]==x)	return i;
	return 0;
}
int tk_np(int x)	// ap dung cho day da sap xep tang dan
{
	int l=1, r=n;
	while (l<=r)
	{
		int mid=(l+r)/2;
		if (a[mid]==x)	return mid;
		else if (a[mid]<x)	l=mid+1;
		else r=mid-1;
	}
	return 0;
}
int main()
{
	cin>>n>>x;
	for(int i=1;i<=n;i++)	cin>>a[i];
	if (tk_tt(x)!=0 || tk_np(x)!=0)	cout<<"X ton tai trong day";
	else cout<<"X khong ton tai trong day";
	return 0;
}
