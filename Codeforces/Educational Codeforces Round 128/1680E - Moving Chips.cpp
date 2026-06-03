#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
char s[2][MAX];
int pre[MAX][2],suf[MAX][2];
int main()
{
	int T,n,i,ans,f;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s[0]+1);
		scanf("%s",s[1]+1);
		s[0][0]=s[0][n+1]=s[1][0]=s[1][n+1]='.';
		pre[0][0]=pre[0][1]=0;
		for(i=1;i<=n;i++)
		{
			pre[i][0]=pre[i][1]=INF;
			f=0;
			if(pre[i-1][0] || s[0][i-1]=='*')
			{
				pre[i][0]=min(pre[i][0],pre[i-1][0]+1+(s[1][i]=='*'));
				pre[i][1]=min(pre[i][1],pre[i-1][0]+2);
				f=1;
			}
			if(pre[i-1][1] || s[1][i-1]=='*')
			{
				pre[i][0]=min(pre[i][0],pre[i-1][1]+2);
				pre[i][1]=min(pre[i][1],pre[i-1][1]+1+(s[0][i]=='*'));
				f=1;
			}
			if(!f)
			{
				pre[i][0]=min(pre[i][0],0+(s[1][i]=='*'));
				pre[i][1]=min(pre[i][1],0+(s[0][i]=='*'));
			}
//			printf("%d %d %d\n",i,pre[i][0],pre[i][1]);
		}
		suf[n+1][0]=suf[n+1][1]=0;
		for(i=n;i;i--)
		{
			suf[i][0]=suf[i][1]=INF;
			f=0;
			if(suf[i+1][0] || s[0][i+1]=='*')
			{
				suf[i][0]=min(suf[i][0],suf[i+1][0]+1+(s[1][i]=='*'));
				suf[i][1]=min(suf[i][1],suf[i+1][0]+2);
				f=1;
			}
			if(suf[i+1][1] || s[1][i+1]=='*')
			{
				suf[i][0]=min(suf[i][0],suf[i+1][1]+2);
				suf[i][1]=min(suf[i][1],suf[i+1][1]+1+(s[0][i]=='*'));
				f=1;
			}
			if(!f)
			{
				suf[i][0]=min(suf[i][0],0+(s[1][i]=='*'));
				suf[i][1]=min(suf[i][1],0+(s[0][i]=='*'));
			}
//			printf("%d %d %d\n",i,suf[i][0],suf[i][1]);
		}
		ans=INF;
		for(i=1;i<=n;i++)
		{
			f=0;
			if(suf[i+1][0] || s[0][i+1]=='*')
			{
				ans=min(ans,pre[i][0]+suf[i+1][0]+1);
				ans=min(ans,pre[i][1]+suf[i+1][0]+2);
				f=1;
			}
			if(suf[i+1][1] || s[1][i+1]=='*')
			{
				ans=min(ans,pre[i][0]+suf[i+1][1]+2);
				ans=min(ans,pre[i][1]+suf[i+1][1]+1);
				f=1;
			}
			if(!f)
			{
				ans=min(ans,pre[i][0]);
				ans=min(ans,pre[i][1]);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
闭着眼睛dp，dp[i][0/1]表示1-i列的*都移动到第i列的上/下面。
正着做一遍，倒着做一遍，然后枚举最终*在哪。
*/
