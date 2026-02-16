#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=360+10;
int dp[MAX][MAX],pos[MAX];
int main()
{
	int T,n,k,i,j,x,y,ans,mx;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		memset(pos,0x3f,sizeof pos);
		mx=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			if(x>mx) pos[x]=i;
			mx=max(mx,x);
		}
		for(i=k;~i;i--) pos[i]=min(pos[i+1],pos[i]);
		for(i=0;i<=k;i++)
		{
			for(j=0;j<=k;j++) dp[i][j]=-INF;
		}
		dp[0][0]=0;
		for(i=0;i<=k;i++)
		{
			for(y=0;y<=mx;y++)
			{
				for(x=0;x<y && x+y<=i;x++)
				{
					if(dp[i-y][x]<0) continue;
					dp[i][y]=max(dp[i][y],dp[i-y][x]+(y-x)*(n-pos[y]+1));
				}
			}
		}
		ans=0;
		for(i=0;i<=k;i++)
		{
			for(j=0;j<=k;j++) ans=max(ans,dp[i][j]);
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
dp[i][j] 总共选了 i，上一个选 j 
发现当ai更新前缀max时这个ai才是有用的， 
即使如此，枚举每个ai的复杂度是 k^3*sqrt(k)的。 
此时发现转移中只是需要当前ai的位置， 
考虑记录下有用的ai的位置，就不用枚举ai了
复杂度降为 k^3 
*/
