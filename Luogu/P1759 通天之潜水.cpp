#include <bits/stdc++.h>
using namespace std;
int a[105],b[105],c[105];
int dp[105][205][205];
int last[105][205][205];//前i个物品，背包重量分别为j,k时的最后一个物品编号 
int main()
{
	int i,j,k,m,v,n,ans,pos,x,y,z;
	scanf("%d%d%d",&m,&v,&n);
	memset(dp,0,sizeof dp);
	memset(last,-1,sizeof last);
	for(i=1;i<=n;i++) scanf("%d%d%d",&a[i],&b[i],&c[i]);
	for(i=n;i;i--)
	{
		for(j=m;j>=0;j--)
		{
			for(k=v;k>=0;k--)
			{
				// 不选第i个物品 
				dp[i][j][k]=dp[i+1][j][k];
				last[i][j][k]=last[i+1][j][k];
				
				if(j-a[i]<0 || k-b[i]<0) continue;
				
				//选第i个比不选更优 
				if(dp[i+1][j-a[i]][k-b[i]]+c[i]>=dp[i][j][k])
				{
					dp[i][j][k]=dp[i+1][j-a[i]][k-b[i]]+c[i];
					last[i][j][k]=i;
				}
			}
		}
	}
	ans=dp[1][m][v];
	x=1;
	y=m;
	z=v;
	vector<int> res;
	while(1)
	{
		pos=last[x][y][z];
		if(pos<=0) break;
		res.push_back(pos);
		x=pos+1;
		y-=a[pos];
		z-=b[pos];
	}
	
	printf("%d\n",ans);
	for(i=0;i<res.size();i++) printf("%d%c",res[i]," \n"[i==res.size()-1]);
	return 0;
}
