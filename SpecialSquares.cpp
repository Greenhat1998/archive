#include <iostream>
using namespace std;
const int mod=1e9+7;
struct matrix{
	long long a[3][3];
}X;
long long n, w, h;
matrix multi_matrix(matrix A, matrix B)
{
	matrix C;
	for(int i=1;i<=2;i++)
		for(int j=1;j<=2;j++)
		{
			C.a[i][j]=0;
			for(int k=1;k<=2;k++)	C.a[i][j]=(C.a[i][j]+A.a[i][k]*B.a[k][j])%mod;
		}
	return C;
}
matrix pow_matrix(matrix A, long long k)
{
	if (k==1)	return A;
	matrix C=pow_matrix(A,k/2);
	C=multi_matrix(C,C);
	if (k%2==1)	C=multi_matrix(C,A);
	return C;
}
int main()
{
	matrix A, C;
	cin>>n;
	A.a[1][1]=0,	A.a[1][2]=1,	A.a[2][1]=1,	A.a[2][2]=1;
	C=pow_matrix(A,n);
	h=C.a[2][2],	w=(C.a[2][2]+C.a[1][2])%mod;
	cout<<h*w%mod;
	return 0;
}
