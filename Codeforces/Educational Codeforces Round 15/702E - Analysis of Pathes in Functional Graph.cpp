#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
int go[40][MAX],mn[40][MAX],v[MAX];
ll sum[40][MAX];
int main()
{
	int n,i,j,now,rmn;
	ll k,ans;
	scanf("%d%lld",&n,&k);
	for(i=0;i<n;i++) scanf("%d",&go[0][i]);
	for(i=0;i<n;i++)
	{
		scanf("%d",&v[i]);
		sum[0][i]=mn[0][i]=v[i];
	}
	for(i=1;i<40;i++)
	{
		for(j=0;j<n;j++)
		{
			go[i][j]=go[i-1][go[i-1][j]];
			sum[i][j]=sum[i-1][j]+sum[i-1][go[i-1][j]];
			mn[i][j]=min(mn[i-1][j],mn[i-1][go[i-1][j]]);
		}
	}
	for(i=0;i<n;i++)
	{
		ans=0;
		rmn=INF;
		now=i;
		for(j=40-1;~j;j--)
		{
			if((k>>j)&1)
			{
				ans+=sum[j][now];
				rmn=min(rmn,mn[j][now]);
				now=go[j][now];
			}
		}
		printf("%lld %d\n",ans,rmn);
	}
	return 0;
}
