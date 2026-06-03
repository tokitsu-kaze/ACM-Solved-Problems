#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3000+10;
int dp[MAX][MAX];
pair<int,int> pre[MAX][MAX];
char s[MAX],t[MAX];
int main()
{
	int n,m,i,j,x,y,px,py;
	scanf("%s",s+1);
	scanf("%s",t+1);
	n=strlen(s+1);
	m=strlen(t+1);
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
		{
			dp[i][j]=0;
			pre[i][j]={-1,-1};
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			dp[i][j]=dp[i-1][j];
			pre[i][j]={i-1,j};
			if(dp[i][j-1]>dp[i][j])
			{
				pre[i][j]={i,j-1};
				dp[i][j]=dp[i][j-1];
			}
			if(s[i]==t[j])
			{
				if(dp[i-1][j-1]+1>dp[i][j])
				{
					pre[i][j]={i-1,j-1};
					dp[i][j]=dp[i-1][j-1]+1;
				}
			}
		}
	}
//	printf("%d\n",dp[n][m]);
	string res;
	x=n;
	y=m;
	while(x!=-1)
	{
		px=pre[x][y].first;
		py=pre[x][y].second;
		if(dp[x][y]==dp[px][py]+1) res+=s[x];
		x=px;
		y=py;
	}
	reverse(res.begin(),res.end());
	cout<<res<<"\n";
	return 0;
}
