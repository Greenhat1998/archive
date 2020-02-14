#include <iostream>
using namespace std;
const int INF=1e9;
int n, h, a[1002], b[1002], F[10002];
int main() 
{
    cin>>h>>n;
    for(int i=0;i<n;i++)	cin>>a[i]>>b[i];
    for(int i=0;i<=h;i++)	F[i]=INF;
    for(int i=0;i<=h;i++)
    	for(int j=0;j<n;j++)
        	if (a[j]>=i)	F[i]=min(F[i],b[j]);
        	else F[i]=min(F[i],F[i-a[j]]+b[j]);
    cout<<F[h];
    return 0;
}
