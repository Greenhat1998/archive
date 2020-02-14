#include <iostream>
using namespace std;
long long solve(long long x)
{
	if (x==1)	return 1;
	else return 1+2*solve(x/2);
}
int main() 
{
	long long x;
	cin>>x;
	cout<<solve(x);
	return 0;
}
