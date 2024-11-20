#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
int cnt[MAX][2];
int main()
{
	int T,n,i,x,y;
	ll ans,sum[2];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=0;i<=n+1;i++) cnt[i][0]=cnt[i][1]=0;
		sum[0]=sum[1]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&x,&y);
			cnt[x][y]++;
			sum[y]++;
		}
		ans=0;
		for(i=0;i<=n;i++)
		{
			if(i-1>=0)
			{
				if(cnt[i][0] && cnt[i-1][1] && cnt[i+1][1]) ans++;
				if(cnt[i][1] && cnt[i-1][0] && cnt[i+1][0]) ans++;
			}
			if(cnt[i][0]&&cnt[i][1]) ans+=sum[0]-1+sum[1]-1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
