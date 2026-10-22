#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int dp[MAX][5],a[MAX];
int main()
{
	int T,n,i,x,y,t;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		memset(dp[n+1],0,sizeof dp[n+1]);
		dp[n+1][0]=1;
		for(i=n;i;i--)
		{
			memset(dp[i],0,sizeof dp[i]);
			for(x=0;x<=2;x++)
			{
				for(y=0;y<=2;y++)
				{
					t=a[i]-(x+3*y);
					if(t>=0)
					{
						dp[i][t%3]|=dp[i+1][x+y];
						if(t%3<=1 && t>=t%3+3) dp[i][t%3+3]|=dp[i+1][x+y];
					}
				}
			}
		}
		if(dp[1][0]) puts("YES");
		else puts("NO");
	}
	return 0;
}
/*
发现 1 和 3 操作最多做 2 次，做 3 次的话，可以转化成做 2 操作。
由于 a[i+1] 只能 -1 或者 -3，考虑倒着做。
dp[i][j] 表示 [i+1..n] 都变为 0，a[i]=j 是否可达。
转移分别枚举 1 和 3 操作做几次，要注意可能会都做，而不是只做 1 或者只做 3。

2
5 3

*/
