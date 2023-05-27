////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-08-07 16:43:28
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1559
////Problem Title: 
////Run result: Accept
////Run time:390MS
////Run memory:9652KB
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
int mp[1010][1010];
int a[1010][1010];
int main()
{
	int t,n,m,i,j,ans,x,y,k1,k2;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d",&n,&m,&k1,&k2);
		mem(a,0);
		mem(mp,0);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				scanf("%d",&mp[i][j]);
				a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+mp[i][j];
			}
		}
		ans=0;
		for(i=k1;i<=n;i++)
		{
			for(j=k2;j<=m;j++)
			{
				x=i-k1;
				y=j-k2;
				ans=max(ans,a[i][j]-a[x][j]-a[i][y]+a[x][y]);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}