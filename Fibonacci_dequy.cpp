#include <iostream>
using namespace std;
const int mod=1e9+7;
struct matrix{
	long long a[4][4];
}A;
long long n;
matrix nhan(matrix M, matrix N)
{
	matrix P;
	for(int i=1;i<=2;i++)
		for(int j=1;j<=2;j++)
		{
			P.a[i][j]=0;
			for(int k=1;k<=2;k++)	P.a[i][j]=(P.a[i][j]+M.a[i][k]*N.a[k][j])%mod;
		}
	return P;
}
matrix power(matrix X, long long k)
{
	if (k==1)	return X;
	matrix C=power(X,k/2);
	C=nhan(C,C);
	if (k%2==1)	C=nhan(C,X);
	return C;
}
int main()
{
	cin>>n;
	if (n<3)	
	{
		cout<<1;
		return 0;
	}
	matrix A;
	A.a[1][1]=0,	A.a[1][2]=1,	A.a[2][1]=1,	A.a[2][2]=1;
	matrix B=power(A,n-2);
	cout<<(B.a[1][2]+B.a[2][2])%mod;
	return 0;
}
