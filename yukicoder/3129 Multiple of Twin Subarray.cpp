#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int n,a[MAX];
ll pre[MAX],suf[MAX];
ll work()
{
	int i;
	ll now,res;
	now=0;
	pre[0]=-4e18;
	for(i=1;i<=n;i++)
	{
		now+=a[i];
		pre[i]=max(pre[i-1],now);
		if(now<0) now=0;
	}
	now=0;
	suf[n+1]=-4e18;
	for(i=n;i;i--)
	{
		now+=a[i];
		suf[i]=max(suf[i+1],now);
		if(now<0) now=0;
	}
	res=-4e18;
	for(i=1;i<n;i++) res=max(res,pre[i]*suf[i+1]);
	return res;
}
int main()
{
	int i;
	ll ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	ans=work();
	for(i=1;i<=n;i++) a[i]=-a[i];
	ans=max(ans,work());
	printf("%lld\n",ans);
	return 0;
}
