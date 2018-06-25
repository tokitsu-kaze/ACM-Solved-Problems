////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-08-31 17:18:50
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6182
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1676KB
//////////////////System Comment End//////////////////
#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double db;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-4;
const int MAX=1e5+10;
const ll mod=1e9+7;
ll a[16];
ll pow2(ll a,ll b)
{
	ll res=1;
	while(b)
	{
		if(b&1) res*=a;
		a*=a;
		b>>=1;
	}
	return res;
}
void init()
{
	ll i;
	for(i=1;i<=15;i++)
	{
		ll temp=pow2(i,i);
		a[i]=temp;
	}
}
int main()
{
	ll n,ans,i;
	init();
	while(~scanf("%lld",&n))
	{
		ans=0;
		for(i=1;i<=15;i++)
		{
			if(a[i]<=n) ans++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}