////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-08-04 16:17:24
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5690
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1684KB
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
ll pow2(ll a,ll b,ll mod)
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
int main()
{
	ll t,cas=1,x,m,k,c;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld%lld",&x,&m,&k,&c);
		printf("Case #%lld:\n",cas++);
		if((pow2(10,m,9*k)-1+9*k)/9*x%k==c) puts("Yes");
		else puts("No");
	}
	return 0;
}