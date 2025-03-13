#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
ll sqr(ll x){return x*x;}
int x[MAX],r[MAX];
int main()
{
	int T,n,m,i,j;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++) scanf("%d",&x[i]);
		for(i=1;i<=n;i++) scanf("%d",&r[i]);
		map<ll,ll> mp;
		for(i=1;i<=n;i++)
		{
			for(j=-r[i];j<=r[i];j++)
			{
				mp[j-x[i]]=max(mp[j-x[i]],(ll)sqrtl(sqr(r[i])-sqr(j)));
			}
		}
		ans=0;
		for(auto &it:mp) ans+=it.second*2+1;
		printf("%lld\n",ans);
	}
	return 0;
}
