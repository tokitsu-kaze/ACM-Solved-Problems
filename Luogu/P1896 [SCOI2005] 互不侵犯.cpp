#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[2][(1<<9)+5][2][82];
int main()
{
	int n,k,i,j,l,f,up,lf,s,s0,s1,x;
	ll ans;
	scanf("%d%d",&n,&k);
	f=0;
	memset(dp[f],0,sizeof dp[f]);
	dp[f][0][0][0]=1;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			f^=1;
			memset(dp[f],0,sizeof dp[f]);
			for(s=0;s<(1<<n);s++)
			{
				if(j==0) lf=0;
				else lf=(s>>(j-1))&1;
				up=(s>>j)&3;
				if(!i&&up) continue;
				s0=(((1<<n)-1)^(1<<j))&s;
				s1=s|(1<<j);
				x=(s>>j)&1;
				for(l=0;l<=k;l++)
				{
					dp[f][s0][x][l]+=dp[f^1][s][0][l]+dp[f^1][s][1][l];
					if(!lf&&!up&&l>0)
					{
						dp[f][s1][x][l]+=dp[f^1][s][0][l-1];
						if(j==0) dp[f][s1][x][l]+=dp[f^1][s][1][l-1];
					}
				}
			}
		}
	}
	ans=0;
	for(s=0;s<(1<<n);s++) ans+=dp[f][s][0][k]+dp[f][s][1][k];
	printf("%lld\n",ans);
	return 0;
}

