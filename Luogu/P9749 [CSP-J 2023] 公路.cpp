#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
int v[MAX],a[MAX];
int main()
{
	int n,i,j,mn,d,now,tmp;
	ll ans;
	scanf("%d%d",&n,&d);
	for(i=1;i<n;i++) scanf("%d",&v[i]);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	now=0;
	mn=INF;
	ans=0;
	for(i=1;i<n;i++)
	{
		now+=v[i];
		mn=min(mn,a[i]);
		if(now>0)
		{
			tmp=(now+d-1)/d;
			ans+=1ll*tmp*mn;
			now-=tmp*d;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
