#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
ll a[MAX],b[MAX],suma[MAX];
int main()
{
	int n,m,i,ans;
	ll k,x,y,tot,cntb,sumb;
	scanf("%d%d%lld",&n,&m,&k);
	scanf("%lld%lld",&x,&y);
	for(i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(i=1;i<=m;i++) scanf("%lld",&b[i]);
	sort(a+1,a+1+n);
	suma[0]=0;
	for(i=1;i<=n;i++) suma[i]=suma[i-1]+a[i];
	sort(b+1,b+1+m);
	ans=0;
	tot=x+y*k;
	for(i=n;i;i--)
	{
		if(suma[i]<=tot)
		{
			ans=i;
			break;
		}
	}
	cntb=sumb=0;
	for(i=1;i<=m;i++)
	{
		cntb+=(b[i]+k-1)/k;
		sumb+=b[i];
		if(cntb>y) break;
		ans=max(ans,i+int(upper_bound(suma+1,suma+1+n,tot-sumb)-suma-1));
	}
	printf("%d\n",ans);
	return 0;
}
/*
每种只能买一个。
枚举买几个饮料，剩下的尽可能买甜点。
*/
