#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int mp[11][11],n,d[11],ans,cnt[11];
void dfs(int x,int now)
{
	int i,j,tmp,ret;
/*	printf("%d\n",x);
	for(i=1;i<=n;i++) printf("%d %d\n",i,d[i]);
	puts("****");*/
	if(x==n)
	{
		for(i=1;i<=n;i++)
		{
			if(d[i]!=2) return;
		}
		ans=min(ans,now);
		return;
	}
	if(d[x]>2) return;
	if(d[x]==2) dfs(x+1,now+cnt[x]);
	if(d[x]==0)
	{
		ret=cnt[x];
		tmp=0;
		for(i=x+1;i<=n;i++)
		{
			if(mp[x][i]) ret--;
			else tmp++;
			d[x]++;
			d[i]++;
			for(j=i+1;j<=n;j++)
			{
				if(mp[x][j]) ret--;
				else tmp++;
				d[x]++;
				d[j]++;
				dfs(x+1,now+tmp+ret);
				if(mp[x][j]) ret++;
				else tmp--;
				d[x]--;
				d[j]--;
			}
			if(mp[x][i]) ret++;
			else tmp--;
			d[x]--;
			d[i]--;
		}
	}
	else if(d[x]==1)
	{
		ret=cnt[x];
		tmp=0;
		for(i=x+1;i<=n;i++)
		{
			if(mp[x][i]) ret--;
			else tmp++;
			d[x]++;
			d[i]++;
			dfs(x+1,now+tmp+ret);
			if(mp[x][i]) ret++;
			else tmp--;
			d[x]--;
			d[i]--;
		}
	}
}
int main()
{
	int m,i,a,b;
	scanf("%d%d",&n,&m);
	memset(mp,0,sizeof mp);
	memset(d,0,sizeof d);
	memset(cnt,0,sizeof cnt);
	while(m--)
	{
		scanf("%d%d",&a,&b);
		mp[a][b]=mp[b][a]=1;
		if(a<b) cnt[a]++;
		else cnt[b]++;
	}
	ans=INF;
	dfs(1,0);
	printf("%d\n",ans);
	return 0;
}
