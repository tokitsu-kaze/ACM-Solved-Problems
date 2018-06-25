////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-09-15 15:24:12
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6082
////Problem Title: 
////Run result: Accept
////Run time:374MS
////Run memory:2596KB
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
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-8;
const int MAX=1e5+10;
const ll mod=1e9+7;
int a[MAX],b[MAX],q[1010],p[1010];
ll dp[1010][15];
int main()
{
	int n,m,i,j,k,flag;
	ll ans;
	while(~scanf("%d%d",&n,&m))
	{
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&a[i],&b[i]);
		}
		for(i=1;i<=m;i++)
		{
			scanf("%d%d",&q[i],&p[i]);
		}
		mem(dp,0);
		for(i=1;i<=1000;i++)
		{
			for(j=0;j<=10;j++)
			{
				dp[i][j]=LLINF;
				for(k=1;k<=m;k++)
				{
					if(p[k]-j>=0)
					{
						if(p[k]-j>=i) dp[i][j]=min(dp[i][j],(ll)q[k]);
						else dp[i][j]=min(dp[i][j],(ll)dp[i-p[k]+j][j]+q[k]);
					}
				}
			}
		}
		ans=flag=0;
		for(i=1;i<=n;i++)
		{
			if(dp[a[i]][b[i]]==LLINF) flag=1;
			ans+=(ll)dp[a[i]][b[i]];
		}
		if(flag) puts("-1");
		else printf("%lld\n",ans);
	}
	return 0;
}