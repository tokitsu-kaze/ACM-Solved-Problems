#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#define mem(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-5;
const int MAX=150+10;
const ll mod=1e9+6;
struct node
{
	ll p,q;
}a[MAX];
int main()
{
	ll t,dp[MAX],cnt[MAX],i,j,n;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		mem(a,0);
		mem(dp,0);
		mem(cnt,0);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[i].p);
		}
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[i].q);
		}
		for(i=1;i<=n;i++)
		{
			ll temp=0,c=0;
			for(j=0;j<i;j++)
			{
				if(a[j].p<a[i].p)
				{
					if(c<cnt[j])
					{
						temp=dp[j];
						c=cnt[j];
					}
					else if(c==cnt[j]) temp=max(temp,dp[j]);
				}
			}
			dp[i]=temp+a[i].q;
			cnt[i]=c+1;
		}
		ll ans=-1e16,ansc=0;
		for(i=1;i<=n;i++)
		{
			if(ansc<cnt[i])
			{
				ansc=cnt[i];
				ans=dp[i];
			}
			else if(ansc==cnt[i]) ans=max(ans,dp[i]);
		}
		printf("%lld\n",ansc);
		printf("%lld\n",ans);
	}
	return 0;
}