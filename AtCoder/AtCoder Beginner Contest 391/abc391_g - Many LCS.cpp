#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
const int MAX=(1<<10)+5;
int g[MAX][26],dp[105][MAX];
char ss[12];
int gao(int n,int s,int ch)
{
	int i,res,pre[12],now[12];
	pre[0]=0;
	for(i=0;i<n;i++) pre[i+1]=pre[i]+((s>>i)&1);
	now[0]=0;
	for(i=1;i<=n;i++)
	{
		now[i]=now[i-1];
		if(ss[i]-'a'==ch) now[i]=max(now[i],pre[i-1]+1);
		now[i]=max(now[i],pre[i]);
	}
	res=0;
	for(i=0;i<n;i++) res+=(now[i+1]-now[i])*(1<<i);
	return res;
}
int main()
{
	int n,m,i,j,k,bs,ans[12];
	scanf("%d%d",&n,&m);
	scanf("%s",ss+1);
	for(i=0;i<1<<n;i++)
	{
		for(j=0;j<26;j++)
		{
			g[i][j]=gao(n,i,j);
		}
	}
	memset(dp,0,sizeof dp);
	dp[0][0]=1;
	for(i=1;i<=m;i++)
	{
		for(j=0;j<1<<n;j++)
		{
			for(k=0;k<26;k++)
			{
				dp[i][g[j][k]]=(dp[i][g[j][k]]+dp[i-1][j])%mod;
			}
		}
	}
	memset(ans,0,sizeof ans);
	for(i=0;i<1<<n;i++)
	{
		bs=__builtin_popcount(i);
		ans[bs]=(ans[bs]+dp[m][i])%mod;
	}
	for(i=0;i<=n;i++) printf("%d%c",ans[i]," \n"[i==n]);
	return 0;
}

