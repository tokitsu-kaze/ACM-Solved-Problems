#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e6+10;
int cnt[MAX],a[MAX],tmp[MAX];
int main()
{
	int n,m,i,x,now;
	ll ans;
	scanf("%d%d",&n,&m);
	for(i=0;i<=m;i++) cnt[i]=0;
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=n+1;i<=2*n;i++) a[i]=a[i-n];
	now=0;
	cnt[0]=1;
	tmp[0]=0;
	ans=0;
	for(i=1;i<2*n;i++)
	{
		if(i>=n) cnt[tmp[i-n]]--;
		now=(now+a[i])%m;
		ans+=cnt[now];
		if(i<n) cnt[now]++;
		tmp[i]=now;
//		printf("%d %lld\n",i,ans);
	}
	printf("%lld\n",ans);
	return 0;
}

