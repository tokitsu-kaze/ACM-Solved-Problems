#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
ll x[MAX],y[MAX],c[MAX],dp[2][16];
int main()
{
	int T,n,i,j,k,f;
	ll now;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%lld",&x[i]);
		for(i=1;i<=n;i++) scanf("%lld",&y[i]);
		for(i=1;i<=n;i++) scanf("%lld",&c[i]);
		f=0;
		memset(dp[f],-0x3f,sizeof dp[f]);
		dp[f][0]=0;
		for(i=1;i<=n;i++)
		{
			f^=1;
			memset(dp[f],-0x3f,sizeof dp[f]);
			for(j=0;j<16;j++)
			{
				for(k=0;k<16;k++)
				{
					if(j&k) continue;
					now=0;
					if(k==0) now=c[i];
					if(k&1) now-=2*x[i];
					if(k&2) now+=2*x[i];
					if(k&4) now-=2*y[i];
					if(k&8) now+=2*y[i];
					dp[f][j|k]=max(dp[f][j|k],dp[!f][j]+now);
				}
			}
		}
		printf("%lld\n",dp[f][15]);
	}
	return 0;
}
/*
猜想保留2个点当对角线是最优的，看样例发现并不是，可以4个点都在边界上。
那么保留的点的数量肯定<=4。
所以每个点要么删除，要么贡献一些边界。
一个点可以贡献多个边界，但多个点不能贡献同一个边界。
dp一下。
*/
