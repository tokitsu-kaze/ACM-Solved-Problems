#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=200+10;
int dis[MAX][MAX],t[MAX];
int main()
{
	int n,m,q,i,j,a,b,c,p,now;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++) scanf("%d",&t[i]);
	memset(dis,0x3f,sizeof dis);
	while(m--)
	{
		scanf("%d%d%d",&a,&b,&c);
		dis[a][b]=dis[b][a]=c;
	}
	for(i=0;i<n;i++) dis[i][i]=0;
	scanf("%d",&q);
	p=0;
	while(q--)
	{
		scanf("%d%d%d",&a,&b,&now);
		while(p<n && t[p]<=now)
		{
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
					dis[i][j]=min(dis[i][j],dis[i][p]+dis[p][j]);
				}
			}
			p++;
		}
		if(t[a]>now || t[b]>now || dis[a][b]==INF) puts("-1");
		else printf("%d\n",dis[a][b]);
	}
	return 0;
}
