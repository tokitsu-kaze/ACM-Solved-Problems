////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2018-02-10 22:29:12
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1211
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1680KB
//////////////////System Comment End//////////////////
#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
using namespace std;
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
typedef long long ll;
typedef unsigned long long ull;
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<double,double>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-4;
const int MAX=6e4+10;
const ll mod=1e9+7;
ll fn;
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
ll inv(ll a)
{
	ll g,x,y;
	g=exgcd(a,fn,x,y);
	return g==1?(x+fn)%fn:-1;
}
ll pow2(ll a,ll b,ll m)
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
int main()
{
	ll p,q,e,l,n,c,d;
	while(~scanf("%lld%lld%lld%lld",&p,&q,&e,&l))
	{
		n=p*q;
		fn=(p-1)*(q-1);
		d=inv(e);
		while(l--)
		{
			scanf("%lld",&c);
			putchar((char)pow2(c,d,n));
		}
		puts("");
	}
	return 0;
}