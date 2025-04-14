#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int a[MAX];
ll ans[MAX];
int main()
{
	int T,n,q,i;
	ll k;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&q);
		map<ll,ll> mp;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			mp[1LL*i*(n-i+1)-1]++;
		}
		for(i=2;i<=n;i++) mp[1LL*(i-1)*(n-i+1)]+=a[i]-a[i-1]-1;
		for(i=1;i<=q;i++)
		{
			scanf("%lld",&k);
			if(mp.count(k)) ans[i]=mp[k];
			else ans[i]=0;
		}
		for(i=1;i<=q;i++) printf("%lld%c",ans[i]," \n"[i==q]);
	}
	return 0;
}

