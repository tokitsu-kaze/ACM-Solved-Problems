#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
int a[MAX];
ll dp[2][4][4][4];
int main()
{
	int n,i,f,x,y,z,v,cnt0;
	ll ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	f=0;
	memset(dp[f],0,sizeof dp[f]);
	dp[f][0][0][0]=1;
	ans=cnt0=0;
	for(i=1;i<=n;i++)
	{
		if(a[i]==0)
		{
			ans+=1LL*i*(n-i+1);
			cnt0++;
		}
		else
		{
			f^=1;
			memset(dp[f],0,sizeof dp[f]);
			dp[f][a[i]][0][0]=cnt0+1;
			for(x=1;x<=3;x++)
			{
				for(y=0;y<=3;y++)
				{
					for(z=0;z<=3;z++)
					{
						if(y==0 && z!=0) continue;
						if(x&a[i]) dp[f][a[i]][y][z]+=dp[!f][x][y][z];
						else if(y==0 || (y&a[i])) dp[f][x][a[i]][z]+=dp[!f][x][y][z];
						else if(z==0 || (z&a[i])) dp[f][x][y][a[i]]+=dp[!f][x][y][z];
					}
				}
			}
			cnt0=0;
		}
		for(x=0;x<=3;x++)
		{
			for(y=0;y<=3;y++)
			{
				for(z=0;z<=3;z++)
				{
					v=min(x,1)+min(y,1)+min(z,1);
					ans+=dp[f][x][y][z]*v;
//					printf("%d %d %d %d %lld\n",i,x,y,z,dp[f][x][y][z]);
				}
			}
		}
//		printf("%d %lld\n",i,ans);
	}
	printf("%lld\n",ans);
	return 0;
}
/*
观察到去掉 0 后最多只有 3 个序列。
dp[i][x][y][z] 表示以 ai 结尾 3个子序列的结尾分别是 x,y,z 时的方案数。
有 0 时需要注意记录答案与新增 ai 时会增加 cnt0+1个序列。
*/
