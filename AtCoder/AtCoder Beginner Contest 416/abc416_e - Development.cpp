#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=500+10;
ll dis[MAX][MAX],dis2[MAX];
int tag[MAX],d[MAX];
int main()
{
	int n,m,i,j,k,a,b,tot,q,x,op;
	ll ans,t,c;
	scanf("%d%d",&n,&m);
	memset(dis,0x3f,sizeof dis);
	for(i=1;i<=n;i++) dis[i][i]=0;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%lld",&a,&b,&c);
		dis[a][b]=min(dis[a][b],c);
		dis[b][a]=min(dis[b][a],c);
	}
	scanf("%d%lld",&tot,&t);
	memset(tag,0,sizeof tag);
	for(i=1;i<=tot;i++)
	{
		scanf("%d",&d[i]);
		tag[d[i]]=1;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(tag[i] && tag[j])
			{
				dis[i][j]=min(dis[i][j],t);
				dis[j][i]=min(dis[j][i],t);
			}
		}
	}
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			if(dis[i][k]==LLINF) continue;
			for(j=1;j<=n;j++)
			{
				if(dis[k][j]==LLINF) continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	memset(dis2,0x3f,sizeof dis2);
	for(i=1;i<=tot;i++)
	{
		for(j=1;j<=n;j++)
		{
			dis2[j]=min(dis2[j],dis[j][d[i]]);
		}
	}
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d%d%lld",&a,&b,&c);
			dis[a][b]=min(dis[a][b],c);
			dis[b][a]=min(dis[b][a],c);
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=n;j++)
				{
					if(i==j) continue;
					dis[i][j]=min(dis[i][j],dis[i][a]+dis[a][b]+dis[b][j]);
					dis[i][j]=min(dis[i][j],dis[i][b]+dis[b][a]+dis[a][j]);
				}
			}
		}
		else if(op==2)
		{
			scanf("%d",&x);
			d[++tot]=x;
			tag[x]=1;
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=n;j++)
				{
					if(tag[i] && tag[j])
					{
						dis[i][j]=min(dis[i][j],t);
						dis[j][i]=min(dis[j][i],t);
					}
				}
			}
			for(i=1;i<=tot;i++)
			{
				for(j=1;j<=n;j++)
				{
					dis2[j]=min(dis2[j],dis[j][d[i]]);
				}
			}
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=n;j++)
				{
					if(i==j) continue;
					dis[i][j]=min(dis[i][j],dis2[i]+dis2[j]+t);
				}
			}
			for(i=1;i<=tot;i++)
			{
				for(j=1;j<=n;j++)
				{
					dis2[j]=min(dis2[j],dis[j][d[i]]);
				}
			}
		}
		else
		{
			ans=0;
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=n;j++)
				{
					if(dis[i][j]!=LLINF) ans+=dis[i][j];
				}
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
