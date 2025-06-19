#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5000+10;
ll a[MAX];
int main()
{
	int T,n,i,s,ans;
	ll k;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%lld",&n,&k);
		for(i=1;i<=n;i++) scanf("%lld",&a[i]);
		for(s=0;s<61;s++)
		{
			for(i=1;i<=n;i++)
			{
				if((a[i]>>s)&1) continue;
				if(k>=(1LL<<s))
				{
					k-=(1LL<<s);
					a[i]|=(1LL<<s);
				}
			}
		}
		ans=0;
		for(i=1;i<=n;i++) ans+=__builtin_popcountll(a[i]);
		printf("%d\n",ans);
	}
	return 0;
}
