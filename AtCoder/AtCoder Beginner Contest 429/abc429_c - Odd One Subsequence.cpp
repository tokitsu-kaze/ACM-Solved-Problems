#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int cnt[MAX];
int main()
{
	int n,i,x;
	ll ans,cnt1,cnt2;
	scanf("%d",&n);
	for(i=1;i<=n;i++) cnt[i]=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		cnt[x]++;
	}
	ans=1LL*n*(n-1)*(n-2)/6;
	cnt1=cnt2=0;
	for(i=1;i<=n;i++)
	{
		if(cnt[i]>=3) ans-=1LL*cnt[i]*(cnt[i]-1)*(cnt[i]-2)/6;
		ans-=cnt2*cnt[i];
		cnt2+=cnt1*cnt[i];
		cnt1+=cnt[i];
	}
	printf("%lld\n",ans);
	return 0;
}

