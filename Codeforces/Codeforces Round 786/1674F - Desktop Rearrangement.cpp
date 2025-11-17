#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
char mp[1010][1010];
int id[1010][1010],vis[MAX];
int main()
{
	int n,m,q,i,j,tot,r,ans,x,y;
	scanf("%d%d%d",&n,&m,&q);
	for(i=1;i<=n;i++) scanf("%s",mp[i]+1);
	tot=0;
	for(j=1;j<=m;j++)
	{
		for(i=1;i<=n;i++)
		{
			id[i][j]=++tot;
		}
	}
	for(i=1;i<=tot;i++) vis[i]=0;
	r=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(mp[i][j]=='*')
			{
				r++;
				vis[id[i][j]]=1;
			}
		}
	}
	ans=0;
	for(i=r+1;i<=tot;i++) ans+=vis[i];
	while(q--)
	{
		scanf("%d%d",&x,&y);
		if(vis[id[x][y]])
		{
			ans+=vis[r];
			r--;
			if(id[x][y]>r) ans--;
		}
		else
		{
			r++;
			ans-=vis[r];
			if(id[x][y]>r) ans++;
		}
		vis[id[x][y]]^=1;
		printf("%d\n",ans);
	}
	return 0;
}
