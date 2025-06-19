#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=6e5+10;
const int delta=3e5;
int cnt[MAX],now[MAX],sum[MAX];
vector<int> mp[MAX];
int main()
{
	int T,n,m,i,j,k,l,r;
	ll ans;
	char c;
	memset(cnt,0,sizeof cnt);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		if(n>m)
		{
			for(i=1;i<=m;i++) mp[i]=vector<int>(n+1,0);
			for(j=1;j<=n;j++)
			{
				for(i=1;i<=m;i++)
				{
					scanf(" %c",&c);
					if(c=='.') mp[i][j]=1;
					else mp[i][j]=-1;
				}
			}
			swap(n,m);
		}
		else
		{
			for(i=1;i<=n;i++)
			{
				mp[i]=vector<int>(m+1,0);
				for(j=1;j<=m;j++)
				{
					scanf(" %c",&c);
					if(c=='.') mp[i][j]=1;
					else mp[i][j]=-1;
				}
			}
		}
		ans=0;
		for(l=1;l<=n;l++)
		{
			for(i=0;i<=m;i++) now[i]=0;
			for(r=l;r<=n;r++)
			{
				sum[0]=0;
				cnt[sum[0]+delta]++;
				for(i=1;i<=m;i++)
				{
					now[i]+=mp[r][i];
					sum[i]=sum[i-1]+now[i];
					ans+=cnt[sum[i]+delta];
					cnt[sum[i]+delta]++;
				}
				for(i=0;i<=m;i++) cnt[sum[i]+delta]=0;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
