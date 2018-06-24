////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-08-17 20:28:26
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1787
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
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=3e4+10;
const ll mod=1e9+7;
ll Euler(ll n)
{
	ll ans,i;
	ans=n;
	for(i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			ans=ans-ans/i;
			while(n%i==0) n/=i;
		}
	}
	if(n>1) ans=ans-ans/n;
	return ans;
}
int main()
{
	ll n;
	while(~scanf("%lld",&n)&&n)
	{
		printf("%lld\n",n-Euler(n)-1);
	}
	return 0;
}