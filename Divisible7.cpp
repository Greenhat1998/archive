#include <iostream>
using namespace std;
string a[7]={"1869", "6198", "1896", "1689", "1986", "1968", "1698" };
int flag[11];
int main() 
{
	string s;
	cin>>s;
	int p=0, cnt=0;
	for(int i=0;i<s.length();i++)
		if ((s[i]=='1' || s[i]=='6' || s[i]=='8' || s[i]=='9') && flag[s[i]-'0']==0)	flag[s[i]-'0']=1;
		else if (s[i]=='0')	cnt++;
		else{
			cout<<s[i];
			p=(p*10+s[i]-'0')%7;
		}
	cout<<a[p];
	for(int i=0;i<cnt;i++)	cout<<0;
	return 0;
}
