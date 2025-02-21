#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e6+10;
int cnt[MAX];
ll a[MAX];
int main()
{
	int T,n,i,j;
	ll ans,now;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=4*n;i++) cnt[i]=0;
		map<ll,int> mp;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			if(a[i]<=4*n) cnt[a[i]]++;
			else mp[a[i]]++;
		}
		ans=n+1;
		for(auto &it:mp) ans=max(ans,it.first+it.second);
		for(i=2;i<=4*n;i++)
		{
			now=0;
			for(j=i;j<=4*n;j+=i) now+=cnt[j];
			if(now) ans=max(ans,now+i);
		}
		printf("%lld\n",ans);
	}
	return 0;
}

