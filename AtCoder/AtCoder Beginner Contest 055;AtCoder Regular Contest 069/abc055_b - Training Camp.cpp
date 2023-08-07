#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#define mem(a,b) memset((a),(b),sizeof(a))
using namespace std;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-12;
const int MAX=1000000+10;
const int EDGE=100000+10;//±ßµÄÌõÊý
typedef long long ll;
const int mod=1000000000+7;
ll mul2(ll a,ll b)
{
	ll ans=0;
	while(b)
	{
		if(b&1)
		{
			ans=(ans+a)%mod;
		}
		a=(a<<1)%mod;
		b>>=1;
	}
	return ans;
}
int main()
{
	ll n,s,i;
	while(~scanf("%lld",&n))
	{
		s=1;
		for(i=1;i<=n;i++)
		{
			s=mul2(s,i);
		}
		printf("%lld\n",s);
	}
	return 0;
}
