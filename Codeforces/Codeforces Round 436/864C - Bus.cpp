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
const int MAX=2e5+10;
const ll mod=1e9+7;
int main()
{
	ll a,b,f,k,ans,now,i;
	while(~scanf("%lld%lld%lld%lld",&a,&b,&f,&k))
	{
		ans=0;
		if(b<f)
		{
			puts("-1");
			continue;
		}
		now=b-f;
		for(i=1;i<=k-1&&ans!=-1;i++)
		{
			if(i%2)
			{
				if(now>=(a-f)*2);
				else
				{
					if(b<(a-f)*2)
					{
						puts("-1");
						return 0;
					}
					ans++;
					now=b;
				}
				now-=(a-f)*2;
			}
			else
			{
				if(now>=f*2);
				else
				{
					if(b<f*2)
					{
						puts("-1");
						return 0;
					}
					ans++;
					now=b;
				}
				now-=f*2;
			}
		}
		if(k%2)
		{
			if(now>=(a-f)) now-=(a-f);
			else
			{
				if(b<(a-f))
				{
					puts("-1");
					return 0;
				}
				ans++;
				now=b;
			}
		}
		else
		{
			if(now>=f) now-=f;
			else
			{
				if(b<f)
				{
					puts("-1");
					return 0;
				}
				ans++;
				now=b;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}