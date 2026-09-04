#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=100+2;
int cola[MAX],colb[MAX];
int prea[MAX][MAX],preb[MAX][MAX];
ll cnta[MAX],cntb[MAX],dp[MAX][MAX];
int main()
{
	int T,cas,n,m,i,j,y,tot,pa,pb;
	ll sa,sb,x;
	scanf("%d",&T);
	for(cas=1;cas<=T;cas++)
	{
		scanf("%d%d",&n,&m);
		tot=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld%d",&x,&y);
			if(tot && cola[tot]==y) cnta[tot]+=x;
			else
			{
				tot++;
				cnta[tot]=x;
				cola[tot]=y;
			}
		}
		n=tot;
		memset(prea[0],0,sizeof prea[0]);
		cola[0]=0;
		for(i=1;i<=n;i++)
		{
			memcpy(prea[i],prea[i-1],sizeof prea[i-1]);
			prea[i][cola[i-1]]=i-1;
		}
		
		tot=0;
		for(i=1;i<=m;i++)
		{
			scanf("%lld%d",&x,&y);
			if(tot && colb[tot]==y) cntb[tot]+=x;
			else
			{
				tot++;
				cntb[tot]=x;
				colb[tot]=y;
			}
		}
		m=tot;
		memset(preb[0],0,sizeof preb[0]);
		colb[0]=0;
		for(i=1;i<=m;i++)
		{
			memcpy(preb[i],preb[i-1],sizeof preb[i-1]);
			preb[i][colb[i-1]]=i-1;
		}
		
		memset(dp[0],0,sizeof dp[0]);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
				if(cola[i]!=colb[j]) continue;
				sa=0;
				for(pa=i;pa>=1;pa=prea[pa][cola[i]])
				{
					sa+=cnta[pa];
					sb=0;
					for(pb=j;pb>=1;pb=preb[pb][colb[j]])
					{
//						printf("%d %d %d %d\n",i,j,pa,pb);
						sb+=cntb[pb];
						dp[i][j]=max(dp[i][j],dp[pa-1][pb-1]+min(sa,sb));
					}
				}
			}
		}
		printf("Case #%d: %lld\n",cas,dp[n][m]);
	}
	return 0;
}
/*
首先 dp[i][j] 表示处理完1-i的盒子和1-j的玩具，但转移时我不知道上一次匹配剩下多少东西，这该怎么转移呢？ 

如果有剩下，那中间别的类型肯定是要丢掉的。
考虑匹配的起点，从前面某个相同类型的节点为起点，累加到当前节点，然后再去匹配。
复杂度 O(T n^2 m^2)。
此时可以做一些简单的优化：
1.相邻的相同类型合并，变成相邻不相同的状态。
2.转移时每次往前跳相同类型。
这样复杂度变成 O(T (n/2)^2 (m/2)^2 )。
然后两个双重循环还各带一个 /2 常数。
最后大概是 O(T(n^2 m^2)/64)，1.5e8。
*/
