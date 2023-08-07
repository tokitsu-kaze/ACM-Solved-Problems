////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-09-15 17:18:22
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4990
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
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-8;
const int MAX=1e5+10;
const ll mod=1e9+7;
ll m;
ll pow2(ll a,ll b)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=res*a%m;
		a=a*a%m;
		b>>=1;
	}
	return res;
}
ll exgcd(ll a,ll b,ll &x,ll &y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return a;
	}
	ll g,t;
	g=exgcd(b,a%b,x,y);
	t=x;
	x=y;
	y=t-a/b*y;
	return g;
}
int main()
{
	ll n;
	while(~scanf("%lld%lld",&n,&m))
	{
		m*=3;
		if(n&1) printf("%lld\n",(pow2(2,n+1)-1+m)/3%(m/3));
		else printf("%lld\n",(pow2(2,n+1)-2+m)/3%(m/3));
	}
	return 0;
}