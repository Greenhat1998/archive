#include <bits/stdc++.h>
using namespace std;
const string ruou[] = {"ABSINTH", "TEQUILA", "VODKA", "WHISKEY", "WINE", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE"};
int n, cnt;
int solve(string st) 
{
    int x=0;
    for(int i=0;i<st.length();i++)
        if ('0'<=st[i] && st[i]<='9') x=x*10+st[i]-'0';
        else return -1;
    return x;
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++) 
	{
        string st;
        cin>>st;
        int num=solve(st);
        if (num==-1) 
            for(int j=0;j<11;j++) 
			{
                if (st==ruou[j])	cnt++;
            }
        else if (num<18)	cnt++;
    }
    cout<<cnt;
    return 0;
}
