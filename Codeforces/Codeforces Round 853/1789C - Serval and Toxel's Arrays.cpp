#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=4e5+10;
int a[MAX],cnt[MAX];
int main()
{
	int T,n,m,i,p,v;
	ll ans,sum;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<=n+m;i++) cnt[i]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			cnt[a[i]]+=m+1;
		}
		ans=sum=0;
		for(i=1;i<=m;i++)
		{
			scanf("%d%d",&p,&v);
			cnt[a[p]]-=m-i+1;
			sum+=cnt[a[p]];
			a[p]=v;
			sum-=cnt[a[p]];
			cnt[a[p]]+=m-i+1;
			ans+=sum+1LL*n*i;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
1 2 3
4 2 3
4 5 3
1 5 3
*/
