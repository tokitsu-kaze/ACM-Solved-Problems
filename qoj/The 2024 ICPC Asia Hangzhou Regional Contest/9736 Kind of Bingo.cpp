#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int id[MAX],cnt[MAX];
int main()
{
	int T,n,m,k,i,j,x,tot,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&k);
		tot=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				tot++;
				id[tot]=i;
			}
			cnt[i]=0;
		}
		ans=n*m;
		for(i=1;i<=n*m;i++)
		{
			scanf("%d",&x);
			cnt[id[x]]++;
			if(cnt[id[x]]+k>=m) ans=min(ans,max(i,m));
		}
		printf("%d\n",ans);
	}
	return 0;
}
