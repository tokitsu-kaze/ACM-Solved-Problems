#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <map>
#define mem(a,b) memset(a,b,sizeof(a))
#define MAX 100000+10
#define PI acos(-1.0)
using namespace std;
typedef long long ll;
int main()
{
    ll t,n,ans,i;
    while(cin>>t)
    {
		while(t--)
		{
			cin>>n;
			ans=0;
			for(i=1;i<=sqrt(n);i++)
			{
				ans+=2*(n/i);
			}
			i--;
			cout<<ans-i*i-n<<endl; 
		}
	}
    return 0;
}