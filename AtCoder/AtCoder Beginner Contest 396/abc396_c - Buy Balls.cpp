#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
const int mod=998244353;
int a[MAX],b[MAX];
ll sum[MAX];
int main()
{
	int n,m,i,j;
	ll ans,now;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=m;i++) scanf("%d",&b[i]);
	sort(a+1,a+1+n);
	reverse(a+1,a+1+n);
	sort(b+1,b+1+m);
	reverse(b+1,b+1+m);
	sum[0]=0;
	for(i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	j=0;
	while(j+1<=n && a[j+1]>0) j++;
	ans=sum[j];
	now=0;
	for(i=1;i<=min(n,m);i++)
	{
		now+=b[i];
		ans=max(ans,sum[max(i,j)]+now);
	}
	printf("%lld\n",ans);
	return 0;
}
