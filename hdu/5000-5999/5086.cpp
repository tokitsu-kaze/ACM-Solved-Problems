////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-09-18 17:43:33
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5086
////Problem Title: 
////Run result: Accept
////Run time:655MS
////Run memory:5168KB
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
const long double eps=1e-8;
const int MAX=447000+10;
const ll mod=1e9+7;
ll a[MAX];
int main()
{
	ll t,n,i,ans;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
		}
		ans=0;
		for(i=1;i<=n;i++)
		{
			ans+=a[i]*i%mod*(n-i+1)%mod;
			ans%=mod;
		}
		printf("%lld\n",ans%mod);
	}
	return 0;
}