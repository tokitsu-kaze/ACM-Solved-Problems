#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=750+10;
int dp[MAX][MAX],sum[MAX][MAX],a[MAX][MAX];
int main()
{
	int n,i,j,k,len,l,r,res;
	scanf("%d",&n);
	res=0;
	for(j=2;j<=n;j++)
	{
		for(i=1;i<j;i++)
		{
			scanf("%d",&a[i][j]);
			if(a[i][j]<0) res+=-a[i][j];
		}
	}
	for(i=1;i<=n;i++)
	{
		sum[i][i]=0;
		dp[i][i]=0;
		for(j=i+1;j<=n;j++)
		{
			sum[i][j]=sum[i][j-1];
			if(a[i][j]<0) sum[i][j]+=a[i][j];
			dp[i][j]=INF;
		}
	}
	for(len=2;len<=n;len++)
	{
		for(l=1;l+len-1<=n;l++)
		{
			r=l+len-1;
			for(k=l;k<r;k++)
			{
				dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r]+
							 sum[l][r]-sum[l][k+1]+a[l][k+1]);
			}
		}
	}
	printf("%d\n",dp[1][n]+res);
	return 0;
}
/*
先把删边转成加边。
感觉有点套路。考虑对dfs序做区间dp。
dp[l][r]表示 l 为根子树能搞出dfs序 l..r 的答案。
转移枚举中断点 k，将 [l,k] 和 [k+1,r] 合并。
这里我们只考虑将 k+1 连到 l 上，连到别的节点上其实在别的情况就考虑过了。
那这样的话就好办了，连一条 (l,k+1) 的边。
然后发现还可以加 (l,k+1),(l,k+2),...,(l,r) 这些返祖边。
前缀和维护一下转移即可。
*/
