#include <iostream>
using namespace std;
const int MAXN = 100005;
int n, m, T, a[MAXN], b[MAXN];
long long count(int a[], int n, int t) 
{
    long long res=0;
    for(int i=0;i<n;i++)	res+=t/a[i];
    return res;
}
int main() 
{
    cin>>T>>n;
    for(int i=0;i<n;i++)	cin>>a[i];
    cin>>m;
    for(int i=0;i<m;i++)	cin>>b[i];
    int l=0, r=T, tmp=-1;
    while (l<=r) 
	{
        int mid=(l+r)/2;
        long long A=count(a,n,mid),	B=count(b,m,T-mid);
        if (A<B)	tmp=mid,	l=mid+1;
        else	r=mid-1;
    }
    long long ans=min(count(a,n,tmp),count(b,m,T-tmp));
    if (tmp<=T)	ans=max(ans,min(count(a,n,tmp+1),count(b,m,T-tmp-1)));
    cout<<ans;
    return 0;
}
