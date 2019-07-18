#include <iostream> 
using namespace std;
long long a, mod, x, y, g;
long long gcd_ex(long long a, long long b, long long &x,long long &y)
{     
	if (a==0)
	{
		x=0; 
		y=1;
		return b;
	}
	long long x1, y1;     
	long long d = gcd_ex(b%a,a,x1,y1);
	x=y1-(b/a)*x1;     
	y=x1;     
	return d; 
}  
int main() 
{     
	cin>>a>>mod;     
	g=gcd_ex(a,mod,x,y);     
	if(g!=1)	cout<<"No solution";       
	else       
	{           
		x=(x%mod+mod)%mod;           
		cout<<x;       
	} 
	return 0;
} 
