#include <iostream>
#include <algorithm>
#define Nmax 1000000
using namespace std;
pair <int,int> a[Nmax];
int n, tmp=0, c=1, ans=0;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x, y;
        cin>>x>>y;
        a[2*i-1]={x,0};
        a[2*i]={y,1};
    }
    sort(a+1,a+1+2*n);
    for(int i=1;i<=2*n;i++)
    {
        if (a[i].second==0) tmp++;
        else tmp--;
        if (tmp==0) 
        {
            ans=ans+(a[i].first-a[c].first+1);
            c=i+1;
        }
    }
    cout<<ans;
    return 0;
}
