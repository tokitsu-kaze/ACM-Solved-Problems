#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=(1<<7)+10;
char mp[11][11];
int dp[11][MAX],n,m;
int cal(int x,int s)
{
	int i,res;
	res=0;
	for(i=0;i<m;i++)
	{
		if(mp[x][i]=='#')
		{
			if(!((s>>i)&1)) res++;
		}
		else
		{
			if((s>>i)&1) return INF;
		}
	}
	return res;
}
int ck(int s,int t)
{
	int i;
	for(i=0;i<m-1;i++)
	{
		if(((s>>i)&3)==3 && ((t>>i)&3)==3) return 0;
	}
	return 1;
}
int main()
{
	int T,i,j,k,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++) scanf("%s",mp[i]);
		memset(dp,0x3f,sizeof dp);
		for(j=0;j<(1<<m);j++) dp[0][j]=cal(0,j);
		for(i=1;i<n;i++)
		{
			for(j=0;j<(1<<m);j++)
			{
				for(k=0;k<(1<<m);k++)
				{
					if(!ck(j,k)) continue;
					dp[i][j]=min(dp[i][j],dp[i-1][k]+cal(i,j));
				}
			}
		}
		ans=INF;
		for(j=0;j<(1<<m);j++) ans=min(ans,dp[n-1][j]);
		printf("%d\n",ans);
	}
	return 0;
}

