#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=500*500+10;
char mp[505][505];
int sum[505],cnt[MAX];
int main()
{
	int n,m,k,l,r,i,bit;
	ll ans;
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=n;i++) scanf("%s",mp[i]+1);
	memset(cnt,0,sizeof cnt);
	ans=0;
	for(l=1;l<=n;l++)
	{
		memset(sum,0,sizeof sum);
		for(r=l;r<=n;r++)
		{
			bit=0;
			cnt[bit]++;
			for(i=1;i<=m;i++)
			{
				sum[i]+=mp[r][i]-'0';
				bit+=sum[i];
				if(bit-k>=0) ans+=cnt[bit-k];
				cnt[bit]++;
			}
			bit=0;
			cnt[bit]=0;
			for(i=1;i<=m;i++)
			{
				bit+=sum[i];
				cnt[bit]=0;
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}
