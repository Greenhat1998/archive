#include <iostream>
#define MAX 1000002
using namespace std;
int cnt[MAX], Prime[MAX], Q, T;
int main() 
{
    for(int i=1;i<MAX;i++)
		for(int j=i;j<MAX;j+=i)	cnt[j]++;
	  Prime[0]=1, Prime[1]=1;
    for(int i=1;i<MAX;i++)
		if (!Prime[i]) 
		{
        	for(int j=2*i;j<MAX;j+=i)	Prime[j]=1;
        	for(int j=i;j<MAX;j+=i)	cnt[j]--;
    	}
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>Q;
    while (Q--)
	{
        cin>>T;
        cout<<cnt[T]<<'\n';
    }
    return 0;
}
