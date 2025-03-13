#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
const int mod=998244353;
int a[MAX];
ll sum[MAX],res[MAX];
int main()
{
	int n,k,i;
	ll ans,now;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	sum[n+1]=0;
	for(i=n;i;i--) sum[i]=sum[i+1]+a[i];
	ans=-4e18;
	now=0;
	priority_queue<ll> q;
	for(i=2;i<=n;i++)
	{
		now+=sum[i];
		q.push(-sum[i]);
		if(q.size()>k-1)
		{
			now-=(-q.top());
			q.pop();
		}
		if(q.size()==k-1)
		{
			ans=max(ans,sum[1]+now-k*sum[i+1]);
		}
	}
	printf("%lld\n",ans);
	return 0;
}
