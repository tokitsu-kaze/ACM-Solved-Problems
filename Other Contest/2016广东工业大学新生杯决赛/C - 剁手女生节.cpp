#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>
#include <map>
#include <iomanip>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;
int main()
{
    ll t,n,a,b,c;
    while(cin>>t)
    {
        while(t--)
        {
            cin>>n>>a>>b>>c;
            n%=4;
            if(n==0)
            {
				puts("0");
			}
			else if(n==1)
			{
				cout<<min(min(3*a,a+b),min(a+b,c))<<endl;
			}
			else if(n==2)
			{
				cout<<min(min(2*a,b),min(b,2*c))<<endl;
			}
			else if(n==3)
			{
				cout<<min(min(a,b+c),min(b+c,3*c))<<endl;
			}
        }
    }
    return 0;
}