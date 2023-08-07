////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-09-28 19:53:30
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4737
////Problem Title: 
////Run result: Accept
////Run time:452MS
////Run memory:2452KB
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
const ll mod=2008;
ll a[MAX];
int main()
{
	ll t,cas=1,n,m,i,j,now,ans;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&m);	
		ans=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			if(a[i]<m) ans++;
		}
		for(i=1;i<=n;i++)
		{
			now=a[i];
			for(j=i+1;j<=n;j++)
			{
				now|=a[j];
				if(now>=m) break;
				ans++;
			}
		}
		printf("Case #%lld: %lld\n",cas++,ans);
	}
	return 0;
}