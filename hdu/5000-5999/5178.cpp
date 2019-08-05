////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-09-21 19:56:18
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5178
////Problem Title: 
////Run result: Accept
////Run time:312MS
////Run memory:2460KB
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
ll x[MAX];
int main()
{
	ll t,n,k,i,j,ans;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&k);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&x[i]);
		}
		sort(x+1,x+1+n);
		ans=0;
		for(i=1,j=1;i<=n;i++)
		{
			while(x[i]-x[j]>k&&j<i) j++;
			ans+=i-j;
		}
		printf("%lld\n",ans);
	}
	return 0;
}