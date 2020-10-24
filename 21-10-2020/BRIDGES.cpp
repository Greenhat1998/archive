#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, f[100005];
pair<int,int> s[100005];
bool cmp(const pair<int,int> &x, const pair<int,int> &y)
{
	if (x.second==y.second) return x.first<y.first;
	return x.second<y.second;
}
void update(int p)
{
    for(int i=p;i<=n;i+= i&-i)	f[i]++;
}
int get(int p) 
{
    int ans=0;
    for(int i=p;i>0;i-= i&-i)	ans+=f[i];
    return ans;
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)	cin>>s[i].first>>s[i].second;
    sort(s,s+n,cmp);
    vector<int> p;
    for(int i=0;i<n;i++)	p.push_back(s[i].first);
    sort(p.begin(),p.end());
    p.erase(unique(p.begin(),p.end()),p.end());
    long long res=0;
    for(int i=n-1;i>=0;i--) 
	{
        int pos=lower_bound(p.begin(),p.end(),s[i].first)-p.begin()+1;
        res=res+get(pos);
        update(pos+1);
    }
    cout<<res;
    return 0;
}
