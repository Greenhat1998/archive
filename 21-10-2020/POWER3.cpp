#include <iostream>
#include <math.h>
using namespace std;
long long T, n;
int main() 
{
  cin>>T;
  while (T--) 
  {
    cin>>n;
    long long tmp=round(pow(n,1.0/3.0));
    if (tmp*tmp*tmp==n) cout<<"YES\n";
    else cout<<"NO\n";
  }
  return 0;
}
