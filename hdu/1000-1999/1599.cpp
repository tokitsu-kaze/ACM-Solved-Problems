////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-08-07 21:30:26
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1599
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:1784KB
//////////////////System Comment End//////////////////
#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
int mp[111][111],dis[111][111],ans,n;
void floyd()
{
	int i,j,k;
	for(k=1;k<=n;k++)
	{
		for(i=1;i<k;i++)
		{
			if(mp[k][i]==INF) continue;
			for(j=i+1;j<k;j++)
			{
				if(mp[k][j]==INF) continue;
				ans=min(ans,mp[k][i]+mp[k][j]+dis[i][j]);
			}
		}
		for(i=1;i<=n;i++)
		{
			if(dis[i][k]==INF) continue;
			for(j=1;j<=n;j++)
			{
				if(dis[k][j]==INF) continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
}
int main()
{
	int m,i,a,b,w;
	while(~scanf("%d%d",&n,&m))
	{
		mem(mp,0x3f);
		mem(dis,0x3f);
		ans=INF;
		while(m--)
		{
			scanf("%d%d%d",&a,&b,&w);
			mp[a][b]=mp[b][a]=dis[a][b]=dis[b][a]=min(mp[a][b],w);
		}
		floyd();
		if(ans==INF) puts("It's impossible.");
		else printf("%d\n",ans);
	}
	return 0;	
}