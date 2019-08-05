////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-08-05 18:20:22
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4823
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
const int MAX=1e5+10;
const ll mod=1e9+7;
int main()
{
	ll t,n,m,v,k,ans,pre;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld%lld",&n,&m,&v,&k);
		ans=0;
		while(m<n)
		{
			pre=m;
			m=(m-v)*k;
			if(pre>=m)
			{
				ans=-1;
				break;
			}
			ans++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}