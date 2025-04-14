#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e3+10;
char s[MAX];
int dp[MAX][6],res[MAX][6][6];
int main()
{
	int T,n,m,i,j,k,x,y,id[128],ans,now,val;
	memset(id,0,sizeof id);
	id['n']=1;
	id['a']=2;
	id['r']=3;
	id['e']=4;
	id['k']=5;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++) memset(res[i],-0x3f,sizeof res[i]);
		for(i=1;i<=n;i++)
		{
			scanf("%s",s+1);
			for(k=1;k<=5;k++)
			{
				now=k;
				val=0;
				for(j=1;j<=m;j++)
				{
					if(id[s[j]]==now)
					{
						val++;
						now++;
						if(now==6) now=1;
					}
					else
					{
						if(id[s[j]]) val--;
					}
				}
				res[i][k][now]=val;
			}
		}
		
		for(i=0;i<=n;i++) memset(dp[i],-0x3f,sizeof dp[i]);
		dp[0][1]=0;
		for(i=1;i<=n;i++)
		{
			for(x=1;x<=5;x++) dp[i][x]=dp[i-1][x];
			for(x=1;x<=5;x++)
			{
				for(y=1;y<=5;y++)
				{
					dp[i][y]=max(dp[i][y],dp[i-1][x]+res[i][x][y]);
				}
			}
		}
		ans=0;
		for(x=1;x<=5;x++) ans=max(ans,dp[n][x]-2*(x-1));
		printf("%d\n",ans);
	}
	return 0;
}
/*
1
2 3
nar
ekn
*/
