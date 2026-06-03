#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=500+10;
int mp[MAX][MAX];
int main()
{
	int T,n,i,j;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=2*n;i++)
		{
			for(j=1;j<=2*n;j++) scanf("%d",&mp[i][j]);
		}
		if(n==1)
		{
			ans=mp[2][2]+min(mp[2][1],mp[1][2]);
			printf("%lld\n",ans);
			continue;
		}
		ans=0;
		for(i=n+1;i<=2*n;i++)
		{
			for(j=n+1;j<=2*n;j++) ans+=mp[i][j];
		}
		ans+=min({
			mp[n+1][1],
			mp[2*n][1],
			mp[n+1][n],
			mp[2*n][n],
			mp[1][n+1],
			mp[1][2*n],
			mp[n][n+1],
			mp[n][2*n]
		});
		printf("%lld\n",ans);
	}
	return 0;
}
/*
反正右下角肯定得全加上。
先观察第3,4组样例怎么过，尝试手玩出一种移动方案。
然后发现能从右上和左下n*n中的4个角走。
把这总共8个位置的数取min计入答案。
*/
