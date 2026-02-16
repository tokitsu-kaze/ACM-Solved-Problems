#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int op[MAX],x[MAX],y[MAX],vis[MAX],a[MAX],b[MAX];
ll dis[305][305],ans[MAX],c[MAX];
int main()
{
	int n,m,q,i,j,k,id,xx,yy;
	scanf("%d%d%d",&n,&m,&q);
	for(i=1;i<=m;i++) scanf("%d%d%lld",&a[i],&b[i],&c[i]);
	for(i=1;i<=m;i++) vis[i]=1;
	for(i=1;i<=q;i++)
	{
		scanf("%d%d",&op[i],&x[i]);
		if(op[i]==2) scanf("%d",&y[i]);
		else vis[x[i]]=0;
	}
	memset(dis,0x3f,sizeof dis);
	for(i=1;i<=m;i++)
	{
		if(!vis[i]) continue;
		dis[a[i]][b[i]]=min(dis[a[i]][b[i]],c[i]);
		dis[b[i]][a[i]]=min(dis[b[i]][a[i]],c[i]);
	}
	for(i=1;i<=n;i++) dis[i][i]=0;
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(i=q;i;i--)
	{
		if(op[i]==1)
		{
			id=x[i];
			dis[a[id]][b[id]]=min(dis[a[id]][b[id]],c[id]);
			dis[b[id]][a[id]]=min(dis[b[id]][a[id]],c[id]);
			for(xx=1;xx<=n;xx++)
			{
				for(yy=1;yy<=n;yy++)
				{
					dis[xx][yy]=min(dis[xx][yy],dis[xx][a[id]]+dis[a[id]][b[id]]+dis[b[id]][yy]);
					dis[xx][yy]=min(dis[xx][yy],dis[xx][b[id]]+dis[b[id]][a[id]]+dis[a[id]][yy]);
				}
			}
		}
		else
		{
			if(dis[x[i]][y[i]]==LLINF) ans[i]=-1;
			else ans[i]=dis[x[i]][y[i]];
		}
	}
	for(i=1;i<=q;i++)
	{
		if(op[i]==2) printf("%lld\n",ans[i]);
	}
	return 0;
}
