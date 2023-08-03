#include<bits/stdc++.h>
using namespace std;
int bit[5010][5010];
const int MAX=5001;
int main()
{
	int n,r,i,j,x,y,v,ans;
	memset(bit,0,sizeof bit);
	scanf("%d%d",&n,&r);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d",&x,&y,&v);
		bit[x+1][y+1]=v;
	}
	for(i=1;i<=MAX;i++)
	{
		for(j=1;j<=MAX;j++)
		{
			bit[i][j]+=bit[i-1][j]+
					   bit[i][j-1]-
					   bit[i-1][j-1];
		}
	}
	ans=0;
	for(i=r;i<=MAX;i++)
	{
		for(j=r;j<=MAX;j++)
		{
			ans=max(ans,bit[i][j]-
						bit[i][j-r]-
						bit[i-r][j]+
						bit[i-r][j-r]);
		}
	}
	printf("%d\n",ans);
	return 0;
}
