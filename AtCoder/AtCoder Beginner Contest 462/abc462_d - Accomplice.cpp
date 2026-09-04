#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
int cnt[MAX];
int main()
{
	int n,d,i,l,r;
	ll ans;
	scanf("%d%d",&n,&d);
	memset(cnt,0,sizeof cnt);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&l,&r);
		r-=d;
		if(l<=r)
		{
			cnt[l]++;
			cnt[r+1]--;
		}
	}
	ans=0;
	for(i=1;i<MAX;i++)
	{
		cnt[i]+=cnt[i-1];
		if(cnt[i]<=1) continue;
		ans+=1LL*cnt[i]*(cnt[i]-1)/2;
	}
	printf("%lld\n",ans);
	return 0;
}
