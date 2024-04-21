#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e4+10;
int dp[2][105][MAX]; // 1..i  cnt(0)=j  cnt(01)-cnt(10)=k
char s[105];
const int delta=1e4;
int main()
{
	int n,i,j,k,f,ans,cnt[2];
	scanf("%s",s+1);
	n=strlen(s+1);
	cnt[0]=cnt[1]=0;
	f=0;
	memset(dp[f],0x3f,sizeof dp[f]);
	dp[0][0][delta]=0;
	for(i=1;i<=n;i++)
	{
		f^=1;
		memset(dp[f],0x3f,sizeof dp[f]);
		for(j=0;j<=i;j++)
		{
			for(k=-n*n+delta;k<=n*n+delta;k++)
			{
				if(j>0 && k-(i-j)>=0)
				{
					dp[f][j][k]=min(dp[f][j][k],dp[f^1][j-1][k-(i-j)]+(s[i]!='0'));
				}
				if(k+j<=n*n+delta)
				{
					dp[f][j][k]=min(dp[f][j][k],dp[f^1][j][k+j]+(s[i]!='1'));
				}
	//			printf("%d %d %d %d\n",i,j,k,dp[f][j][k]);
			}
		}
		cnt[s[i]-'0']++;
	}
	printf("%d\n",dp[f][cnt[0]][delta]/2);
	return 0;
}
