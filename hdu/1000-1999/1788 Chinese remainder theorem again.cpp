////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-08-17 20:49:16
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1788
////Problem Title: 
////Run result: Accept
////Run time:15MS
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
const int MAX=3e4+10;
const ll mod=1e9+7;
int main()
{
	ll n,a,k,ans;
	while(~scanf("%lld%lld",&n,&k)&&n+k)
	{
		ans=1;
		while(n--)
		{
			scanf("%lld",&a);
			ans=ans*a/__gcd(ans,a);
		}
		printf("%lld\n",ans-k);
	}
	return 0;
}