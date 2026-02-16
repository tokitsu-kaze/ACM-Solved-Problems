#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int mp[2010][2010],sum[2010][2010];
int a[MAX],b[MAX],c[MAX],d[MAX];
int main()
{
	const int n=2000;
	int m,tot,ans,i,j;
	memset(mp,0,sizeof mp);
	scanf("%d",&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d%d",&a[i],&c[i],&b[i],&d[i]);
		mp[a[i]][b[i]]++;
		mp[a[i]][d[i]+1]--;
		mp[c[i]+1][b[i]]--;
		mp[c[i]+1][d[i]+1]++;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			mp[i][j]+=mp[i-1][j]
					 +mp[i][j-1]
					 -mp[i-1][j-1];
		}
	}
	memset(sum,0,sizeof sum);
	tot=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(mp[i][j]==0) tot++;
			else if(mp[i][j]==1) sum[i][j]=1;
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			sum[i][j]+=sum[i-1][j]
					  +sum[i][j-1]
					  -sum[i-1][j-1];
		}
	}
	for(i=1;i<=m;i++)
	{
		printf("%d\n",tot+sum[c[i]][d[i]]-
						sum[c[i]][b[i]-1]-
						sum[a[i]-1][d[i]]+
						sum[a[i]-1][b[i]-1]);
	}
	return 0;
}
