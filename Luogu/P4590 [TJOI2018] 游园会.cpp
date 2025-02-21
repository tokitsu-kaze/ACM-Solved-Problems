#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int MAX=(1<<15)+5;
int nex[MAX][26],dp[2][MAX][3][3];
char ss[22];
int get_id(char c)
{
	if(c=='N') return 0;
	else if(c=='O') return 1;
	else if(c=='I') return 2;
	assert(0);
	return -1;
}
int gao(int n,int s,int ch)
{
	int i,res,pre[22],now[22];
	pre[0]=0;
	for(i=0;i<n;i++) pre[i+1]=pre[i]+((s>>i)&1);
	now[0]=0;
	for(i=1;i<=n;i++)
	{
		now[i]=now[i-1];
		if(get_id(ss[i])==ch) now[i]=max(now[i],pre[i-1]+1);
		now[i]=max(now[i],pre[i]);
	}
	res=0;
	for(i=0;i<n;i++) res+=(now[i+1]-now[i])*(1<<i);
	return res;
}
int main()
{
	int T,n,m,i,j,k,bs,ans[22],f,x,y;
	scanf("%d%d",&m,&n);
	scanf("%s",ss+1);
	for(i=0;i<1<<n;i++)
	{
		for(j=0;j<3;j++)
		{
			nex[i][j]=gao(n,i,j);
		}
	}
	f=0;
	memset(dp[f],0,sizeof dp[f]);
	for(x=0;x<3;x++)
	{
		for(y=0;y<3;y++)
		{
			dp[f][nex[nex[0][x]][y]][x][y]=1;
		}
	}
	for(i=3;i<=m;i++)
	{
		f^=1;
		memset(dp[f],0,sizeof dp[f]);
		for(j=0;j<1<<n;j++)
		{
			for(k=0;k<3;k++)
			{
				for(x=0;x<3;x++)
				{
					for(y=0;y<3;y++)
					{
						if(x==0 && y==1 && k==2) continue;
						dp[f][nex[j][k]][y][k]=(dp[f][nex[j][k]][y][k]+dp[!f][j][x][y])%mod;
					}
				}
			}
		}
	}
	memset(ans,0,sizeof ans);
	for(i=0;i<1<<n;i++)
	{
		bs=__builtin_popcount(i);
		for(x=0;x<3;x++)
		{
			for(y=0;y<3;y++)
			{
				ans[bs]=(ans[bs]+dp[f][i][x][y])%mod;
			}
		}
	}
	for(i=0;i<=n;i++) printf("%d\n",ans[i]);
	return 0;
}

