#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[3][MAX],premx[MAX],premn[MAX],sufmx[MAX],sufmn[MAX];
int cnt[2*MAX];
int main()
{
	int T,n,i,l,r;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[1][i]);
		for(i=1;i<=n;i++) scanf("%d",&a[2][i]);
		premn[0]=INF;
		premx[0]=-INF;
		for(i=1;i<=n;i++)
		{
			premn[i]=min(premn[i-1],a[1][i]);
			premx[i]=max(premx[i-1],a[1][i]);
		}
		sufmn[n+1]=INF;
		sufmx[n+1]=-INF;
		for(i=n;i;i--)
		{
			sufmn[i]=min(sufmn[i+1],a[2][i]);
			sufmx[i]=max(sufmx[i+1],a[2][i]);
		}
		for(i=1;i<=2*n;i++) cnt[i]=0;
		for(i=1;i<=n;i++)
		{
			l=min(premn[i],sufmn[i]);
			r=max(premx[i],sufmx[i]);
			cnt[l]=max(cnt[l],2*n-r+1);
		}
		cnt[2*n+1]=0;
		ans=0;
		for(i=2*n;i;i--)
		{
			cnt[i]=max(cnt[i+1],cnt[i]);
			ans+=cnt[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
1 2   3 4 5 6 7 8
1 2 3       6 7 8
1 2 3 4   5 6 7 8
*/
