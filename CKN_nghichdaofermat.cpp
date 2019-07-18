#include <iostream>
using namespace std;
const int mod=1e9+7;
int n, k;
long long p[1000002];
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
	p[1]=1;
	for(int i=2;i<=n;i++)	p[i]=(p[i-1]*i)%mod;
	long long mau=power((p[k]*p[n-k])%mod,mod-2);
	cout<<(p[n]*mau)%mod;
	return 0;
}
