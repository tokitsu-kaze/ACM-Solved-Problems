#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=8e5+10;
const int M=(1<<20)+10;
const int D=4e5+1;
int dp[M],sum[M],v[21][MAX],lstv[21][MAX],bit[21],mn[21];
char ss[MAX];
int main()
{
	int n,i,j,s,now,len,ans;
	scanf("%d",&n);
	memset(sum,0,sizeof sum);
	for(i=0;i<n;i++)
	{
		scanf("%s",ss);
		len=strlen(ss);
		now=0;
		memset(v[i],0,sizeof v[i]);
		memset(lstv[i],-0x3f,sizeof lstv[i]);
		mn[i]=INF;
		for(j=0;j<len;j++)
		{
			if(ss[j]=='(') now++;
			else now--;
			mn[i]=min(mn[i],now);
			v[i][now+D]++;
			if(v[i][now+D]==1 && lstv[i][now+D]<0) lstv[i][now+D]=v[i][now+1+D];
		}
		bit[i]=now;
	}
	memset(dp,-0x3f,sizeof dp);
	dp[0]=0;
	sum[0]=0;
	ans=0;
	for(s=0;s<(1<<n);s++)
	{
		for(i=0;i<n;i++)
		{
			if((s>>i)&1) continue;
			if(sum[s]+mn[i]<0) ans=max(ans,dp[s]+lstv[i][-sum[s]-1+D]);
			else dp[s|(1<<i)]=max(dp[s|(1<<i)],dp[s]+v[i][-sum[s]+D]);
			sum[s|(1<<i)]=sum[s]+bit[i];
		}
	}
	for(s=0;s<(1<<n);s++) ans=max(ans,dp[s]);
	printf("%d\n",ans);
	return 0;
}
/*
显然状压dp。考虑两个括号串合并如何计算贡献。
由于求的是前缀的数量，当某个点<0时，后面的全部不合法。
于是首先考虑不合法的情况怎么判断。发现可以维护前面的sum+当前串的min。
然后发现合法情况的贡献其实就是这个串中有多少值=-sum，
这玩意可以预处理出n个桶，于是就能转移了。
但不合法的点之前可能还有一些贡献，再存一下第一次出现-sum时，-sum-1的数量。
遇到不合法时直接取答案，不更新dp。
感觉还是挺好想的。
*/
