////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-08-13 17:58:41
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6114
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1672KB
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
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
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
ll inv(ll x)
{
	return pow2(x,mod-2);
}
int main()
{
	int t;
	ll n,m,ans,i,d;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%I64d%I64d",&n,&m);
		if(n>m) swap(n,m);
		ans=1;
		for(i=m;i>=m-n+1;i--)
		{
			ans=ans*i%mod;
		}
		d=1;
		for(i=1;i<=n;i++)
		{
			d=d*i%mod;
		}
		printf("%I64d\n",ans*inv(d)%mod);
	}
	return 0;
}