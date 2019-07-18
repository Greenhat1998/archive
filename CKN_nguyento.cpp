#include <iostream>
using namespace std;
const int mod=1e9+7;
int n, k, a[1000002], p[1000002];
long long ans=1;
void phantich(int x, int sign)
{
	while (x>1)
	{
		p[a[x]]+=sign;
		x=x/a[x];
	}
}
long long power(long long x, long long n)
{
	long long res=1;
	while (n>0)
	{
		if (n%2==1)	res=(res*x)%mod;         
		x=(x*x)%mod;
		n=n/2;
	}
	return res;
}
int main()
{
	cin>>n>>k;
	a[1]=1;
	for(int i=2;i<=n;i++)
		for(int j=i;j<=n;j+=i)
			if (a[j]==0)	a[j]=i;
	for(int i=k+1;i<=n;i++)		phantich(i,1);
	for(int i=2;i<=n-k;i++)		phantich(i,-1);
	for(int i=2;i<=n;i++)
		if (p[i]>0)		ans=ans*power(i,p[i]);
	cout<<ans;
	return 0;
}
