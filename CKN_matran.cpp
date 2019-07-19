#include <iostream>
using namespace std;
const int mod=1e9+7;
long long C[5000][5000];
int n, k;
int main()
{
	cin>>n>>k;
	C[1][0]=1, C[1][1]=1;
	for(int i=2;i<=n;i++)
		for(int j=0;j<=i;j++)
			if (j==0 || j==i)	C[i][j]=1;
			else C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	cout<<C[n][k];
	return 0;
}
