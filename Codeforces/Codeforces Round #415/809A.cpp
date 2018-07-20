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
#define MP make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=3e5+10;
const ll mod=1e9+7;
ll pow2(ll a,ll b)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
ll a[MAX];
int main()
{
	ll n,i,ans;
	while(~scanf("%lld",&n))
	{
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
		}
		sort(a+1,a+n+1);
		ans=0;
		for(i=n;i>1;i--)
		{
			ans+=(pow2(2,i-1)-1)*a[i];
			ans%=mod;
		}
		for(i=1;i<n;i++)
		{
			ans-=(pow2(2,n-i)-1)*a[i];
			ans%=mod;
		}
		printf("%lld\n",(ans+mod)%mod);
	}
	return 0;
}