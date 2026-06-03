#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e4+10;
int v[MAX],dp[MAX][2][2];
int main()
{
	int T,n,i,x,a,b,c,now,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&v[i]);
		scanf("%d",&x);
		for(i=1;i<=n;i++) v[i]-=x;
		memset(dp[0],-0x3f,sizeof dp[0]);
		memset(dp[1],-0x3f,sizeof dp[1]);
		dp[1][0][1]=1;
		dp[1][0][0]=0;
		v[0]=0;
		for(i=2;i<=n;i++)
		{
			memset(dp[i],-0x3f,sizeof dp[i]);
			for(a=0;a<=1;a++)
			{
				for(b=0;b<=1;b++)
				{
					for(c=0;c<=1;c++)
					{
						now=0;
						if(!c)
						{
							dp[i][b][c]=max(dp[i][b][c],dp[i-1][a][b]);
							continue;
						}
						now+=v[i];
						if(!b)
						{
							dp[i][b][c]=max(dp[i][b][c],dp[i-1][a][b]+1);
							continue;
						}
						now+=v[i-1];
						if(now<0) break;
						if(!a) dp[i][b][c]=max(dp[i][b][c],dp[i-1][a][b]+1);
						now+=v[i-2];
						if(now<0) break;
						dp[i][b][c]=max(dp[i][b][c],dp[i-1][a][b]+1);
					}
				}
			}
		}
		ans=0;
		for(a=0;a<=1;a++)
		{
			for(b=0;b<=1;b++)
			{
				ans=max(ans,dp[n][a][b]);
//				printf("%d %d %d\n",a,b,dp[n][a][b]);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
看到任意子区间都满足条件，我们需要去找最短能满足条件就能推出任意能满足条件的子区间。
两个限制说人话就是，选出的所有连续子区间需要满足第二个限制。
把 ai-x，做前缀和，第2个限制等价于，sum[r]>=sum[l-1]。
发现只要所有长度2和3的子序列满足即可。
然后随便dp一下，看看上一个和上上一个选不选。
*/
