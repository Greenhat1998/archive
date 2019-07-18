#include <iostream>
using namespace std;
const int mod=1e9+7;
long long F[5000][5000];
int n, k;
int main()
{
	cin>>n>>k;
	F[1][0]=1, F[1][1]=1;
	for(int i=2;i<=n;i++)
		for(int j=0;j<=i;j++)
			if (j==0 || j==i)	F[i][j]=1;
			else F[i][j]=(F[i-1][j-1]+F[i-1][j])%mod;
	cout<<F[n][k];
	return 0;
}
